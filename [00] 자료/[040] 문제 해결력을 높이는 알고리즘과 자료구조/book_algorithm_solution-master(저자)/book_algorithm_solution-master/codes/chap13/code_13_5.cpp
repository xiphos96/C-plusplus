#include <iostream>
#include <vector>
using namespace std;
using Graph = vector<vector<int>>;

// ���������Ƚ��
vector<int> color;
bool dfs(const Graph &G, int v, int cur = 0) {
    color[v] = cur;
    for (auto next_v : G[v]) {
        // ����ĺ�������Ǥ˿����ꤷ�Ƥ������
        if (color[next_v] != -1) {
            // Ʊ���������ܤ���������������դǤϤʤ�
            if (color[next_v] == cur) return false;

            // �������ꤷ�����ˤ�õ�����ʤ�
            continue;
        }

        // ����ĺ���ο����Ѥ��ơ��Ƶ�Ū��õ��
        // false ���֤äƤ����� false ���֤�
        if (!dfs(G, next_v , 1 - cur)) return false;
    }
    return true;
}

int main() {
    // ĺ�������տ�
    int N, M;
    cin >> N >> M;

    // ��������ϼ���
    Graph G(N);
    for (int i = 0; i < M; ++i) {
        int a, b;
        cin >> a >> b;
        G[a].push_back(b);
        G[b].push_back(a);
    }

    // õ��
    color.assign(N, -1);
    bool is_bipartite = true;
    for (int v = 0; v < N; ++v) {
        if (color[v] != -1) continue; // v ��õ���Ѥߤξ���õ�����ʤ�
        if (!dfs(G, v)) is_bipartite = false;
    }

    if (is_bipartite) cout << "Yes" << endl;
    else cout << "No" << endl;
}
