#include <iostream>
#include <vector>
using namespace std;

void main( )
{ 
    vector<int> v1(5); //0���� �ʱ�ȭ�� size�� 5�� �����̳�
    v1.push_back(10); //10 �߰�
    v1.push_back(20); //20 �߰�
    v1.push_back(30); //30 �߰�
    v1.push_back(40); //40 �߰�
    v1.push_back(50); //50 �߰�
    
    for(vector<int>::size_type i = 0 ; i < v1.size() ; ++i)
        cout << v1[i] << " ";   
    cout << endl;

    vector<int> v2(5); //0���� �ʱ�ȭ�� size�� 5�� �����̳�
    v2[0] = 10; // 0���� 10�� ����
    v2[1] = 20; // 0���� 20�� ����
    v2[2] = 30; // 0���� 30�� ����
    v2[3] = 40; // 0���� 40�� ����
    v2[4] = 50; // 0���� 50�� ����
    
    for(vector<int>::size_type i = 0 ; i < v2.size() ; ++i)
        cout << v2[i] << " ";   
    cout << endl;
}