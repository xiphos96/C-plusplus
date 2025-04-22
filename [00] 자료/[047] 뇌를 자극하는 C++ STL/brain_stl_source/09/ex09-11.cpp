#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

void main( )
{
    vector<int> v;
    v.push_back(10); 
    v.push_back(20);
    v.push_back(30);
    v.push_back(40);
    v.push_back(50);

    cout <<"v : ";
    for(vector<int>::size_type i = 0 ; i < v.size() ; i++)
        cout << v[i] << " ";
    cout << endl;

    cout <<"20 ���� ���� ������ ����: "<< count_if(v.begin(), v.end(), 
        bind2nd<less<int> >(less<int>(), 20) ) << endl;
    cout <<"20 ���� �۰ų� ���� ������ ����: "<< count_if(v.begin(), v.end(), 
        bind2nd<less_equal<int> >(less_equal<int>(), 20) ) << endl;
    cout <<"20 ���� ū ������ ����: "<< count_if(v.begin(), v.end(), 
        bind2nd<greater<int> >(greater<int>(), 20) ) << endl;
    cout <<"20 ���� ũ�ų� ���� ������ ����: "<< count_if(v.begin(), v.end(), 
        bind2nd<greater_equal<int> >(greater_equal<int>(), 20) ) << endl;
    cout <<"20�� ���� ������ ����: "<< count_if(v.begin(), v.end(), 
        bind2nd<equal_to<int> >(equal_to<int>(), 20) ) << endl;
    cout <<"20�� �ٸ� ������ ����: "<< count_if(v.begin(), v.end(), 
        bind2nd<not_equal_to<int> >(not_equal_to<int>(), 20) ) << endl;
}
