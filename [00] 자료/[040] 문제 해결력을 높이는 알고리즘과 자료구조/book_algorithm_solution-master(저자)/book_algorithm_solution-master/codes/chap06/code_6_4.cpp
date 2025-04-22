#include <iostream>
#include <vector>
#include <algorithm> // sort() �� lower_bound() ��ɬ�פǤ�
using namespace std;
const int INF = 20000000; // ��ʬ�礭���ͤ�

int main() {
    // ���Ϥ�������
    int N, K;
    cin >> N >> K;
    vector<int> a(N), b(N);
    for (int i = 0; i < N; ++i) cin >> a[i];
    for (int i = 0; i < N; ++i) cin >> b[i];

    // ����Ǿ��ͤ��Ǽ�����ѿ�
    int min_value = INF;

    // b �򥽡���
    sort(b.begin(), b.end());

    // b ��̵�����ɽ���� (INF) ���ɲä��Ƥ���
    // �����Ԥ����Ȥǡ�iter = b.end() �Ȥʤ��ǽ�����������
    b.push_back(INF);

    // a ����ꤷ�Ʋ�
    for (int i = 0; i < N; ++i) {
        // b ����� K - a[i] �ʾ���ϰϤǤκǾ��ͤ򼨤����ƥ졼��
        auto iter = lower_bound(b.begin(), b.end(), K - a[i]);

        // ���ƥ졼���μ����ͤ���Ф�
        int val = *iter;

        // min_value ����Ӥ���
        if (a[i] + val < min_value) {
            min_value = a[i] + val;
        }
    }
    cout << min_value << endl;
}
