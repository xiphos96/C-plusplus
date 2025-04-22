#include <iostream>
#include <vector>
using namespace std;

bool func(int i, int w, const vector<int> &a) {
    // �١���������
    if (i == 0) {
        if (w == 0) return true;
        else return false;
    }

    // a[i - 1] �����Фʤ����
    if (func(i - 1, w, a)) return true;

    // a[i - 1] ��־��
    if (func(i - 1, w - a[i - 1], a)) return true;

    // �ɤ���� false �ξ��� false
    return false;
}

int main() {
    // ����
    int N, W;
    cin >> N >> W;
    vector<int> a(N);
    for (int i = 0; i < N; ++i) cin >> a[i];

    // �Ƶ�Ū�˲�
    if (func(N, W, a)) cout << "Yes" << endl;
    else cout << "No" << endl;
}
