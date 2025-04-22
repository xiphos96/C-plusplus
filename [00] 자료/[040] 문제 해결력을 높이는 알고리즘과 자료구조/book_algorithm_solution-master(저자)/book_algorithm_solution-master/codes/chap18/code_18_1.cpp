#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
using Graph = vector<vector<int>>;

// ����
int N; // ĺ����
vector<long long> w; // ��ĺ���νŤ�
Graph G; // �����

// �ھ��ưŪ�ײ�ˡ�ơ��֥�
vector<int> dp1, dp2;

void dfs(int v, int p = -1) {
    // �ǽ�˳ƻ�ĺ����õ�����Ƥ����ޤ�
    for (auto ch : G[v]) {
        if (ch == p) continue;
        dfs(ch, v);
    }

    // ���꤬������ưŪ�ײ�ˡ
    dp1[v] = 0, dp2[v] = w[v]; // ������
    for (auto ch : G[v]) {
        if (ch == p) continue;
        dp1[v] += max(dp1[ch], dp2[ch]);
        dp2[v] += dp1[ch];
    }
}

int main() {
    // ĺ���� (�ڤʤΤ��տ��� N - 1 �ǳ���)
    cin >> N;

    // �Ťߤȥ���դ����ϼ���
    w.resize(N);
    for (int i = 0; i < N; ++i) cin >> w[i];
    G.clear(); G.resize(N);
    for (int i = 0; i < N - 1; ++i) {
        int a, b;
        cin >> a >> b;
        G[a].push_back(b);
        G[b].push_back(a);
    }

    // õ��
    int root = 0; // ����ĺ�� 0 �򺬤Ȥ���
    dp1.assign(N, 0), dp2.assign(N, 0);
    dfs(root);

    // ���
    cout << max(dp1[root], dp2[root]) << endl;
}
