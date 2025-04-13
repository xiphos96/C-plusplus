#include <iostream>
#include <string>
#include <vector>
using namespace std;

template<class T> void chmin(T& a, T b) {
    if (a > b) {
        a = b;
    }
}

const int INF = 1 << 29; // ��ʬ�礭���� (�����Ǥ� 2^29 �Ȥ���)

int main() {
    // ����
    string S, T;
    cin >> S >> T;
    
    // DP �ơ��֥����
    vector<vector<int>> dp(S.size() + 1, vector<int>(T.size() + 1, INF));

    // DP ������
    dp[0][0] = 0;

    // DP�롼��
    for (int i = 0; i <= S.size(); ++i) {
        for (int j = 0; j <= T.size(); ++j) {
            // �ѹ����
            if (i > 0 && j > 0) {
                if (S[i - 1] == T[j - 1]) {
                    chmin(dp[i][j], dp[i - 1][j - 1]);
                }
                else {
                    chmin(dp[i][j], dp[i - 1][j - 1] + 1);
                }
            }
            
            // ������
            if (i > 0) chmin(dp[i][j], dp[i - 1][j] + 1);

            // �������
            if (j > 0) chmin(dp[i][j], dp[i][j - 1] + 1);
        }
    }
    
    // �����ν���
    cout << dp[S.size()][T.size()] << endl;
}
