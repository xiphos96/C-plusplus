#include <iostream>
#include <any>

int main() {
    std::any a = 123;
    std::cout << "a stores an integer: " << std::any_cast<int>(a) << std::endl;

    a = 456.789;
    std::cout << "a stores a double: " << std::any_cast<double>(a) << std::endl;

    a = true;
    std::cout << "a stores a boolean: " << std::any_cast<bool>(a) << std::endl;

    if (a.has_value())
    {
        std::cout << "a has a value." << std::endl;
    }

    return 0;
}