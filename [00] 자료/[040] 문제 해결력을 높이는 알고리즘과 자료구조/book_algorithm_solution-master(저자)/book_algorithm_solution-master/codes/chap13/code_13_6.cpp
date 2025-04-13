#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
using Graph = vector<vector<int>>;

// �ȥݥ����륽���Ȥ���
vector<bool> seen;
vector<int> order; // �ȥݥ����륽���Ƚ��ɽ��
void rec(const Graph &G, int v) {
    seen[v] = true;
    for (auto next_v : G[v]) {
        if (seen[next_v]) continue; // ���Ǥ�ˬ��Ѥߤʤ�õ�����ʤ�
        rec(G, next_v);
    }

    // v-out ��Ͽ����
    order.push_back(v);
}

int main() {
    int N, M;
    cin >> N >> M; // ĺ�����Ȼ޿�
    Graph G(N); // ĺ���� N �Υ����
    for (int i = 0; i < M; ++i) {
        int a, b;
        cin >> a >> b;
        G[a].push_back(b);
    }

    // õ��
    seen.assign(N, false); // ������֤Ǥ���ĺ����̤ˬ��
    order.clear(); // �ȥݥ����륽���Ƚ�
    for (int v = 0; v < N; ++v) {
        if (seen[v]) continue; // ���Ǥ�ˬ��Ѥߤʤ�õ�����ʤ�
        rec(G, v);
    }
    reverse(order.begin(), order.end()); // �ս��

    // ����
    for (auto v : order) cout << v << " -> ";
    cout << endl;
}
