#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void main( )
{
    vector<int> v1;
    v1.push_back(10);
    v1.push_back(20);
    v1.push_back(30);
    v1.push_back(40);
    v1.push_back(50);

    cout << "v1 : ";
    for(vector<int>::size_type i = 0; i < v1.size(); ++i)
        cout << v1[i] <<" ";
    cout << endl;

    vector<int> v2(5);
    vector<int>::iterator middle=v1.begin()+2;
    vector<int>::iterator iter_end;
    // ��� ���Ҹ� �������� 2��ŭ�� ȸ���Ͽ� [v2.begin(), iter_end) �������� �����Ѵ�.
    iter_end=rotate_copy(v1.begin(), middle, v1.end(),v2.begin());

    cout << "v2 : ";
    for(vector<int>::iterator iter=v2.begin(); iter!=iter_end; ++iter)
        cout << *iter <<" ";
    cout << endl;
}