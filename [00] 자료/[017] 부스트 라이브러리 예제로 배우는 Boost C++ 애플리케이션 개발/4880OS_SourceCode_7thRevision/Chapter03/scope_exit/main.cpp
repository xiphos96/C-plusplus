#include <boost/scope_exit.hpp>
#include <cstdlib>
#include <cstdio>
#include <cassert>

int main() {
    std::FILE* f = std::fopen("example_file.txt", "w");
    assert(f);
    BOOST_SCOPE_EXIT(f) {
    // 영역 내에서 무슨 일이 일어나든
    // 이 코드는 실행되기 때문에 파일은 잘 닫힌다
        std::fclose(f);
    } BOOST_SCOPE_EXIT_END

    // 예외를 던지거나 반환하는 어떤 코드
    // ...
}

class theres_more_example {
public:
    void close(std::FILE*);

    void theres_more_example_func() {
        std::FILE* f = 0;
        BOOST_SCOPE_EXIT(f, this_) { // `this_` 객체 붙잡기
            this_->close(f);
        } BOOST_SCOPE_EXIT_END
    }
};
