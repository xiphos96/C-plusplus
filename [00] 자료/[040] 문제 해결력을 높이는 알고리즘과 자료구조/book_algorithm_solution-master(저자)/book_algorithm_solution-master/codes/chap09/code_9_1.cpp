#include <iostream>
#include <vector>
using namespace std;
const int MAX = 100000; // �����å�����κ��祵����

int st[MAX]; // �����å���ɽ������
int top = 0; // �����å�����Ƭ��ɽ��ź��

// �����å�����������
void init() {
    top = 0; // �����å���ź���������֤�
}

// �����å��������ɤ�����Ƚ�ꤹ��
bool isEmpty() {
    return (top == 0); // �����å��������� 0 ���ɤ���
}

// �����å������դ��ɤ�����Ƚ�ꤹ��
bool isFull() {
    return (top == MAX); // �����å��������� MAX ���ɤ���
}

// push
void push(int x) {
    if (isFull()) {
        cout << "error: stack is full." << endl;
        return;
    }
    st[top] = x; // x ���Ǽ����
    ++top; // top ��ʤ��
}

// pop
int pop() {
    if (isEmpty()) {
        cout << "error: stack is empty." << endl;
        return -1;
    }
    --top; // top ��ǥ�����Ȥ���
    return st[top]; // top �ΰ��֤ˤ������Ǥ��֤�
}

int main() {
    init(); // �����å�������

    push(3); // �����å��� 3 ���������� {} -> {3}
    push(5); // �����å��� 5 ���������� {3} -> {3, 5}
    push(7); // �����å��� 7 ���������� {3, 5} -> {3, 5, 7}

    cout << pop() << endl; // {3, 5, 7} -> {3, 5} �� 7 �����
    cout << pop() << endl; // {3, 5} -> {3} �� 5 �����

    push(9); // ������ 9 ���������� {3} -> {3, 9}
}
