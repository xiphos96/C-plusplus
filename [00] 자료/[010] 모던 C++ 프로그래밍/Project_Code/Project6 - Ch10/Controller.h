#ifndef _CONTROLLER_H_
#define _CONTROLLER_H_

#include "Contact.h"
#include "Menu.h"
#include "Owner.h"
#include "Twitter.h"

class Controller{
private:
    Contact contacts;       // ����ó ����
    Menu    menu;           // �޴�
    Owner   owner;          // ������ ����
    Twitter twitter;        // Ʈ���� ����

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
    

    // Ʈ���� �ȷ��� ��� ����ó ����ȭ
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


    // ������ �޴� ����
    void runOwnerMenu();   

    // ����ó �޴� ����
    void runContactMenu(); 

    // Ʈ���� �޴� ����
    void runTwitterMenu();       

public:
    // ���� �޴� ����
    void runMainMenu();             
};

#endif