#include <iostream>
#include <string>
using namespace std;

void main( )
{
    string s("Hello!");
    const char *sz;
    const char *buf;

    sz = s.c_str();
    buf = s.data();

    cout <<"'\\0'���ڷ� ������ ���ڿ�(C-style): " << sz << endl;    
    cout <<"'\\0'���� �������� ���� ���ڿ� �迭: ";
    for(int i=0 ; i < 6 ; ++i)
        cout << buf[i];
    cout << endl;
}