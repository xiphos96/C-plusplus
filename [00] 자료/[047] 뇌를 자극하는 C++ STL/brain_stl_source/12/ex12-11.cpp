#include <iostream>
#include <string>
using namespace std;

void main( )
{
    string s1, s2;

    
    //cin >> buf�� ����.
    //cout << "�� ���ڿ� �Է�:"<<endl;
    //cin >> s1 >> s2;
    //cout <<"s1: "<< s1 <<"   s2: "<< s2 << endl;

    //cin.getline(buf)�� ����.
    cout << "�� ���ڿ� �Է�(���� ���� ����):"<<endl;
    getline(cin, s1);
    getline(cin, s2, '\n');
    cout <<"s1: "<< s1 <<endl;
    cout <<"s2: "<< s2 << endl;
}