#include <iostream>
#include <vector>
using namespace std;

// �����ǤϽŤߤ�ɽ������ long long ���Ȥ���
struct Edge {
    int to; // ����ĺ���ֹ�
    long long w; // �Ť�
    Edge(int to, long long w) : to(to), w(w) {}
};
    
// ��ĺ�������ܥꥹ�Ȥ��ս����ɽ��
using Graph = vector<vector<Edge>>;

int main() {
    // ĺ�������տ�
    int N, M;
    cin >> N >> M;

    // �����
    Graph G(N);
    for (int i = 0; i < M; ++i) {
        int a, b;
        long long w;
        cin >> a >> b >> w;
        G[a].push_back(Edge(b, w));
    }
}
