#include <iostream>
using namespace std;

struct FuncObject
{
public:
    void operator()( int arg ) const 
    {
        cout <<"���� : " << arg << endl;
    }
};
void Print1( int arg )
{
    cout <<"���� : " << arg << endl;
}
void main( )
{
    void (*Print2)(int) = Print1;
    FuncObject Print3;

    Print1(10); // ù°, �Լ� ȣ��
    Print2(10); // ��°, �Լ� ȣ�� 
    Print3(10); // ù°, �Լ� ȣ�� Print3.operator(10)�� ȣ��
}
