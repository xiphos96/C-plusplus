#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void main( )
{  
    vector<int> v;
    v.push_back(10);
    v.push_back(20);
    v.push_back(30);
    v.push_back(40);
    v.push_back(30);
    v.push_back(50);

    for(vector<int>::size_type i = 0; i < v.size(); ++i)
        cout << v[i] <<" ";
    cout << endl;

    // ���� [v.begin(), v.end())���� 30 ������ ������ ��ȯ
    int n = count(v.begin(), v.end(), 30);
    cout <<"30�� ����: "<< n << endl;
}