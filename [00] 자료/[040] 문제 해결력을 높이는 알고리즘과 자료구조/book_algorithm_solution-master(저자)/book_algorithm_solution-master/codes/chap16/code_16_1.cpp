#include <iostream>
#include <vector>
using namespace std;

// ����դ�ɽ����¤��
struct Graph {
    // �դ�ɽ����¤��
    // rev: ���� (to, from) �� G[to] ����ǲ����ܤ����Ǥ�
    // cap: �� (from, to) ������
    struct Edge {
        int rev, from, to, cap;
        Edge(int r, int f, int t, int c) :
            rev(r), from(f), to(t), cap(c) {}
    };

    // ���ܥꥹ��
    vector<vector<Edge>> list;

    // N: ĺ����
    Graph(int N = 0) : list(N) { }

    // ����դ�ĺ��������
    size_t size() {
        return list.size();
    }
    
    // Graph ���󥹥��󥹤� G �Ȥ��ơ�
    // G.list[v] �� G[v] �Ƚ񤱤�褦�ˤ��Ƥ���
    vector<Edge> &operator [] (int i) {
        return list[i];
    }

    // �� e = (u, v) �ε��� (v, u) ���������
    Edge& redge(const Edge &e) {
        return list[e.to][e.rev];
    }

    // �� e = (u, v) ��ή�� f �Υե���ή��
    // e = (u, v) ��ή�̤� f ������������
    // ���ΤȤ����� (v, u) ��ή�̤����䤹
    void run_flow(Edge &e, int f) {
        e.cap -= f;
        redge(e).cap += f;
    }

    // ĺ�� from ����ĺ�� to ������ cap ���դ�ĥ��
    // ���ΤȤ� to ���� from �ؤ����� 0 ���դ�ĥ�äƤ���
    void addedge(int from, int to, int cap) {
        int fromrev = (int)list[from].size();
        int torev = (int)list[to].size();
        list[from].push_back(Edge(torev, from, to, cap));
        list[to].push_back(Edge(fromrev, to, from, 0));
    }
};

struct FordFulkerson {
    static const int INF = 1 << 30; // ̵�����ɽ���ͤ�Ŭ�ڤ�
    vector<int> seen;

    FordFulkerson() { }

    // ��;����վ�� s-t �ѥ��򸫤Ĥ��� (����ͥ��õ��)
    // �֤��ͤ� s-t �ѥ�������̤κǾ��� (���Ĥ���ʤ��ä��� 0)
    // f: s ���� v ����ã���������γ��դ����̤κǾ���
    int fodfs(Graph &G, int v, int t, int f) {
        // ��ü t ����ã������꥿����
        if (v == t) return f;

        // ����ͥ��õ��
        seen[v] = true;
        for (auto &e : G[v]) {
            if (seen[e.to]) continue;

            // ���� 0 ���դϼºݤˤ�¸�ߤ��ʤ�
            if (e.cap == 0) continue;

            // s-t �ѥ���õ��
            // ���Ĥ��ä��� flow �ϥѥ���κǾ�����
            // ���Ĥ���ʤ��ä��� f = 0
            int flow = fodfs(G, e.to, t, min(f, e.cap));

            // s-t �ѥ������Ĥ���ʤ��ä��鼡�դ�
            if (flow == 0) continue;

            // �� e ������ flow �Υե���ή��
            G.run_flow(e, flow);

            // s-t �ѥ��򸫤Ĥ�����ѥ���Ǿ����̤��֤�
            return flow;
        }

        // s-t �ѥ������Ĥ���ʤ��ä����Ȥ򼨤�
        return 0;
    }

    // ����� G �� s-t �֤κ���ή�̤����
    // �������꥿������� G �ϻ�;����դˤʤ�
    int solve(Graph &G, int s, int t) {
        int res = 0;

        // ��;����դ� s-t �ѥ����ʤ��ʤ�ޤ�ȿ��
        while (true) {
            seen.assign((int)G.size(), 0);
            int flow = fodfs(G, s, t, INF);

            // s-t �ѥ������Ĥ���ʤ��ä��齪λ
            if (flow == 0) return res;

            // ������û�
            res += flow;
        }

        // no reach
        return 0;
    }
};

int main() {
    // ����դ�����
    // N: ĺ������M: �տ�
    int N, M;
    cin >> N >> M;
    Graph G(N);
    for (int i = 0; i < M; ++i) {
        int u, v, c;
        cin >> u >> v >> c;

        // ���� c ���� (u, v) ��ĥ��
        G.addedge(u, v, c);
    }

    // �ե����ɡ��ե��륫������ˡ
    FordFulkerson ff;
    int s = 0, t = N - 1;
    cout << ff.solve(G, s, t) << endl;
}
