#include <iostream>
#include <vector>
using namespace std;

// Union-Find
struct UnionFind {
    vector<int> par, siz;

    UnionFind(int n) : par(n, -1) , siz(n, 1) { }

    // �������
    int root(int x) {
        if (par[x] == -1) return x;
        else return par[x] = root(par[x]);
    }

    // x �� y ��Ʊ�����롼�פ�°���뤫�ɤ��� (�������פ��뤫�ɤ���)
    bool issame(int x, int y) {
        return root(x) == root(y);
    }

    // x ��ޤ॰�롼�פ� y ��ޤ॰�롼�פȤ�ʻ�礹��
    bool unite(int x, int y) {
        x = root(x), y = root(y);
        if (x == y) return false; 
        if (siz[x] < siz[y]) swap(x, y);
        par[y] = x;
        siz[x] += siz[y];
        return true;
    }

    // x ��ޤ॰�롼�פΥ�����
    int size(int x) {
        return siz[root(x)];
    }
};

int main() {
    // ĺ�������տ�
    int N, M;
    cin >> N >> M;

    // Union-Find �����ǿ� N �ǽ����
    UnionFind uf(N);

    // ���դ��Ф������
    for (int i = 0; i < M; ++i) {
        int a, b;
        cin >> a >> b;
        uf.unite(a, b); // a ��ޤ॰�롼�פ� b ��ޤ॰�롼�פ�ʻ�礹��
    }

    // ����
    int res = 0;
    for (int x = 0; x < N; ++x) {
        if (uf.root(x) == x) ++res;
    }
    cout << res << endl;
}
