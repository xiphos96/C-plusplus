#include <iostream>
#include <set>
using namespace std;

void main( )
{
    set<int> s; // ���� ���Ҹ� �����ϴ� �⺻ ���� ������ less�� �� �����̳� ����

    s.insert(50); //�������� ����(key)�� �����Ѵ�.
    s.insert(30);
    s.insert(80);
    s.insert(40);
    s.insert(10);
    s.insert(70);
    s.insert(90);

    set<int>::iterator iter; // �⺻ ���� ������ less�� set�� ����� �ݺ���
    for( iter = s.begin() ; iter != s.end() ; ++iter)
        cout << *iter << " "; // inorder 2�� Ʈ�� Ž�� ������ ��µȴ�.
    cout << endl;

    s.insert(50); //�ߺ��� ����(key)�� �����Ѵ�. ����!!
    s.insert(50);

    for( iter = s.begin() ; iter != s.end() ; ++iter)
        cout << *iter << " "; // ����� ����.
    cout << endl;
}
