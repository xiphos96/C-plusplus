#include <iostream>
#include <vector>
using namespace std;

const int MAX = 100000; // �����Ǥ�������ͤ� 100000 ̤���Ȥ���

// �Х��åȥ�����
void BucketSort(vector<int> &a) {
    int N = (int)a.size();
    
    // �����ǤθĿ��򥫥���Ȥ���
    // num[v]: v �θĿ�
    vector<int> num(MAX, 0);
    for (int i = 0; i < N; ++i) {
        ++num[a[i]]; // a[i] �򥫥���Ȥ���
    }

    // num �������¤�Ȥ�
    // sum[v]: v �ʲ����ͤθĿ�
    // �� a[i] �����Τ���ǲ����ܤ˾������������
    vector<int> sum(MAX, 0);
    sum[0] = num[0];
    for (int v = 1; v < MAX; ++v) {
        sum[v] = sum[v - 1] + num[v];
    }

    // sum ���Ȥ˥����Ƚ���
    // a2: a �򥽡��Ȥ������
    vector<int> a2(N);
    for (int i = N - 1; i >= 0; --i) {
        a2[--sum[a[i]]] = a[i];
    }
    a = a2;
}

int main() {
    // ����
    int N; // ���ǿ�
    cin >> N;
    vector<int> a(N);
    for (int i = 0; i < N; ++i) cin >> a[i];

    // �Х��åȥ�����
    BucketSort(a);
}
