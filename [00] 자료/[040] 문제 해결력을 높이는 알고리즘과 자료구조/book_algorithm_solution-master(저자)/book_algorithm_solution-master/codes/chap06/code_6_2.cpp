#include <iostream>
using namespace std;

// x ���������������ɤ���
bool P(int x) {

}

// P(x) = true �Ȥʤ�Ǿ������� x ���֤�
int binary_search() {
    // P(left) = False, P(right) = True �Ȥʤ�褦��
    int left, right; 
    
    while (right - left > 1) {
        int mid = left + (right - left) / 2;
        if (P(mid)) right = mid;
        else left = mid;
    }
    return right;
}
