#include <boost/noncopyable.hpp>
#include <algorithm>
#include <iostream>
#include <string.h>
#include <assert.h>

class descriptor_owner: private boost::noncopyable {
    void* descriptor_;

public:
    descriptor_owner()
        : descriptor_(NULL)
    {}

    explicit descriptor_owner(const char* param)
        : descriptor_(strdup(param))
    {}

    void swap(descriptor_owner& desc) {
        std::swap(descriptor_, desc.descriptor_);
    }

    ~descriptor_owner() {
        free(descriptor_);
    }
};


//descriptor_owner construct_descriptor() {
//    return descriptor_owner("Construct using this string");
//}

void construct_descriptor1(descriptor_owner& ret) {
    descriptor_owner("Construct using this string").swap(ret);
}


#include <boost/config.hpp>

#if !defined(BOOST_NO_RVALUE_REFERENCES) && !defined(BOOST_NO_CXX11_RVALUE_REFERENCES)

class descriptor_owner1 {
    void* descriptor_;

public:
    descriptor_owner1()
        : descriptor_(NULL)
    {}

    explicit descriptor_owner1(const char* param)
        : descriptor_(strdup(param))
    {}

    descriptor_owner1(descriptor_owner1&& param)
        : descriptor_(param.descriptor_)
    {
        param.descriptor_ = NULL;
    }

    descriptor_owner1& operator=(descriptor_owner1&& param) {
        clear();
        std::swap(descriptor_, param.descriptor_);
        return *this;
    }

    void clear() {
        free(descriptor_);
        descriptor_ = NULL;
    }

    bool empty() const {
        return !descriptor_;
    }

    ~descriptor_owner1() {
        clear();
    }
};

// GCC은 아래 코드를 컴파일할 때 -std=c++0x 옵션을 주고 한다  -----_____-------
descriptor_owner1 construct_descriptor2() {
    return descriptor_owner1("Construct using this string");
}


void foo_rv() {
    std::cout << "C++11\n";
    descriptor_owner1 desc;
    desc = construct_descriptor2();
    assert(!desc.empty());
}
#else
void foo_rv() {std::cout << "no C++11\n";}
#endif

#include <boost/move/move.hpp>
#include <boost/container/vector.hpp>

class descriptor_owner_movable {
    void* descriptor_;

    BOOST_MOVABLE_BUT_NOT_COPYABLE(descriptor_owner_movable)
public:
    descriptor_owner_movable()
        : descriptor_(NULL)
    {}

    explicit descriptor_owner_movable(const char* param)
        : descriptor_(strdup(param))
    {}

    descriptor_owner_movable(BOOST_RV_REF(descriptor_owner_movable) param) BOOST_NOEXCEPT
        : descriptor_(param.descriptor_)
    {
        param.descriptor_ = NULL;
    }

    descriptor_owner_movable& operator=(BOOST_RV_REF(descriptor_owner_movable) param) BOOST_NOEXCEPT {
        clear();
        std::swap(descriptor_, param.descriptor_);
        return *this;
    }

    void clear() {
        free(descriptor_);
        descriptor_ = NULL;
    }

    bool empty() const {
        return !descriptor_;
    }

    ~descriptor_owner_movable() BOOST_NOEXCEPT {
        clear();
    }
};

descriptor_owner_movable construct_descriptor3() {
    return descriptor_owner_movable("Construct using this string");
}

// your_project/vector.hpp
// 카피라이트 등등을 여기에 쓴다

// 가드(guard)를 쓴다
#ifndef YOUR_PROJECT_VECTOR_HPP
#define YOUR_PROJECT_VECTOR_HPP

#include <boost/config.hpp>

// 이 매크로는 boost/config.hpp 헤더에 선언되어 있다
// 이동이 가능하며, 어떠한 부스트 라이브러리 버전에서도 쓸 수 있다
#if !defined(BOOST_NO_RVALUE_REFERENCES) && !defined(BOOST_NO_CXX11_RVALUE_REFERENCES)

// rvalue가 있다
#include <vector>
namespace your_project_namespace {
    using std::vector;
} // your_project_namespace

#else

// rvalue가 없다
#include <boost/container/vector.hpp>
namespace your_project_namespace {
    using boost::container::vector;
} // your_project_namespace

#endif // !defined(BOOST_NO_RVALUE_REFERENCES) && !defined(BOOST_NO_CXX11_RVALUE_REFERENCES)

#endif // YOUR_PROJECT_VECTOR_HPP








int main()
{
    foo_rv();

    // 다음 코드는 C++11과 C++03 컴파일러 모두에서 동작한다
    descriptor_owner_movable movable;
    movable = construct_descriptor3();

    boost::container::vector<descriptor_owner_movable> vec;
    vec.resize(10);
    vec.push_back(construct_descriptor3());

    vec.back() = boost::move(vec.front());


    your_project_namespace::vector<descriptor_owner_movable> v;
    v.resize(10);
    v.push_back(construct_descriptor3());

    v.back() = boost::move(v.front());

    return 0;
}

