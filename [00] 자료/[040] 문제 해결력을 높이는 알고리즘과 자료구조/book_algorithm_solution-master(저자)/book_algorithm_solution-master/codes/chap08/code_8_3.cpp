// �Ρ��� p ��ľ��˥Ρ��� v ����������
void insert(Node* v, Node* p) {
    v->next = p->next;
    p->next = v;
}
