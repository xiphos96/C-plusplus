#include <iostream>
#include <vector>
using namespace std;

int main() {
    // ���Ϥ�������
    int N, v;
    cin >> N >> v;
    vector<int> a(N);
    for (int i = 0; i < N; ++i) cin >> a[i];
    
    // ����õ��
    int found_id = -1; // ����ͤ� -1 �ʤɤ��ꤨ�ʤ��ͤ�
    for (int i = 0; i < N; ++i) {
        if (a[i] == v) {
            found_id = i; // ���Ĥ��ä���ź����Ͽ
            break; // �롼�פ�ȴ����
        }
    }
    
    // ��̽��� (-1 �ΤȤ��ϸ��Ĥ���ʤ��ä����Ȥ�ɽ��)
    cout << found_id << endl;
}
