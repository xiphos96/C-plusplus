#include <iostream>
#include <functional>
using namespace std;

void main( )
{
    less<int> oLess;
    //1. oLess ��ü�� 10, 20�� �� true. �Ϲ��� ȣ��
    cout << oLess(10, 20) << endl;
    //2. oLess ��ü�� 10, 20�� �� true.  ����� ȣ��
    cout << oLess.operator()(10,20) << endl;

    //3. �ӽ� ��ü�� 10, 20�� �� true. �Ϲ��� ȣ��(�Ϲ����� ���)
    cout << less<int>()(10, 20) << endl;
    //4. �ӽ� ��ü�� 10, 20�� �� true. ����� ȣ��
    cout << less<int>().operator()(10, 20) << endl;
}