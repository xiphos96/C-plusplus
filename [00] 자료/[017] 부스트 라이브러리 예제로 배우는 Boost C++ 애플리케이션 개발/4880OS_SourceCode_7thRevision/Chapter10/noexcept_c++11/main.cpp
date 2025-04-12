#include <boost/config.hpp>

class move_nothrow {
    // 클래스 멤버는 여기에
    // ...
public:
    move_nothrow() BOOST_NOEXCEPT {}
    move_nothrow(move_nothrow&&) BOOST_NOEXCEPT
        // : 멤버 초기화
        // ...
    {}

    move_nothrow& operator=(move_nothrow&&) BOOST_NOEXCEPT {
        // 구현
        // ...
        return *this;
    }

    move_nothrow(const move_nothrow&);
    move_nothrow& operator=(const move_nothrow&);
};


#include <vector>
int main() {

    std::vector<move_nothrow> v(10);
    v.push_back(move_nothrow());

}

// 헤더 파일에
int foo() BOOST_NOEXCEPT;


// 소스 파일에
int foo() BOOST_NOEXCEPT {
    return 0;
}
