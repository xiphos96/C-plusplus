#include <iostream>
using namespace std;

void Print(int n)
{
    cout <<"���� �Լ�: "<< n << endl;
}
namespace A
{
    void Print(int n)
    {
        cout <<"namespace A ���� �Լ�: "<< n << endl;
    }
}
class Point
{
public:
    static void Print(int n)
    {
        cout <<"Point Ŭ������ ���� ��� �Լ�: "<< n << endl;
    }
};
void main()
{
    void (*pf)(int );
  
    Print( 10 ); // 1. namespace ���� ���� �Լ� ȣ��
    A::Print( 10 ); // 2, namespace A�� ���� �Լ� ȣ��
    Point::Print( 10 ); // 3, Point Ŭ������ ���� ��� �Լ� ȣ��
    cout << endl;
        
    pf = Print;
    pf( 10 );  // 1. �Լ� �����ͷ� namespace ���� ���� �Լ� ȣ��
    pf = A::Print;
    pf( 10 );  // 2. �Լ� �����ͷ� namespace A�� ���� �Լ� ȣ��
    pf = Point::Print;
    pf( 10 );  // 3. �Լ� �����ͷ� Point Ŭ������ ���� ��� �Լ� ȣ��
}