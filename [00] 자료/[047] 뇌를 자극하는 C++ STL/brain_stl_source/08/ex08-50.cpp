#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool Pred(int n)
{
    return n < 40;
}
void main( )
{
    vector<int> v;
    v.push_back(30);
    v.push_back(40);
    v.push_back(50);
    v.push_back(10);
    v.push_back(20);
    v.push_back(60);

    cout << "v : ";
    for(vector<int>::size_type i = 0; i < v.size(); ++i)
        cout << v[i] <<" ";
    cout << endl;

    vector<int>::iterator iter_sep;
    // ���ҵ��� ������� ������ �����ϸ� 40 ���Ҹ� �������� �̸��� �̻��� �з��Ѵ�.
    iter_sep = stable_partition(v.begin(), v.end(), Pred);

    cout <<"40�̸��� ������: ";
    for(vector<int>::iterator iter=v.begin(); iter != iter_sep; ++iter)
        cout << *iter <<" ";
    cout << endl;
    cout <<"40�̻��� ������: ";
    for(vector<int>::iterator iter=iter_sep; iter != v.end(); ++iter)
        cout << *iter <<" ";
    cout << endl;
}