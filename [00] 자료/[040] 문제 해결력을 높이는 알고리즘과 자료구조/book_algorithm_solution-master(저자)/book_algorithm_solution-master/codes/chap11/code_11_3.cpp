#include <iostream>
#include <vector>
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

int main() {
    UnionFind uf(7); // {0}, {1}, {2}, {3}, {4}, {5}, {6}

    uf.unite(1, 2); // {0}, {1, 2}, {3}, {4}, {5}, {6}
    uf.unite(2, 3); // {0}, {1, 2, 3}, {4}, {5}, {6}
    uf.unite(5, 6); // {0}, {1, 2, 3}, {4}, {5, 6}
    cout << uf.issame(1, 3) << endl; // True
    cout << uf.issame(2, 5) << endl; // False

    uf.unite(1, 6); // {0}, {1, 2, 3, 5, 6}, {4}
    cout << uf.issame(2, 5) << endl; // True
}
