class descriptor_owner {
    void* descriptor_;

public:
    explicit descriptor_owner(const char* params){ (void)params; }

    ~descriptor_owner() {
        // system_api_free_descriptor(descriptor_);
    }
};

void foo() {
    descriptor_owner d1("O_o");
    descriptor_owner d2("^_^");

    // d2가 가진 기술자(descriptor)가 올바르게 해지되지 않았다
    d2 = d1;

    // d2의 소멸자가 기술자를 해지한다
    // d1의 소멸자가 이미 해지된 기술자를 해지하려 한다
}

#include <boost/noncopyable.hpp>

class descriptor_owner_fixed : private boost::noncopyable {
    // ...
public:
    descriptor_owner_fixed(const char* params){ (void)params; }
};

void foo2() {
    descriptor_owner_fixed d1("O_o");
    descriptor_owner_fixed d2("^_^");

    // 컴파일 되지 않는다
    //d2 = d1;
    //descriptor_owner_fixed d3(d1);
}

struct noncopyable_or_not {
private:
    noncopyable_or_not(const noncopyable_or_not&);
    noncopyable_or_not& operator=(const noncopyable_or_not&);

public:
    noncopyable_or_not(){}
    noncopyable_or_not(noncopyable_or_not&){}
    noncopyable_or_not& operator=(noncopyable_or_not&){ return *this; }
};

struct noncopyable_or_not2 {
private:
    noncopyable_or_not2(noncopyable_or_not2&);
    noncopyable_or_not2& operator=(noncopyable_or_not2&);

public:
    noncopyable_or_not2(){}
    noncopyable_or_not2(const noncopyable_or_not2&){}
    noncopyable_or_not2& operator=(const noncopyable_or_not2&) { return *this; }
};

int main()
{
    foo();
    foo2();

    noncopyable_or_not non1;
    noncopyable_or_not non2 = non1;

    const noncopyable_or_not2 n1;
    noncopyable_or_not2 n2 = n1;

    // 사용하지 않은 변수에 대한 경고 메시지 억제
    (void)non2;
    (void) n2;

    return 0;
}

