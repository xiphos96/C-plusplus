#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool Pred(int left, int right)
{
    return abs(right-left) < 5;
}
void main( )
{  
    vector<int> v1;
    v1.push_back(10);
    v1.push_back(21);
    v1.push_back(30);

    vector<int> v2;
    v2.push_back(10);
    v2.push_back(20);
    v2.push_back(33);


    cout << "v1 : ";
    for(vector<int>::size_type i = 0; i < v1.size(); ++i)
        cout << v1[i] <<" ";
    cout << endl;

    cout << "v2 : ";
    for(vector<int>::size_type i = 0; i < v2.size(); ++i)
        cout << v2[i] <<" ";
    cout << endl;

    //���� [v1.being(), v1.end)�� ���� [v2.begin(), v2.begin()+3)�� �� �մϴ�.
    if( equal(v1.begin(), v1.end(), v2.begin(), Pred) )
        cout << "�� �������� �����ϴ�." << endl;
}