#include <iostream>
#include <vector>
using namespace std;

template<class T> void chmin(T& a, T b) {
    if (a > b) {
        a = b;
    }
}

const long long INF = 1LL << 60; // ��ʬ�礭���ͤȤ��� (�����Ǥ� 2^60)

// ���ϥǡ����ȡ�����Ѥ� DP �ơ��֥�
int N;
vector<long long> h;
vector<long long> dp;

long long rec(int i) {
    // DP ���ͤ���������Ƥ����餽�Τޤޥ꥿����
    if (dp[i] < INF) return dp[i];

    // �١���������: ­�� 0 �Υ����Ȥ� 0
    if (i == 0) return 0;

    // ������ɽ���ѿ��� INF �ǽ��������
    long long res = INF;

    // ­�� i - 1 �����褿���
    chmin(res, rec(i - 1) + abs(h[i] - h[i - 1])); 
    
    // ­�� i - 2 �����褿���
    if (i > 1) {
        chmin(res, rec(i - 2) + abs(h[i] - h[i - 2]));
    }

    // ��̤��⤷�ʤ��顢�֤�
    return dp[i] = res;
}

int main() {
    // ���ϼ������
    cin >> N;
    h.resize(N);
    for (int i = 0; i < N; ++i) cin >> h[i];

    // ����� (�Ǿ�������ʤΤ� INF �˽����)
    dp.assign(N, INF);

    // ����
    cout << rec(N - 1) << endl;
}
