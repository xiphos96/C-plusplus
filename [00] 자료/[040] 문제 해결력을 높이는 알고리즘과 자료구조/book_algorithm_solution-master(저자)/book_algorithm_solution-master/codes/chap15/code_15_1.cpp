#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Union-Find
struct UnionFind {
    vector<int> par, siz;

    // �����
    UnionFind(int n) : par(n, -1) , siz(n, 1) { }
    
    // �������
    int root(int x) {
        if (par[x] == -1) return x; // x �����ξ��� x ���֤�
        else return par[x] = root(par[x]);
    }

    // x �� y ��Ʊ�����롼�פ�°���뤫�ɤ��� (�������פ��뤫�ɤ���)
    bool issame(int x, int y) {
        return root(x) == root(y);
    }

    // x ��ޤ॰�롼�פ� y ��ޤ॰�롼�פȤ�ʻ�礹��
    bool unite(int x, int y) {
        // x, y �򤽤줾�캬�ޤǰ�ư����
        x = root(x);
        y = root(y);

        // ���Ǥ�Ʊ�����롼�פΤȤ��ϲ��⤷�ʤ�
        if (x == y) return false; 

        // union by size (y ¦�Υ��������������ʤ�褦�ˤ���)
        if (siz[x] < siz[y]) swap(x, y);

        // y �� x �λҤȤ���
        par[y] = x;
        siz[x] += siz[y];
        return true;
    }

    // x ��ޤ॰�롼�פΥ�����
    int size(int x) {
        return siz[root(x)];
    }
};

// �� e = (u, v) �� {w(e), {u, v}} ��ɽ��
using Edge = pair<int, pair<int,int>>;

int main() {
    // ����
    int N, M; // ĺ�������տ�
    cin >> N >> M;
    vector<Edge> edges(M); // �ս���
    for (int i = 0; i < M; ++i) {
        int u, v, w; // w �ϽŤ�
        cin >> u >> v >> w;
        edges[i] = Edge(w, make_pair(u, v));
    }

    // ���դ��դνŤߤ���������˥����Ȥ���
    // pair �ϥǥե���Ȥ� (�������, ��������) �μ�������
    sort(edges.begin(), edges.end());

    // ���饹����ˡ
    long long res = 0;
    UnionFind uf(N);
    for (int i = 0; i < M; ++i) {
        int w = edges[i].first;
        int u = edges[i].second.first;
        int v = edges[i].second.second;

        // �� (u, v) ���ɲäˤ�äƥ������뤬���������Ȥ����ɲä��ʤ�
        if (uf.issame(u, v)) continue;

        // �� (u, v) ���ɲä���
        res += w;
        uf.unite(u, v);
    }
    cout << res << endl;
}
