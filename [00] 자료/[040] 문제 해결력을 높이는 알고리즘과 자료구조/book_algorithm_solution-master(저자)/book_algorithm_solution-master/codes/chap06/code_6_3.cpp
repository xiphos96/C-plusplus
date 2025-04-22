#include <iostream>
using namespace std;

int main() {
    cout << "Start Game!" << endl;

    // A ����ο��θ����ɽ����֤�[left, right) ��ɽ��
    int left = 20, right = 36;

    // A ����ο��� 1 �Ĥ˹ʤ�ʤ������Ϸ����֤�
    while (right - left > 1) {
        int mid = left + (right - left) / 2; // ��֤ο�����

        // mid �ʾ夫��ʹ���ơ������� yes/no �Ǽ������
        cout << "Is the age less than " << mid << " ? (yes / no)" << endl;
        string ans;
        cin >> ans;

        // �����α����ơ����뤦������ϰϤ�ʤ�
        if (ans == "yes") right = mid;
        else left = mid;
    }

    // ���Х����Ƥ롪
    cout << "The age is " << left << "!" << endl;
}
