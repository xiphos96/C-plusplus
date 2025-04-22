#include <iostream>
#include <vector>
using namespace std;

template<class T> void chmin(T& a, T b) {
    if (a > b) {
        a = b;
    }
}

const long long INF = 1LL << 60; // ��ʬ�礭���� (�����Ǥ� 2^60 �Ȥ���)

int main() {
    // ����
    int N;
    cin >> N;
    vector<vector<long long>> c(N + 1, vector<long long>(N + 1));
    for (int i = 0; i < N + 1; ++i) {
        for (int j = 0; j < N + 1; ++j) {
            cin >> c[i][j];
        }
    }
    
    // DP �ơ��֥����
    vector<long long> dp(N + 1, INF);
    
    // DP ������
    dp[0] = 0;

    // DP�롼��
    for (int i = 0; i <= N; ++i) {
        for (int j = 0; j < i; ++j) {
            chmin(dp[i], dp[j] + c[j][i]);
        }
    }
    
    // �����ν���
    cout << dp[N] << endl;
}
