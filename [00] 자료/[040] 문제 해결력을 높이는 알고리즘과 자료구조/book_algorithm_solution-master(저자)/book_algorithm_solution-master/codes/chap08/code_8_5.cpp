struct Node {
    Node *prev, *next;
    string name; // �Ρ��ɤ��տ路�Ƥ�����

    Node(string name_ = "") :
    prev(NULL), next(NULL), name(name_) { }
};
