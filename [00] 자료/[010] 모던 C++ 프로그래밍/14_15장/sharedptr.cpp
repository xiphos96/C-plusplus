#include <iostream>
#include <memory>

using namespace std;

int main()
{
    shared_ptr<int> s(new int);         // ���� ī��Ʈ 1
    
    *s = 10;
    cout << "���� ī��Ʈ 1" << endl;
    cout << *s << endl;

    shared_ptr<int> t = s;              // ���� ī��Ʈ 2
    *t += 1;                            // 11�� ����

    cout << "���� ī��Ʈ 2" << endl;
    cout << *s << endl;                 // ������ ���� 11 ���
    cout << *t << endl;

    shared_ptr<int> u = t;              // ���� ī��Ʈ 3

    cout << "���� ī��Ʈ 3" << endl;
    *u += 1;

    cout << *s << endl;                 // ������ ���� 12 ���
    cout << *t << endl;
    cout << *u << endl;

    return 0;
}