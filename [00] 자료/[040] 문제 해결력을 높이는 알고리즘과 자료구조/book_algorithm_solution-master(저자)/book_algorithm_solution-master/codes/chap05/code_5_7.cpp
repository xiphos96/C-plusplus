#include <iostream>
#include <vector>
using namespace std;

template<class T> void chmax(T& a, T b) {
    if (a < b) {
        a = b;
    }
}

int main() {
    // ����
    int N;
    long long W;
    cin >> N >> W;
    vector<long long> weight(N), value(N);
    for (int i = 0; i < N; ++i) cin >> weight[i] >> value[i];

    // DP �ơ��֥����
    vector<vector<long long>> dp(N + 1, vector<long long>(W + 1, 0));

    // DP�롼��
    for (int i = 0; i < N; ++i) {
        for (int w = 0; w <= W; ++w) {

            // i ���ܤ���ʪ�����־��
            if (w - weight[i] >= 0) {
                chmax(dp[i + 1][w], dp[i][w - weight[i]] + value[i]);
            }

            // i ���ܤ���ʪ�����Фʤ����
            chmax(dp[i + 1][w], dp[i][w]);
        }
    }

    // ��Ŭ�ͤν���
    cout << dp[N][W] << endl;
}
