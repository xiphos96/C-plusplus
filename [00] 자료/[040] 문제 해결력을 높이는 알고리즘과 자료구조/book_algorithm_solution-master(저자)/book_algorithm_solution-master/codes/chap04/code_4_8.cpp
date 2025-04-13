#include <iostream>
#include <vector>
using namespace std;

// fibo(N) ���������ⲽ��������
vector<long long> memo;

long long fibo(int N) {
    // �١���������
    if (N == 0) return 0;
    else if (N == 1) return 1;

    // ��������å� (���Ǥ˷׻��Ѥߤʤ��������꥿���󤹤�)
    if (memo[N] != -1) return memo[N];

    // �������ⲽ���ʤ��顤�Ƶ��ƤӽФ�
    return memo[N] = fibo(N - 1) + fibo(N - 2);
}

int main() {
    // ��ⲽ������� -1 �ǽ��������
    memo.assign(50, -1);

    // fibo(49) ���Ӥ���
    fibo(49);

    // memo[0], ..., memo[49] ����������Ǽ����Ƥ���
    for (int N = 2; N < 50; ++N) {
        cout << N << " ����: " << memo[N] << endl;
    }
}
