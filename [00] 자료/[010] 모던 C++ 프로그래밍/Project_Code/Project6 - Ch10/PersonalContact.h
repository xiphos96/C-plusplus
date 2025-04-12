#ifndef _PERSONAL_CONTACT_H_
#define _PERSONAL_CONTACT_H_

#include <iostream>
#include "PersonalInfo.h"

using namespace std;
class PersonalContact : public PersonalInfo  {
public:
    // �⺻ ������
    PersonalContact(){}

    // ���� ������
    PersonalContact(PersonalContact &personal);

    // �������� �Է�
    void input(const string inName, const string inPhoneNumber, const string inEmail, const string inAddress, const string inTwitterAccount = "");

    // �������� ��������
    void get(string *outName, string *outPhoneNumber, string *outEmail, string *outAddress, string *outTwitterAccount = NULL) ;

    // �������� ����
    void edit(const string *inName, const string *inPhoneNumber, const string *inEmail, const string *inAddress, const string *inTwitterAccount = NULL);
};

#endif