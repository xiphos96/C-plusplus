#include <iostream>
using namespace std;

template <typename T>
void Print(T a, T b)
{
    cout << a << ", " << b << endl;
}
void main( )
{
    Print<int>(10, 20); // ���� ���
    Print<double>(0.123, 1.123); // �Ǽ� ���
    Print<const char*>("ABC", "abcde"); // ���ڿ� ���
}