#include <iostream>
#include <vector>
using namespace std;

// ���� a �򥽡��Ȥ���
void InsertionSort(vector<int> &a) {
    int N = (int)a.size();
    for (int i = 1; i < N; ++i) {
        int v = a[i]; // ������������

        // v ����������Ŭ�ڤʾ�� j ��õ��
        int j = i;
        for (; j > 0; --j) {
            if (a[j-1] > v) { // v ����礭����Τ� 1 �ĸ��˰ܤ�
                a[j] = a[j-1];
            }
            else break; // v �ʲ��ˤʤä���ߤ��
        }
        a[j] = v; // �Ǹ�� j ���ܤ� v ���äƤ���
    }
}

int main() {
    // ����
    int N; // ���ǿ�
    cin >> N;
    vector<int> a(N);
    for (int i = 0; i < N; ++i) cin >> a[i];

    // ����������
    InsertionSort(a);
}
