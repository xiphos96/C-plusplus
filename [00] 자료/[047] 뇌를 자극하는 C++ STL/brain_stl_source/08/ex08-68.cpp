#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void main( )
{
    vector<int> v;

    v.push_back(10);
    v.push_back(30);
    v.push_back(40);
    v.push_back(50);
    v.push_back(20);
        
    cout << "[v ����]: ";
    for(vector<int>::size_type i = 0; i < v.size(); ++i)
        cout << v[i] <<" ";
    cout << endl;

    //�⺻ ���� ���� less ���
    sort(v.begin(), v.end());        
    cout << "[v: less ����]: ";
    for(vector<int>::size_type i = 0; i < v.size(); ++i)
        cout << v[i] <<" ";
    cout << endl;

    //�� ������ less ����(�Ϲ� ���� binary_search() ����)
    cout <<"�� less ã��: "<< binary_search(v.begin(), v.end(), 20, less<int>()) << endl;

    //���� ���� greater ����
    sort(v.begin(), v.end(), greater<int>());        
    cout << "[v: greater ����]: ";
    for(vector<int>::size_type i = 0; i < v.size(); ++i)
        cout << v[i] <<" ";
    cout << endl;

    //������ ���� ���� greater ����
    cout <<"�� greater ã��: "<< binary_search(v.begin(), v.end(), 20, greater<int>()) << endl;
}