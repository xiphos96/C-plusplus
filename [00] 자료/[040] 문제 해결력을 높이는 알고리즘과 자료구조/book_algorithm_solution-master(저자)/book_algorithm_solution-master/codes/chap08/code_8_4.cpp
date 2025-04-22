#include <iostream>
#include <string>
#include <vector>
using namespace std;

// Ϣ��ꥹ�ȤγƥΡ��ɤ�ɽ����¤��
struct Node {
    Node* next; // �����ɤΥΡ��ɤ�ؤ���
    string name; // �Ρ��ɤ��տ路�Ƥ�����

    Node(string name_ = "") : next(NULL), name(name_) { }
};

// ��ʼ��ɽ���Ρ��ɤ򥰥��Х��ΰ���֤��Ƥ���
Node* nil;

// �����
void init() {
    nil = new Node();
    nil->next = nil; // ������֤Ǥ� nil �� nil ��ؤ��褦�ˤ���
}

// Ϣ��ꥹ�Ȥ���Ϥ���
void printList() {
    Node* cur = nil->next; // ��Ƭ�����ȯ
    for (; cur != nil; cur = cur->next) {
        cout << cur->name << " -> ";
    }
    cout << endl;
}

// �Ρ��� p ��ľ��˥Ρ��� v ����������
// �Ρ��� p �Υǥե���Ȱ����� nil �Ȥ��Ƥ���
// ���Τ��� insert(v) ��ƤӽФ����ϡ��ꥹ�Ȥ���Ƭ�ؤ�������ɽ��
void insert(Node* v, Node* p = nil) {
    v->next = p->next;
    p->next = v;
}

int main() {
    // �����
    init();

    // ��ꤿ���Ρ��ɤ�̾���ΰ���
    // �Ǹ����ΥΡ��� (�ֻ��ܡ�) �������������뤳�Ȥ����
    vector<string> names = {"yamamoto",
                            "watanabe",
                            "ito",
                            "takahashi",
                            "suzuki",
                            "sato"};

    // �ƥΡ��ɤ��������ơ�Ϣ��ꥹ�Ȥ���Ƭ���������Ƥ���
    for (int i = 0; i < (int)names.size(); ++i) {
        // �Ρ��ɤ��������
        Node* node = new Node(names[i]);

        // ���������Ρ��ɤ�Ϣ��ꥹ�Ȥ���Ƭ����������
        insert(node);

        // �ƥ��ƥåפ�Ϣ��ꥹ�Ȥ��ͻҤ���Ϥ���
        cout << "step " << i << ": ";
        printList();
    }
}
