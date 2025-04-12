#include <iostream>
using namespace std;
class Point
{
    int x;
    int y;
public:
    explicit Point(int _x =0, int _y =0 ):x(_x),y(_y) { }
    void Print( ) const { cout << x <<',' << y << endl; }
    void PrintInt(int n) { cout << "�׽�Ʈ ���� : "<< n << endl; }
};
void main()
{
    Point pt(2,3);
    Point *p = &pt;

    void (Point::*pf1)() const; // ��� �Լ� ������ ����
    pf1 = &Point::Print;

    void (Point::*pf2)(int ) ; // ��� �Լ� ������ ����
    pf2 = &Point::PrintInt;

    pt.Print();         
    pt.PrintInt( 10 );
    cout << endl;

    (pt.*pf1)();  // ��ü�� ��� �Լ� �����͸� �̿��� ȣ��
    (pt.*pf2)(10);// ��ü�� ��� �Լ� �����͸� �̿��� ȣ��  
    cout << endl;

    (p->*pf1)();  // �ּҷ� ��� �Լ� �����͸� �̿��� ȣ��
    (p->*pf2)(10);// �ּҷ� ��� �Լ� �����͸� �̿��� ȣ��
}