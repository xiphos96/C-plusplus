#include <iostream>
#include <vector>
using namespace std;

struct Heap {
    vector<int> heap;
    Heap() {}

    // �ҡ��פ��� x ������
    void push(int x) {
        heap.push_back(x); // �Ǹ���������
        int i = (int)heap.size() - 1; // �������줿ĺ���ֹ�
        while (i > 0) {
            int p = (i - 1) / 2; // �Ƥ�ĺ���ֹ�
            if (heap[p] >= x) break; // ��ž���ʤ���н�λ
            heap[i] = heap[p]; // ��ʬ���ͤ�Ƥ��ͤˤ���
            i = p; // ��ʬ�Ͼ�˹Ԥ�
        }
        heap[i] = x; // x �Ϻǽ�Ū�ˤϤ��ΰ��֤ˤ�äƤ���
    }

    // �����ͤ��Τ�
    int top() {
        if (!heap.empty()) return heap[0];
        else return -1;
    }

    // �����ͤ���
    void pop() {
        if (heap.empty()) return;
        int x = heap.back(); // ĺ���ˤ�äƤ�����
        heap.pop_back();
        int i = 0; // ������ߤ��Ƥ���
        while (i * 2 + 1 < (int)heap.size()) {
            // ��ĺ��Ʊ�Τ���Ӥ����礭������ child1 �Ȥ���
            int child1 = i * 2 + 1, child2 = i * 2 + 2;
            if (child2 < (int)heap.size()
                && heap[child2] > heap[child1]) {
                child1 = child2;
            }
            if (heap[child1] <= x) break; // ��ž���ʤ���н�λ
            heap[i] = heap[child1]; // ��ʬ���ͤ��ĺ�����ͤˤ���
            i = child1; // ��ʬ�ϲ��˹Ԥ�
        }
        heap[i] = x; // x �Ϻǽ�Ū�ˤϤ��ΰ��֤ˤ�äƤ���
    }
};

int main() {
    Heap h;
    h.push(5), h.push(3), h.push(7), h.push(1);

    cout << h.top() << endl; // 7
    h.pop();
    cout << h.top() << endl; // 5

    h.push(11);
    cout << h.top() << endl; // 11
}
