#include <iostream>

using namespace std;

int main()
{
    int value;
    try
    {
        cout << "10 �̻��� �� �Է�" << endl;
        cin >> value;

        if (value < 10)
        {
            throw value;
        }        
    }
    catch (int e)
    {
        cout << "���� �߻�. �߸��� �Է� ��: " << e << '\n';
    }
    return 0;
}