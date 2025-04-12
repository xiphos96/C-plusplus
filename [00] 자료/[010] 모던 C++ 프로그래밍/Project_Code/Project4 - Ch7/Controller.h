#include "Contact.h"
#include "Menu.h"
#include "Owner.h"

class Controller  {
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
    

    // ������ �޴� ����
    void runOwnerMenu();

    // ����ó �޴� ����
    void runContactMenu();

public:
    // ���� �޴� ����
    void runMainMenu();              
    
};