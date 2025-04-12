#ifndef _CONTROLLER_H_
#define _CONTROLLER_H_

#include "Contact.h"
#include "Menu.h"
#include "Owner.h"
#include "Twitter.h"
#include "TwitterContact.h"

class Controller{
private:
    Contact<PersonalContact> contacts;         // ����ó ����
    Contact<TwitterContact>  twitterContacts;  // Ʈ���� ����ó ����
    Menu    menu;       // �޴� 
    Owner   owner;      // ������ ����
    Twitter twitter;    // Ʈ���� ����

    // ������ ���� �Է�
    void inputOwnerInfo();

    // ������ ���� ���
    void printOwnerInfo();

    // ������ ���� ����
    void editOwnerInfo();

    // ������ ���� ���� ����
    void saveOwnerInfo();


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

    // ����ó ���� ����
    void saveScontact();


    // Ʈ���� following ��� ����ó ����ȭ
    void syncTwitter();

    // Ʈ���� Ÿ�Ӷ��� ��ȸ
    void getTwitterTimeline();

    // Ư�� ����� Ʈ���� Ÿ�Ӷ��� ��ȸ
    void getTwitterUserTimeline();

    // �ֱ� ���� �޽��� ��ȸ
    void getTwitterReceivedMessages();

    // �ֱ� �۽� �޽��� ��ȸ
    void getTwitterSentMessages();

    // ���ο� �޽��� ����
    void sendTwitterMessage();

    // Ʈ���� ����ó ��� ��ȸ
    void printTwitterContactList();

    // Ʈ���� ����ó �� ��ȸ
    void printTwitterContactDetail();

    // Ʈ��ó ����ó ���� ����
    void saveTwitterContact();


    // ������ �޴� ����
    void runOwnerMenu();

    // ����ó �޴� ����
    void runContactMenu();

    // Ʈ���� �޴� ����
    void runTwitterMenu();

public:
    // ���� �޴� ����
    void runMainMenu();

    // ������
    Controller();
};

#endif