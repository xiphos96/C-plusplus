#include <iostream>
#include <string>
using namespace std;

void main( )
{
    string t("Hello!");
    string s1, s2, s3, s4, s5;

    s1 = t.substr(0);
    s2 = t.substr(0, string::npos);

    s3 = t.substr(0, 2);
    s4 = t.substr(2, 3);
    s5 = t.substr(2, string::npos);

    cout <<"substr(0)-0���� ������: "<< s1 << endl;
    cout <<"substr(0, npos)-0���� ������: "<< s2 << endl;
    cout <<"substr(0, 2)-0���� 2��: "<< s3 << endl;
    cout <<"substr(2, 3)-2���� 3��: "<< s4 << endl;
    cout <<"substr(2, npos)-2���� ������: "<< s5 << endl;
}