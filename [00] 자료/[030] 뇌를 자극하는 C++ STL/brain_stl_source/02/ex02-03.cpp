#include <iostream>
using namespace std;

void Print( )
{
    cout <<"���� �Լ� Print()"<< endl;
}
class Point
{
public:
    void Print( )
    {
        cout <<"��� �Լ� Print()"<< endl;
    }
};
void main()
{
    Point pt;
    Point * p = &pt;

    Print(); // ù°, ���� �Լ� ȣ��
    pt.Print(); // ��°, ��ü�� ����Լ� ȣ��
    p->Print(); // ��°, �ּҷ� ����Լ� ȣ��

}