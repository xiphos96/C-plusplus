#define MY_LIBRARY_COMPILATION
#include "my_library.hpp"

int MY_LIBRARY_API foo() {
    // ����
    // ...
    return 0;
}

int bar::meow() const {
    throw bar_exception();
}
