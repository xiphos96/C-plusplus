#include <iostream>
#include <vector>
using namespace std;

void main( )
{ 
    vector<int> v(5, 1); // �ʱⰪ 1�� 5���� ���Ҹ� ���� �����̳� ����

    for(vector<int>::size_type i = 0 ; i < v.size() ; ++i)
        cout << v[i] << " ";   
    cout << endl;

    v.assign(5, 2); // 5���� ���Ұ��� 2�� �Ҵ�
    cout << v.size() <<',' << v.capacity() << endl;
    for(vector<int>::size_type i = 0 ; i < v.size() ; ++i)
        cout << v[i] << " ";   
    cout << endl;
}