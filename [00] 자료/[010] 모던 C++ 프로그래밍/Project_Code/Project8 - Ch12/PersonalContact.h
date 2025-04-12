#ifndef _PERSONAL_CONTACT_H_
#define _PERSONAL_CONTACT_H_

#include <iostream>
#include "PersonalInfo.h"

using namespace std;
class PersonalContact : public PersonalInfo  {
protected:
    string phoneNumber;     // ��ȭ��ȣ
    string email;           // �̸���
    string address;         // �ּ�

public:
    // �⺻ ������
    PersonalContact(){}

    // ���� ������
    PersonalContact(PersonalContact &personal);

    // ���� ����ó �Է�
    void input(const string inName, const string inPhoneNumber, const string inEmail, const string inAddress, const string inTwitterAccount = "");

    // ���� ����ó ��������
    void get(string *outName, string *outPhoneNumber, string *outEmail, string *outAddress, string *outTwitterAccount = NULL);

    // ���� ����ó ����
    void edit(const string *inName, const string *inPhoneNumber, const string *inEmail, const string *inAddress, const string *inTwitterAccount = NULL);

    // ���� ����ó ���
    void print();
};

#endif