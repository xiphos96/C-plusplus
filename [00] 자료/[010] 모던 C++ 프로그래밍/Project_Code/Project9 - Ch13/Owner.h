#ifndef _OWNER_H_
#define _OWNER_H_

#include <iostream>
#include <string>
#include "PersonalInfo.h"

using namespace std;
class Owner : public PersonalInfo  {
protected:
    string twitterAccount;  // Ʈ���� ���̵�
    string phoneNumber;     // ��ȭ��ȣ
    string email;           // �̸���
    string address;         // �ּ�

public:
    // ������
    Owner();

    // ������ ���� �Է�
    void input(const string inName, const string inPhoneNumber, const string inEmail, const string inAddress, const string inTwitterAccount = "");

    // ������ ���� ��������
    void get(string *outName, string *outPhoneNumber, string *outEmail, string *outAddress, string *outTwitterAccount = NULL);

    // ������ ���� ����
    void edit(const string *inName, const string *inPhoneNumber, const string *inEmail, const string *inAddress, const string *inTwitterAccount);

    // ������ ���� ���
    void print();

    // ������ ������ ���Ϸ� ������
    void save();

    // ������ ������ ���Ͽ��� �ҷ���
    void load();
};

#endif