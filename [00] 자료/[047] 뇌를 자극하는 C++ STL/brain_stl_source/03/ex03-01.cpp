#include <iostream>
using namespace std;
void Print( )
{
    cout << "���� �Լ�!" << endl;
}
struct Functor
{
    void operator( )( )
    {
        cout << "�Լ� ��ü!" << endl;
    }
};
void main( )
{
    Functor functor;

    Print();   // ���� �Լ� ȣ��
    functor(); // ��� �Լ� ȣ�� functor.operator()( )�� ����;
}