#include <iostream>
#include <vector>
#include <algorithm>
#include <ranges>

int main()
{
    std::vector<int> numbers = { 3, 2, 5 ,1, 4 };

    std::ranges::sort(numbers);
    for (int n : numbers)
    {
        std::cout << n << ' ';
    }
    std::cout << std::endl;

    auto evenSquareNumbers =
        numbers | std::views::filter([](int n) { return n % 2 == 0; })
                     | std::views::transform([](int n) { return n * n; });

    for (int n : evenSquareNumbers)
    {
        std::cout << n << ' ';
    }

    return 0;
}