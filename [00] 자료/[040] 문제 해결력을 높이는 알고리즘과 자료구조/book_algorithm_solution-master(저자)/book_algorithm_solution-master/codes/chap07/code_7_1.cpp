#include <iostream>
#include <vector>
using namespace std;

// ������ζ��
const vector<int> value = {500, 100, 50, 10, 5, 1};

int main() {
    // ����
    int X;
    vector<int> a(6);
    cin >> X;
    for (int i = 0; i < 6; ++i) cin >> a[i];

    // ����ˡ
    int result = 0;
    for (int i = 0; i < 6; ++i) {
        // ������¤��ʤ��������
        int add = X / value[i];

        // ������¤��θ
        if (add > a[i]) add = a[i];

        // �Ĥ��ۤ���ơ������������û�����
        X -= value[i] * add;
        result += add;
    }
    cout << result << endl;
}
