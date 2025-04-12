#include <iostream>

using namespace std;

int main()
{
    try
    {
        throw "예외 잡아라!!!";
    }
    catch (int e)
    {
        cout << "예외 발생. 예외 값 " << e << '\n';
    }
    return 0;
}