#include <iostream>
#include <vector>
using namespace std;

// ���� a �ζ�� [left, right) �򥽡��Ȥ���
// [left, right) �ϡ�left, left+1, ..., right-1 ���ܤ�ɽ��
void QuickSort(vector<int> &a, int left, int right) {
    if (right - left <= 1) return;

    int pivot_index = (left + right) / 2;  // Ŭ���ˤ����Ǥ������Ȥ��ޤ�
    int pivot = a[pivot_index];
    swap(a[pivot_index], a[right - 1]);    // pivot �ȱ�ü�� swap

    int i = left; // i �Ϻ��ͤᤵ�줿 pivot ̤�����Ǥα�ü��ɽ��
    for (int j = left; j < right - 1; ++j) {
        if (a[j] < pivot) { // pivot ̤���Τ�Τ����ä��麸�˵ͤ�Ƥ���
            swap(a[i++], a[j]);
        }
    }
    swap(a[i], a[right - 1]); // pivot ��Ŭ�ڤʾ�������

    // �Ƶ�Ū�˲�
    QuickSort(a, left, i);    // ��Ⱦʬ (pivot ̤��)
    QuickSort(a, i + 1, right); // ��Ⱦʬ (pivot �ʾ�)
}

int main() {
    // ����
    int N; // ���ǿ�
    cin >> N;
    vector<int> a(N);
    for (int i = 0; i < N; ++i) cin >> a[i];

    // �����å�������
    QuickSort(a, 0, N);
}
