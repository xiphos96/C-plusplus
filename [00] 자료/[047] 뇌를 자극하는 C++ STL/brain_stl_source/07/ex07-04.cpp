#include <iostream>
#include <set>
using namespace std;

void main( )
{
    set<int, greater<int> > s; // ���� �������� greater<int> �����ڸ� ���.

    s.insert(50);
    s.insert(30);
    s.insert(80);
    s.insert(40);
    s.insert(10);
    s.insert(70);
    s.insert(90);


    // greater<int> �����ڸ� ����ϴ� �ݺ��� ����
    set<int, greater<int> >::iterator iter; 
    for( iter = s.begin() ; iter != s.end() ; ++iter)
        cout << *iter << " ";
    cout << endl;
}