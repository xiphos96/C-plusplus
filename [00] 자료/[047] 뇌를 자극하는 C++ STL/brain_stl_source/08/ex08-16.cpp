#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

template< typename T>
struct Less
{
    bool operator()(const T& left, const T& right) const
    {
        return left < right;
    }
};
void main( )
{
    vector<int> v1;
    v1.push_back(10);
    v1.push_back(20);
    v1.push_back(30);

    vector<int> v2;
    v2.push_back(10);
    v2.push_back(25);
    v2.push_back(30);
    
    if( lexicographical_compare(v1.begin(), v1.end(), v2.begin(), v2.end(), less<int>()) ) 
        cout << "���� less v1�� v2�� ��: true" << endl;
    else
        cout << "���� less v1�� v2�� ��: false" << endl;


    if( lexicographical_compare(v1.begin(), v1.end(), v2.begin(), v2.end(), greater<int>()) ) 
        cout << "���� greater v1�� v2�� ��: true" << endl;
    else
        cout << "���� greater v1�� v2�� ��: false" << endl;


    if( lexicographical_compare(v1.begin(), v1.end(), v2.begin(), v2.end(), Less<int>()) ) 
        cout << "����� ���� Less v1�� v2�� ��: true" << endl;
    else
        cout << "����� ���� Less v1�� v2�� ��: false" << endl;
}