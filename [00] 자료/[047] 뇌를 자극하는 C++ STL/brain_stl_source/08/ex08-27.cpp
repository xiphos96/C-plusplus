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
    v.push_back(50);

    // ���� [v.begin(), v.end())�� ��� ���Ҹ� 0���� ä���.
    fill(v.begin(), v.end(), 0);
    cout << "v : ";
    for(vector<int>::size_type i = 0; i < v.size(); ++i)
        cout << v[i] <<" ";
    cout << endl;

    // ���� [v.begin(), v.begin()+3)�� ��� ���Ҹ� 55�� ä���.
    fill_n(v.begin(), 3, 55);
    cout << "v : ";
    for(vector<int>::size_type i = 0; i < v.size(); ++i)
        cout << v[i] <<" ";
    cout << endl;
}