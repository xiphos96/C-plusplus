#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
    // ����
    int N;
    cin >> N;
    vector<long long> H(N), S(N);
    for (int i = 0; i < N; i++) cin >> H[i] >> S[i];

    // ��ʬõ���ξ���ͤ����
    long long M = 0;
    for (int i = 0; i < N; ++i) M = max(M, H[i] + S[i] * N);

    // ��ʬõ��
    long long left = 0, right = M;
    while (right - left > 1) {
        long long mid = (left + right) / 2;
        
        // Ƚ�ꤹ��
        bool ok = true;
        vector<long long> t(N, 0);  // ����������ޤǤ����»���
        for (int i = 0; i < N; ++i) {
            // ���⤽�� mid ��������٤���㤫�ä��� false
            if (mid < H[i]) ok = false; 
            else t[i] = (mid - H[i]) / S[i];
        }
        // �������¤��������äƤ����˥����� ����
        sort(t.begin(), t.end()); 
        for (int i = 0; i < N; ++i) {
            // �����ڤ�ȯ���ξ��� false
            if (t[i] < i) ok = false; 
        }

        if (ok) right = mid;
        else left = mid;
    }

    cout << right << endl;
}
