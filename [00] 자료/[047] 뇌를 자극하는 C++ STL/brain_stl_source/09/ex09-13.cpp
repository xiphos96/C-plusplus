#include <iostream>
#include <functional>
using namespace std;
void main()
{
    //less�� ù ���ڸ� 10���� ������ ���� ������ binder ����.
    binder1st< less<int> > binder = bind1st(less<int>(), 10 );

    // binder�� ù ��° ���ڸ� 10���� ������ less. 
    cout << binder(5) <<':'<< less<int>()(10, 5) << endl; // �� ������ �����մϴ�.
    cout << binder(10) <<':'<< less<int>()(10, 10) << endl;// �� ������ �����մϴ�.
    cout << binder(20) <<':'<< less<int>()(10, 20) << endl;// �� ������ �����մϴ�.
    cout << "=====���� ����=====" << endl;
    // �ӽ� ��ü ���
    cout << bind1st(less<int>(), 10 )(5) <<':'<< less<int>()(10, 5) << endl;
    cout << bind1st(less<int>(), 10 )(10) <<':'<< less<int>()(10, 10) << endl;
    cout << bind1st(less<int>(), 10 )(20) <<':'<< less<int>()(10, 20) << endl;   
}