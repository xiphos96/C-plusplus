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
        if (seen[next_v]) continue; // next_v ��õ���Ѥ��ä��饹�롼
        dfs(G, next_v); // �Ƶ�Ū��õ��
    }
}

int main() {
    // ĺ�������տ���s �� t
    int N, M, s, t;
    cin >> N >> M >> s >> t;

    // ��������ϼ���
    Graph G(N);
    for (int i = 0; i < M; ++i) {
        int a, b;
        cin >> a >> b;
        G[a].push_back(b);
    }

    // ĺ�� s �򥹥����ȤȤ���õ��
    seen.assign(N, false); // ��ĺ�����̤ˬ��פ˽����
    dfs(G, s);

    // t �ˤ��ɤ��失�뤫�ɤ���
    if (seen[t]) cout << "Yes" << endl;
    else cout << "No" << endl;
}
