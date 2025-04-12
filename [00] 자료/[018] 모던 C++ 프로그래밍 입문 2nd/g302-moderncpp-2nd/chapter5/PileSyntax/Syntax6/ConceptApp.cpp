#include <iostream>
#include <concepts>

template <typename T>
concept MustBeIncrementable = requires(T x)
{
	x++;
};
template <typename T>
concept MustBeEvenOrOdd = requires(T x)
{
	x % 2;
};

template <MustBeIncrementable T>
void myfunction(T x)
{
	x += 1;
	std::cout << x << std::endl;
}

template <typename T>
requires MustBeIncrementable<T> && MustBeEvenOrOdd<T>
void yourfunction(T x)
{
	std::cout << "the parameter " << x
			<< " satisfies both condition." << std::endl;
}

int main()
{
	myfunction<char>(42);
	myfunction<int>(123);
	myfunction<double>(456.789);
//	myfunction<std::string>("eum");

	yourfunction<char>(42);
	yourfunction<int>(123);
//	yourfunction<double>(456.789);
//	yourfunction<std::string>("eum");

	return 0;
}