#include <iostream>
#include <map>
using namespace std;

void main( )
{  
    map<int,int> m;
    pair<map<int,int>::iterator, bool> pr; // insert() ��� pair ��ü

    m.insert( pair<int,int>(5,100) );
    m.insert( pair<int,int>(3,100) );
    m.insert( pair<int,int>(8,30) );
    m.insert( pair<int,int>(4,40) );
    m.insert( pair<int,int>(1,70) );
    m.insert( pair<int,int>(7,100) );    
    
    pr =m.insert( pair<int,int>(9,50) ); // ����!
    if( true == pr.second )
        cout << "key: " << pr.first->first << ", value: " << pr.first->second <<" ���� �Ϸ�!" <<endl;
    else
        cout << "key 9�� �̹� m�� �ֽ��ϴ�." << endl;

    pr =m.insert( pair<int,int>(9,50) ); // ����!
    if( true == pr.second )
        cout << "key: " << pr.first->first << ", value: " << pr.first->second <<"���� �Ϸ�!" <<endl;
    else
        cout << "key: 9�� �̹� m�� �ֽ��ϴ�." << endl;
}