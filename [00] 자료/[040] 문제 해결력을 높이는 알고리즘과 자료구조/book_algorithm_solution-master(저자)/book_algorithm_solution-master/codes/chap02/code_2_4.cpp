#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

// 2 �� (x1, y1) �� (x2, y2) �Ȥε�Υ�����ؿ�
double calc_dist(double x1, double y1, double x2, double y2) {
    return sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));
}

int main() {
    // ���ϥǡ�����������
    int N; cin >> N;
    vector<double> x(N), y(N);
    for (int i = 0; i < N; ++i) cin >> x[i] >> y[i];
    
    // �����ͤ򡢽�ʬ�礭���ͤǽ�������Ƥ���
    double minimum_dist = 100000000.0;
    
    // õ������
    for (int i = 0; i < N; ++i) {
        for (int j = i + 1; j < N; ++j) {
            // (x[i], y[i]) �� (x[j], y[j]) �Ȥε�Υ
            double dist_i_j = calc_dist(x[i], y[i], x[j], y[j]);
            
            // ����Ǿ��� minimum_dist �� dist_i_j ����٤�
            if (dist_i_j < minimum_dist) {
                minimum_dist = dist_i_j;
            }
        }
    }
    
    // ��������Ϥ���
    cout << minimum_dist << endl;
}
