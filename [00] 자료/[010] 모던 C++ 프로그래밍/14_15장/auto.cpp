#include <iostream>

using namespace std;

int main()
{
    auto text = "auto variable";    // char const *�� ����

    cout << typeid(text).name() << endl;

    auto integer = 10;              // int�� ����

    cout << typeid(integer).name() << endl;
    
    return 0;
}