#include <iostream>
using namespace std;

template <typename T1, typename T2>
void Print(T1 a, T2 b)
{
    cout << a << ", " << b << endl;
}
void main( )
{
    Print(10, 1.5); // ����, �Ǽ� ���
    Print("Hello!", 100); // ���ڿ�, ���� ���
    Print(1.5, "Hello!"); // �Ǽ�, ���ڿ� ���
}