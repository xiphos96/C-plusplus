#include <iostream>

using namespace std;

class MyException
{
    int myValue;
public:
    MyException(int value)
    {
        myValue = value;
    }
    void exceptionResult()
    {
        if (myValue < 10)
            cout << "10�̻��� ���� �Է��ϼ���" << endl;
        else if (myValue > 20)
            cout << "20������ ���� �Է��ϼ���" << endl;
        else if (myValue % 7 != 0)
            cout << "7�� ��� ���� �Է��ϼ���" << endl;
    }
};

int main()
{
    int value;
    try
    {
        cout << "10�� 20������ 7�� ����� �Է��ϼ���: ";
        cin >> value;

        if (value < 10 | value > 20 | value % 7 != 0)
            throw MyException(value);
            
        cout << "����!! 10�� 20������ 7�� ����� " << value << "�Դϴ�" << endl;
    }
    catch (MyException &e)
    {
        e.exceptionResult();
    }
    return 0;
}