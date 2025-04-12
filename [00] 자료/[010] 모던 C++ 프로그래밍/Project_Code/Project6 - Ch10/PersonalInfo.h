#ifndef _PERSONAL_INFO_H_
#define _PERSONAL_INFO_H_
#include <iostream>
using namespace std;
class PersonalInfo  {
protected:
    string name;               // �̸�
    string phoneNumber;        // ��ȭ��ȣ
    string email;              // �̸���
    string address;            // �ּ�
public:
    // �������� �Է�
    virtual void input(const string inName, const string inPhoneNumber, const string inEmail, const string inAddress, const string inTwitterAccount = "") = 0;

    // �������� ��������
    virtual void get(string *outName, string *outPhoneNumber, string *outEmail, string *outAddress, string *outTwitterAccount = NULL) = 0;

    // �������� ����
    virtual void edit(const string *inName, const string *inPhoneNumber, const string *inEmail, const string *inAddress, const string *inTwitterAccount = NULL) = 0;
};

#endif