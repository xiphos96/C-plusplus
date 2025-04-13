#include <iostream>
#include <vector>
using namespace std;

// ̵�����ɽ����
const long long INF = 1LL << 60; // ��ʬ�礭���ͤ��Ѥ��� (�����Ǥ� 2^60)

// �դ�ɽ�����������ǤϽŤߤ�ɽ������ long long ���Ȥ���
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
    vector<bool> used(N, false);
    vector<long long> dist(N, INF);
    dist[s] = 0;
    for (int iter = 0; iter < N; ++iter) {
        // �ֻ��ѺѤߡפǤʤ�ĺ���Τ�����dist �ͤ��Ǿ���ĺ����õ��
        long long min_dist = INF;
        int min_v = -1;
        for (int v = 0; v < N; ++v) {
            if (!used[v] && dist[v] < min_dist) {
                min_dist = dist[v];
                min_v = v;
            }
        }

        // �⤷���Τ褦��ĺ�������Ĥ���ʤ���н�λ����
        if (min_v == -1) break;

        // min_v ������Ȥ������դ���¤���
        for (auto e : G[min_v]) {
            chmin(dist[e.to], dist[min_v] + e.w);
        }
        used[min_v] = true; // min_v ��ֻ��ѺѤߡפȤ���
    }

    // ��̽���
    for (int v = 0; v < N; ++v) {
        if (dist[v] < INF) cout << dist[v] << endl;
        else cout << "INF" << endl;
    }
}
