#include <iostream>
#include <vector>
#include <queue>
using namespace std;

// ̵�����ɽ���� (�����Ǥ� 2^60 �Ȥ���)
const long long INF = 1LL << 60;

// �դ�ɽ�����������ǤϽŤߤ�ɽ������ long long ���Ȥ��ޤ�
struct Edge {
    int to; // ����ĺ���ֹ�
    long long w; // �Ť�
    Edge(int to, long long w) : to(to), w(w) {}
};

// �Ť��դ�����դ�ɽ����
using Graph = vector<vector<Edge>>;

// ���¤�»ܤ���ؿ�
template<class T> bool chmin(T& a, T b) {
    if (a > b) {
        a = b;
        return true;
    }
    else return false;
}

int main() {
    // ĺ�������տ�������
    int N, M, s;
    cin >> N >> M >> s;

    // �����
    Graph G(N);
    for (int i = 0; i < M; ++i) {
        int a, b, w;
        cin >> a >> b >> w;
        G[a].push_back(Edge(b, w));
    }

    // ���������ȥ�ˡ
    vector<long long> dist(N, INF);
    dist[s] = 0;

    // (d[v], v) �Υڥ������ǤȤ����ҡ��פ���
    priority_queue<pair<long long, int>,
                   vector<pair<long long, int>>,
                   greater<pair<long long, int>>> que;
    que.push(make_pair(dist[s], s));

    // ���������ȥ�ˡ��ȿ���򳫻�
    while (!que.empty()) {
        // v: ���ѺѤߤǤʤ�ĺ���Τ��� d[v] ���Ǿ���ĺ��
        // d: v ���Ф��륭����
        int v = que.top().second;
        long long d = que.top().first;
        que.pop();

        // d > dist[v] �ϡ�(d, v) �����ߤǤ��뤳�Ȥ��̣����
        if (d > dist[v]) continue; 

        // ĺ�� v ������Ȥ������դ����
        for (auto e : G[v]) {
            if (chmin(dist[e.to], dist[v] + e.w)) {
                // ����������ʤ�ҡ��פ˿���������
                que.push(make_pair(dist[e.to], e.to)); 
            }
        }
    }
    
    // ��̽���
    for (int v = 0; v < N; ++v) {
        if (dist[v] < INF) cout << dist[v] << endl;
        else cout << "INF" << endl;
    }
}
