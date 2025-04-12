#include <iostream>

using namespace std;

#define UNDERVALUEEXCEPTION -1
#define OVERVALUEEXCEPTION -2
#define NOTMULTIVALUEEXCEPTION -3

int main()
{
    int value;
    try
    {
        cout << "10�� 20������ 7�� ����� �Է��ϼ���: ";
        cin >> value;

        if (value < 10)
            throw UNDERVALUEEXCEPTION;
        else if (value > 20)
            throw OVERVALUEEXCEPTION;
        else if (value % 7 != 0)
            throw NOTMULTIVALUEEXCEPTION;
        else
            cout << "����!! 10�� 20������ 7�� ����� " << value << "�Դϴ�" << endl;
    }    
    catch (int e)
    {
        if (e == UNDERVALUEEXCEPTION)
            cout << "10�̻��� ���� �Է��ϼ���" << endl;
        else if (e == OVERVALUEEXCEPTION)
            cout << "20������ ���� �Է��ϼ���" << endl;
        else if (e == NOTMULTIVALUEEXCEPTION)
            cout << "7�� ��� ���� �Է��ϼ���" << endl;            
    }
    return 0;
}