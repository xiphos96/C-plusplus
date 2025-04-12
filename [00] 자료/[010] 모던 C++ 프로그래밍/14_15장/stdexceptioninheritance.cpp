#include <iostream>
#include <exception>

using namespace std;

class MyException : public exception
{
    int myValue;
public:
    MyException(int value)
    {
        myValue = value;
    }
    virtual const char * what() const throw()
    {
        if (myValue < 10)
            return "10�̻��� ���� �Է��ϼ���";
        else if (myValue > 20)
            return "20������ ���� �Է��ϼ���";
        else if (myValue % 7 != 0)
            return "7�� ��� ���� �Է��ϼ���";
        return "�߸��� ���� ����";
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
    catch (exception &e)
    {
        cout << e.what() << endl;
    }
    return 0;
}