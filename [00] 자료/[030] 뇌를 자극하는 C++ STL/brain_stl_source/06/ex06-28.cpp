#include <iostream>
#include <vector>
#include <deque>
using namespace std;

void main() 
{
    vector<int> v(4, 100); //100���� �ʱ�ȭ�� 4���� ���Ҹ� ���� �����̳� v
    deque<int> dq(4, 100); //100���� �ʱ�ȭ�� 4���� ���Ҹ� ���� �����̳� dq

    v.push_back( 200 ); // v�� 200 �߰�
    dq.push_back( 200 ); // dq�� 200 �߰�

    for(vector<int>::size_type i = 0 ; i < v.size() ; ++i)
        cout << v[i] << " ";
    cout << endl;
    for(deque<int>::size_type i = 0 ; i < dq.size() ; ++i)
        cout << dq[i] << " ";
    cout << endl;
}
