#include <iostream>
using namespace std;

int GCD(int m, int n) {
    // �١���������
    if (n == 0) return m;

    // �Ƶ��ƤӽФ�
    return GCD(n, m % n);
}

int main() {
    cout << GCD(51, 15) << endl; // 3 �����Ϥ����
    cout << GCD(15, 51) << endl; // 3 �����Ϥ����
}
