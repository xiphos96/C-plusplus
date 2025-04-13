#include <iostream>
#include <vector>
using namespace std;

// ���� a �ζ�� [left, right) �򥽡��Ȥ���
// [left, right) �ϡ�left, left+1, ..., right-1 ���ܤ�ɽ��
void MergeSort(vector<int> &a, int left, int right) {
    if (right - left == 1) return;
    int mid = left + (right - left) / 2;

    // ��Ⱦʬ [left, mid) �򥽡���
    MergeSort(a, left, mid);

    // ��Ⱦʬ [mid, right) �򥽡���
    MergeSort(a, mid, right);

    // ���ä���ֺ��פȡֱ��פΥ����ȷ�̤򥳥ԡ����Ƥ��� (��¦�Ϻ���ȿž)
    vector<int> buf;
    for (int i = left; i < mid; ++i) buf.push_back(a[i]);
    for (int i = right - 1; i >= mid; --i) buf.push_back(a[i]);

    // ʻ�礹��
    int index_left = 0;                    // ��¦��ź��
    int index_right = (int)buf.size() - 1; // ��¦��ź��
    for (int i = left; i < right; ++i) {
        // ��¦����
        if (buf[index_left] <= buf[index_right]) {
            a[i] = buf[index_left++];
        }
        // ��¦����
        else {
            a[i] = buf[index_right--];
        }
    }
}

int main() {
    // ����
    int N; // ���ǿ�
    cin >> N;
    vector<int> a(N);
    for (int i = 0; i < N; ++i) cin >> a[i];

    // �ޡ���������
    MergeSort(a, 0, N);
}
