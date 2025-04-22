#include <iostream>
#include <string>
#include <vector>
using namespace std;

// Ϣ��ꥹ�ȤγƥΡ��ɤ�ɽ����¤��
struct Node {
    Node *prev, *next;
    string name; // �Ρ��ɤ��տ路�Ƥ�����

    Node(string name_ = "") :
    prev(NULL), next(NULL), name(name_) { }
};

// ��ʼ��ɽ���Ρ��ɤ򥰥��Х��ΰ���֤��Ƥ���
Node* nil;

// �����
void init() {
    nil = new Node();
    nil->prev = nil; 
    nil->next = nil;
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
void insert(Node* v, Node* p = nil) {
    v->next = p->next;
    p->next->prev = v;
    p->next = v;
    v->prev = p;
}

// �Ρ��� v ��������
void erase(Node *v) {
    if (v == nil) return; // v ����ʼ�ξ��ϲ��⤷�ʤ�
    v->prev->next = v->next;
    v->next->prev = v->prev;
    delete v; // �������
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

    // Ϣ��ꥹ�Ⱥ���: �ƥΡ��ɤ���������Ϣ��ꥹ�Ȥ���Ƭ���������Ƥ���
    Node *watanabe;
    for (int i = 0; i < (int)names.size(); ++i) {
        // �Ρ��ɤ��������
        Node* node = new Node(names[i]);

        // ���������Ρ��ɤ�Ϣ��ꥹ�Ȥ���Ƭ����������
        insert(node);

        // �����աץΡ��ɤ��ݻ����Ƥ���
        if (names[i] == "watanabe") watanabe = node;
    }

    // �����աץΡ��ɤ�������
    cout << "before: ";
    printList(); // ����������
    erase(watanabe);
    cout << "after: ";
    printList(); // ���������
}
