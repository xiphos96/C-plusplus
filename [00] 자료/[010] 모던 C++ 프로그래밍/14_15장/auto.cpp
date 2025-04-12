#include <iostream>

using namespace std;

int main()
{
    auto text = "auto variable";    // char const *형 변수

    cout << typeid(text).name() << endl;

    auto integer = 10;              // int형 변수

    cout << typeid(integer).name() << endl;
    
    return 0;
}