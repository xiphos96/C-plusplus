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
    bool exist = false;   // ����ͤ� false ��
    for (int i = 0; i < N; ++i) {
        if (a[i] == v) {
            exist = true;  // ���Ĥ��ä���ե饰��Ω�Ƥ�
        }
    }
    
    // ��̽���
    if (exist) cout << "Yes" << endl;
    else cout << "No" << endl;
}
