#include <iostream>
#include <vector>
using namespace std;

int main() {
    // ���ϼ������
    int N, W;
    cin >> N >> W;
    vector<int> a(N);
    for (int i = 0; i < N; ++i) cin >> a[i];
    
    // bit �� 2^N �̤����ʬ�������Τ�ư��
    bool exist = false;
    for (int bit = 0; bit < (1 << N); ++bit)
    {
        int sum = 0; // ��ʬ����˴ޤޤ�����Ǥ���
        for (int i = 0; i < N; ++i) {
            // i ���ܤ����� a[i] ����ʬ����˴ޤޤ�Ƥ��뤫�ɤ���
            if (bit & (1 << i)) { 
                sum += a[i];
            }
        }
        
        // sum �� W �˰��פ��뤫�ɤ���
        if (sum == W) exist = true;
    }
    
    if (exist) cout << "Yes" << endl;
    else cout << "No" << endl;
}
