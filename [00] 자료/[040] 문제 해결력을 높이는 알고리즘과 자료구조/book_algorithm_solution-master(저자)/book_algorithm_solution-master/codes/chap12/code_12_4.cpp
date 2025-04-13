#include <iostream>
#include <vector>
using namespace std;

// i ���ܤ�ĺ���򺬤Ȥ�����ʬ�ڤˤĤ��ơ��ҡ��׾����������褦�ˤ���
// a �Τ��� 0 ���ܤ��� N-1 ���ܤޤǤ���ʬ a[0:N] �ˤĤ��ƤΤ߹ͤ���
void Heapify(vector<int> &a, int i, int N) {
    int child1 = i * 2 + 1; // ���λҶ�
    if (child1 >= N) return; // �Ҷ����ʤ��Ȥ��Ͻ�λ

    // �Ҷ�Ʊ�Τ����
    if (child1 + 1 < N && a[child1 + 1] > a[child1]) ++child1;
    
    if (a[child1] <= a[i]) return; // ��ž���ʤ��ä��齪λ

    // swap
    swap(a[i], a[child1]);

    // �Ƶ�Ū��
    Heapify(a, child1, N);
}

// ���� a �򥽡��Ȥ���
void HeapSort(vector<int> &a) {
    int N = (int)a.size();

    // ���ƥå� 1: a ���Τ�ҡ��פˤ���ե�����
    for (int i = N / 2 - 1; i >= 0; --i) {
        Heapify(a, i, N);
    }

    // ���ƥå� 2: �ҡ��פ��� 1 �� 1 �ĺ����ͤ� pop ����ե�����
    for (int i = N - 1; i > 0; --i) {
        swap(a[0], a[i]); // �ҡ��פκ����ͤ򺸵ͤ�
        Heapify(a, 0, i); // �ҡ��ץ������� i ��
    }
}

int main() {
    // ����
    int N; // ���ǿ�
    cin >> N;
    vector<int> a(N);
    for (int i = 0; i < N; ++i) cin >> a[i];

    // �ҡ��ץ�����
    HeapSort(a);
}
