#include <iostream>
using namespace std;

bool Pred_less(int a, int b)
{
    return a < b;
}
struct Less
{
    bool operator()(int a, int b)
    {
        return a < b;
    }
};
void main( )
{
    Less l;

    cout << Pred_less(10, 20) << endl;
    cout << Pred_less(20, 10) << endl;
    cout << endl;
    cout << l(10, 20) << endl; // l ��ü�� �Ϲ��� �Լ� ȣ��
    cout << l(20, 10) << endl; // l ��ü�� �Ϲ��� �Լ� ȣ��   
    cout << Less()(10, 20) << endl; // �ӽð�ü�� �Ϲ��� �Լ� ȣ��   
    cout << Less()(20, 10) << endl; // �ӽð�ü�� �Ϲ��� �Լ� ȣ��   
    cout << endl;
    cout << l.operator()(10, 20) << endl; // ����� ȣ��
    cout << Less().operator()(10, 20) << endl; // ����� ȣ��
}