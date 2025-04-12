#include <iostream>
#include <vector>
#include <algorithm>

int main()
{
    std::vector<int> numbers = { 3, 2, 5 ,1, 4 };

    std::sort(numbers.begin(), numbers.end());
    for (int n : numbers)
    {
        std::cout << n << ' ';
    }
    std::cout << std::endl;

    std::vector<int> evenNumbers;
    std::copy_if(numbers.begin(), numbers.end(),
        std::back_inserter(evenNumbers), [](int n) { return n % 2 == 0; });

    std::vector<int> evenSquareNumbers;
    std::transform(evenNumbers.begin(), evenNumbers.end(),
        std::back_inserter(evenSquareNumbers), [](int n) { return n * n; });

    for (int n : evenSquareNumbers)
    {
        std::cout << n << ' ';
    }

    return 0;
}