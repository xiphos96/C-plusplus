#include <boost/config.hpp>

class move_nothrow {
    // Ŭ���� ����� ���⿡
    // ...
public:
    move_nothrow() BOOST_NOEXCEPT {}
    move_nothrow(move_nothrow&&) BOOST_NOEXCEPT
        // : ��� �ʱ�ȭ
        // ...
    {}

    move_nothrow& operator=(move_nothrow&&) BOOST_NOEXCEPT {
        // ����
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

// ��� ���Ͽ�
int foo() BOOST_NOEXCEPT;


// �ҽ� ���Ͽ�
int foo() BOOST_NOEXCEPT {
    return 0;
}
