#include <iostream>
using namespace std;

int fibo(int N) {
    cout << "fibo(" << N << ") ��ƤӽФ��ޤ���" << endl;
    
    // �١���������
    if (N == 0) return 0;
    else if (N == 1) return 1;

    // �Ƶ�Ū����������ƽ��Ϥ���
    int result = fibo(N - 1) + fibo(N - 2);
    cout << N << " ���� = " << result << endl;

    return result;
}

int main() {
    fibo(6);
}
