#include <iostream>
#include <vector>
#include <algorithm> // find ���
using namespace std;

void main( )
{ 
    vector<int> v; 

    v.push_back(10); 
    v.push_back(20);
    v.push_back(30);
    v.push_back(40);
    v.push_back(50);

    vector<int>::iterator iter;
    iter = find(v.begin(), v.end(), 20); //[begin, end)���� 20 ã��
    cout << *iter << endl;

    iter = find(v.begin(), v.end(), 100); //[begin, end)���� 100 ã��
    if( iter == v.end() ) // 100�� ������ iter==v.end() ��
        cout << "100�� ����!" << endl;
}