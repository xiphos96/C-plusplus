#include <iostream>
using namespace std;

int func(int N) {
    // �Ƶ��ؿ���ƤӽФ������Ȥ���𤹤�
    cout << "func(" << N << ") ��ƤӽФ��ޤ���" << endl;

    if (N == 0) return 0;

    // �Ƶ�Ū����������ƽ��Ϥ���
    int result = N + func(N - 1);
    cout << N << " �ޤǤ��� = " << result << endl;

    return result;
}

int main() {
    func(5);
}
