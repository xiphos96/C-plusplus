#include <iostream>

using namespace std;

int main() 
{
    try
    {
        throw 20;
    }
    catch (int e)
    {
        cout << "���� �߻�. ���� �� " << e << '\n';
    }
    return 0;
}