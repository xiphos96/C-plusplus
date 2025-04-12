#ifndef _CONTROLLER_H_
#define _CONTROLLER_H_

#include "Contact.h"
#include "Menu.h"
#include "Owner.h"

class Controller{
private:
    Contact contacts;       // ����ó ����
    Menu    menu;           // �޴�
    Owner   owner;          // ������ ����

    // ������ ���� �Է�
    void inputOwnerInfo();

    // ������ ���� ���
    void printOwnerInfo();

    // ������ ���� ����
    void editOwnerInfo();


    // ����ó ���� �Է�
    void addContact();

    // ����ó ��ü ��� ��ȸ
    void printContactList();

    // ����ó �� ��ȸ
    void printContactDetail();

    // ����ó ����
    void editContact();

    // ����ó ����
    void copyContact();

    // ����ó ����
    void removeContact();

    // Ʈ���� ���� ����
    void syncTwitter();

    // ������ �޴� ����
    void runOwnerMenu();

    // ����ó �޴� ����
    void runContactMenu();

public:
    // ���� �޴� ����
    void runMainMenu();
};

#endif