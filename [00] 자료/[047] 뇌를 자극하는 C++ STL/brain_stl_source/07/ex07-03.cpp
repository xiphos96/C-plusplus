#include <iostream>
#include <set>
using namespace std;

void main( )
{
    set<int> s;
    pair<set<int>::iterator, bool> pr;

    s.insert(50);
    s.insert(30);
    s.insert(80);
    s.insert(40);
    s.insert(10);
    s.insert(70);
    pr=s.insert(90); //pr.first�� 90������ �ݺ���


    set<int>::iterator iter;
    for( iter = s.begin() ; iter != s.end() ; ++iter)
        cout << *iter << " ";
    cout << endl;

    s.insert(pr.first, 85); //90������ �ݺ��ڿ��� �˻� ���� �� �����Ѵ�. 
    
    for( iter = s.begin() ; iter != s.end() ; ++iter)
        cout << *iter << " ";
    cout << endl;
}
