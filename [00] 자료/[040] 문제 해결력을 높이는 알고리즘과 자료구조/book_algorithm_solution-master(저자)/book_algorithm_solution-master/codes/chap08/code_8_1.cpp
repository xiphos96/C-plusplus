#include <iostream>
#include <vector>
using namespace std;

int main() {
    vector<int> a = {4, 3, 12, 7, 11, 1, 9, 8, 14, 6};

    // 0 ���ܤ����Ǥ���� (4)
    cout << a[0] << endl;

    // 2 ���ܤ����Ǥ���� (12)
    cout << a[2] << endl;

    // 2 ���ܤ����Ǥ� 5 �˽񤭴�����
    a[2] = 5;

    // 2 ���ܤ����Ǥ���� (5)
    cout << a[2] << endl;
}
