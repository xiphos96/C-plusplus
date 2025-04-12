#include <iostream>
#include <vector>
 
using namespace std;
 
int main()
{
    vector<int> v(6, 1);
    for (auto i = 0; i < v.size(); i++)
        cout << v[i] << " ";
    cout << endl;
     
    v.assign(4, 3);
    for (auto i = 0; i < v.size(); i++)
        cout << v[i] << " ";
    cout << endl;
     
    v[2] = 7;
    for (auto i = 0; i < v.size(); i++)
        cout << v[i] << " ";
    cout << endl;
     
    for (vector<int>::iterator it = v.begin()+3; it != v.end(); it++)
        *it = 9;
    for (auto i = 0; i < v.size(); i++)
        cout << v[i] << " ";
    cout << endl;
     
    v.push_back(10);
    v.push_back(20);
    for (auto i = 0; i < v.size(); i++)
        cout << v[i] << " ";
    cout << endl;
 
    return 0;
}
 

