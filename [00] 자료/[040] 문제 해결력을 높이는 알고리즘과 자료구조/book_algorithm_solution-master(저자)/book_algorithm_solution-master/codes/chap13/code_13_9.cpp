#include <iostream>
#include <vector>
using namespace std;
using Graph = vector<vector<int>>;

// �ھ��õ��
vector<int> depth;
vector<int> subtree_size;
void dfs(const Graph &G, int v, int p = -1, int d = 0) {
    depth[v] = d;
    for (auto c : G[v]) {
        if (c == p) continue; // õ�����������ص�ή����Τ��ɤ�
        dfs(G, c, v, d + 1);
    }

    // ���꤬�����ˡ���ʬ�ڥ����������
    subtree_size[v] = 1; // ��ʬ����
    for (auto c : G[v]) {
        if (c == p) continue;

        // ��ĺ���򺬤Ȥ�����ʬ���Υ�������û�����
        subtree_size[v] += subtree_size[c]; 
    }
}

int main() {
    // ĺ���� (�ڤʤΤ��տ��� N - 1 �ǳ���)
    int N; 
    cin >> N;

    // ��������ϼ���
    Graph G(N);
    for (int i = 0; i < N - 1; ++i) {
        int a, b;
        cin >> a >> b;
        G[a].push_back(b);
        G[b].push_back(a);
    }

    // õ��
    int root = 0; // ����ĺ�� 0 �򺬤Ȥ���
    depth.assign(N, 0);
    subtree_size.assign(N, 0);
    dfs(G, root);

    // ���
    for (int v = 0; v < N; ++v) {
        cout << v << ": depth = " << depth[v]
        << ", subtree_size = " << subtree_size[v] << endl;
    }
}
