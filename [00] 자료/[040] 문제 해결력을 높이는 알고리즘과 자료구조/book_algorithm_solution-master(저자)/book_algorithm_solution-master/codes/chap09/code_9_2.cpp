#include <iostream>
#include <vector>
using namespace std;
const int MAX = 100000; // ���塼����κ��祵����

int qu[MAX]; // ���塼��ɽ������
int tail = 0, head = 0; // ���塼�����Ƕ�֤�ɽ���ѿ�

// ���塼����������
void init() {
    head = tail = 0;
}

// ���塼�������ɤ�����Ƚ�ꤹ��
bool isEmpty() {
    return (head == tail);
}

// ���塼�����դ��ɤ�����Ƚ�ꤹ��
bool isFull() {
    return (head == (tail + 1) % MAX);
}

// enqueue
void enqueue(int x) {
    if (isFull()) {
        cout << "error: queue is full." << endl;
        return;
    }
    qu[tail] = x;
    ++tail;
    if (tail == MAX) tail = 0; // ��󥰥Хåե��ν�ü���褿�� 0 ��
}

// dequeue
int dequeue() {
    if (isEmpty()) {
        cout << "error: queue is empty." << endl;
        return -1;
    }
    int res = qu[head];
    ++head;
    if (head == MAX) head = 0; // ��󥰥Хåե��ν�ü���褿�� 0 ��
    return res;
}

int main() {
    init(); // ���塼������

    enqueue(3); // ���塼�� 3 ���������� {} -> {3}
    enqueue(5); // ���塼�� 5 ���������� {3} -> {3, 5}
    enqueue(7); // ���塼�� 7 ���������� {3, 5} -> {3, 5, 7}

    cout << dequeue() << endl; // {3, 5, 7} -> {5, 7} �� 3 �����
    cout << dequeue() << endl; // {5, 7} -> {7} �� 5 �����

    enqueue(9); // ������ 9 ���������� {7} -> {7, 9}
}
