#include <iostream>

using namespace std;

int main()
{
    try
    {
        throw "���� ��ƶ�!!!";
    }
    catch (int e)
    {
        cout << "���� �߻�. ���� �� " << e << '\n';
    }
    return 0;
}