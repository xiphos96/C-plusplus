#include <iostream>
#include <vector>
#include <queue>
using namespace std;
using Graph = vector<vector<int>>;

// ����: ����� G �ȡ�õ���λ��� s
// ����: s �����ĺ���ؤκ�ûϩĹ��ɽ������
vector<int> BFS(const Graph &G, int s) {
    int N = (int)G.size(); // ĺ����
    vector<int> dist(N, -1); // ��ĺ�����̤ˬ��פ˽����
    queue<int> que;

    // ������ (ĺ�� s ����ĺ���Ȥ���)
    dist[s] = 0;
    que.push(s); // s ������ĺ���ˤ���

    // BFS ���� (���塼�����ˤʤ�ޤ�õ����Ԥ�)
    while (!que.empty()) {
        int v = que.front(); // ���塼������Ƭĺ������Ф�
        que.pop();

        // v ���餿�ɤ��ĺ���򤹤٤�Ĵ�٤�
        for (int x : G[v]) {
            // ���Ǥ�ȯ���Ѥߤ�ĺ����õ�����ʤ�
            if (dist[x] != -1) continue; 

            // ��������ĺ�� x �ˤĤ��Ƶ�Υ����򹹿����ƥ��塼������
            dist[x] = dist[v] + 1;
            que.push(x);
        }
    }
    return dist;
}

int main() {
    // ĺ�������տ�
    int N, M;
    cin >> N >> M;

    // ��������ϼ��� (�����Ǥ�̵������դ�����)
    Graph G(N);
    for (int i = 0; i < M; ++i) {
        int a, b;
        cin >> a >> b;
        G[a].push_back(b);
        G[b].push_back(a);
    }

    // ĺ�� 0 ������Ȥ��� BFS
    vector<int> dist = BFS(G, 0);

    // ��̽��� (��ĺ����ĺ�� 0 ����ε�Υ�򸫤�)
    for (int v = 0; v < N; ++v) cout << v << ": " << dist[v] << endl;
}
