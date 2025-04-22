#include <iostream>
#include <vector>
using namespace std;
using Graph = vector<vector<int>>;

// ����ͥ��õ��
vector<bool> seen;
void dfs(const Graph &G, int v) {
    seen[v] = true; // v ��ˬ��Ѥˤ���

    // v ����Ԥ����ĺ�� next_v �ˤĤ���
    for (auto next_v : G[v]) { 
        if (seen[next_v]) continue; // next_v ��õ���Ѥʤ��õ�����ʤ�
        dfs(G, next_v); // �Ƶ�Ū��õ��
    }
}

int main() {
    // ĺ�������տ�
    int N, M;
    cin >> N >> M;

    // ��������ϼ��� (�����Ǥ�ͭ������դ�����)
    Graph G(N);
    for (int i = 0; i < M; ++i) {
        int a, b;
        cin >> a >> b;
        G[a].push_back(b);
    }

    // õ��
    seen.assign(N, false); // ������֤Ǥ���ĺ����̤ˬ��
    for (int v = 0; v < N; ++v) {
        if (seen[v]) continue; // ���Ǥ�ˬ��Ѥߤʤ�õ�����ʤ�
        dfs(G, v);
    }
}
