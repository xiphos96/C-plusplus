#include <iostream>
#include <set>
using namespace std;

void main( )
{ 
    multiset<int> ms;
    
    ms.insert(50);
    ms.insert(30);
    ms.insert(80);
    ms.insert(80); // 80 �ߺ�
    ms.insert(30); // 30 �ߺ�
    ms.insert(70); 
    ms.insert(10);

    multiset<int>::iterator iter;    
    for( iter = ms.begin() ; iter != ms.end() ; ++iter)
        cout << *iter << " ";
    cout << endl;

    cout <<"30 ������ ����: " << ms.count(30) << endl; // 30 ������ ����

    iter = ms.find(30); // 30 ù ��° ������ �ݺ���
    cout << "iter: " << *iter<< endl;

    multiset<int>::iterator lower_iter;    
    multiset<int>::iterator upper_iter;    

    lower_iter = ms.lower_bound(30); // 30 �������� ���� �ݺ���
    upper_iter = ms.upper_bound(30); // 30 �������� �� ǥ�� �ݺ���
    cout <<"lower_iter: " << *lower_iter <<",  " <<"upper_iter: " << *upper_iter << endl;

    cout <<"���� [lower_iter, upper_iter)�� ������: " ;
    for( iter = lower_iter ; iter != upper_iter ; ++iter)
        cout << *iter << " ";
    cout << endl;
}
