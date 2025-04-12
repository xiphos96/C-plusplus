#include <iostream>
#include "PersonalContact.h"

class Contact  {
private:
    PersonalContact contactInfo[100];    // 100���� ����ó ���� ������ �迭
    int numberOfContact;                 // ���� ����� ����ó ����

public:
    // ������ - ��� �ʱ�ȭ�� ���� ����
    Contact();

    // ����ó ���� �Է�
    void inputContact(char *name, char *phoneNumber=NULL, char *email=NULL, char *address=NULL);

    // ����ó ��ü ��� ��ȸ
    void printContactList();

    // ����ó �� ��ȸ - index 
    void printContact(int index);

    // ����ó �� ��ȸ - �̸� (�Լ� �����ε�)
    void printContact(char *inName);

    // ����ó ����
    void editContactByIndex(int index, char *name, char *phoneNumber=NULL, char *email=NULL, char *address=NULL);
    
    // ����ó ����
    void copyContact(int index);
    
    // ����ó ����
    void removeContactByIndex(int index);
};
