#include <boost/scope_exit.hpp>
#include <cstdlib>
#include <cstdio>
#include <cassert>

int main() {
    std::FILE* f = std::fopen("example_file.txt", "w");
    assert(f);
    BOOST_SCOPE_EXIT(f) {
    // ���� ������ ���� ���� �Ͼ��
    // �� �ڵ�� ����Ǳ� ������ ������ �� ������
        std::fclose(f);
    } BOOST_SCOPE_EXIT_END

    // ���ܸ� �����ų� ��ȯ�ϴ� � �ڵ�
    // ...
}

class theres_more_example {
public:
    void close(std::FILE*);

    void theres_more_example_func() {
        std::FILE* f = 0;
        BOOST_SCOPE_EXIT(f, this_) { // `this_` ��ü �����
            this_->close(f);
        } BOOST_SCOPE_EXIT_END
    }
};
