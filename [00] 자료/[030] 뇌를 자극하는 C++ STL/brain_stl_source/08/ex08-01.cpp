#include <iostream>
#include <vector>
#include <algorithm> //�˰��� ���
using namespace std;

void main( )
{  
    vector<int> v;
    v.push_back(10);
    v.push_back(20);
    v.push_back(30);
    v.push_back(30);
    v.push_back(40);
    v.push_back(40);
    v.push_back(50);

    for(vector<int>::size_type i = 0; i < v.size(); ++i)
        cout << v[i] <<" ";
    cout << endl;

    vector<int>::iterator iter; 
    //���� [v.begin(), v.end())���� ���� ���ҿ� ���� ���Ұ� �������� ù ��° �ݺ��ڸ� ��ȯ
    iter = adjacent_find(v.begin(), v.end());

    if( iter != v.end() ) //���� ���Ұ� ���ٸ� ������ �� �ݺ��� ��ȯ
        cout << *iter << endl;

    for( ; iter != v.end() ; ++iter)
        cout << *iter <<" ";
    cout << endl;
}