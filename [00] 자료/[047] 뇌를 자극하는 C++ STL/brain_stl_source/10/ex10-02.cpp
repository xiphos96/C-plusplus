#include <iostream>
#include <vector>
using namespace std;

void main() 
{
    vector<int> v;
    v.push_back(10);
    v.push_back(20);
    v.push_back(30);
    v.push_back(40);

    vector<int>::iterator iter = v.begin();
    vector<int>::const_iterator citer = v.begin()+1;
    const vector<int>::iterator const_iter = v.begin()+2;
    const vector<int>::const_iterator const_citer = v.begin()+3;

    //iter�� ��� ����
    *iter = 100; // ����Ű�� ���� ���� ����
    ++iter; // �ݺ��� ���� ����

    //citer
    *citer = 200; // ����Ű�� ���� ���� �Ұ���
    ++citer; // �ݺ��� ���� ����

    //const_iter
    *const_iter = 300; // ����Ű�� ���� ���� ����
    ++const_iter; // �ݺ��� ���� �Ұ���

    //const_citer
    *const_citer = 400; // ����Ű�� ���� ���� �Ұ���
    ++const_citer; // �ݺ��� ���� �Ұ���
}