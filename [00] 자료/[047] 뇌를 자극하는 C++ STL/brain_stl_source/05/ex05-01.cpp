#include <iostream>
#include <vector>
using namespace std;

void main( )
{
    vector<int> v; // ������ �����ϴ� �����̳� v ����

    v.push_back(10); // v�� ���� �߰�
    v.push_back(20);
    v.push_back(30);
    v.push_back(40);
    v.push_back(50);

    for(unsigned int i = 0 ; i < v.size() ; ++i)
        cout << v[i] << endl; // v[i]�� i��° index�� ���� ��ȯ
}