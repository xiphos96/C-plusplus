#include <iostream>
using namespace std;

class Point
{
    int x;
    int y;
public:
    Point(int _x =0 , int _y =0 ):x(_x),y(_y) { }
    void Print( ) const { cout << x <<',' << y << endl; }
};
void main()
{
    Point *p1 = new Point(2,3); //�޸� �Ҵ�
    Point *p2 = new Point(5,5); //�޸� �Ҵ�

    p1->Print(); //p1�� ��� �Լ� ȣ��(���� ���)
    p2->Print(); //p2�� ��� �Լ� ȣ��(���� ���)

    delete p1; //�޸� ����
    delete p2; //�޸� ����
}
