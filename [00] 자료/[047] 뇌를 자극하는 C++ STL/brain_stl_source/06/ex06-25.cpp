#include <iostream>
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

    vector<int> v2( v.begin(), v.end() ); // ������ [v.begin(), v.end())�� v2�� �ʱ�ȭ.

    vector<int>::iterator iter;
    for( iter = v2.begin(); iter != v2.end() ; ++iter)
        cout << *iter << " "; // v2 ���
    cout << endl;

    vector<int> v3;
    v3.assign( v.begin(), v.end() );  // v3�� ������ [v.begin(), v.end())�� �Ҵ�.
    for( iter = v3.begin(); iter != v3.end() ; ++iter)
        cout << *iter << " "; // v3 ���
    cout << endl;
}
