#include "PersonalContact.h"
#include <fstream>

// ���� ������
PersonalContact::PersonalContact(PersonalContact &personal)
{
    name = personal.name;
    phoneNumber = personal.phoneNumber;
    email = personal.email;
    address = personal.address;
}

// ���� ����ó �Է�
void PersonalContact::input(const string inName, const string inPhoneNumber, const string inEmail, const string inAddress, const string inTwitterAccount)
{
    name = inName;
    phoneNumber = inPhoneNumber;
    email = inEmail;
    address = inAddress;
}

// ���� ����ó ��������
void PersonalContact::get(string *outName, string *outPhoneNumber, string *outEmail, string *outAddress, string *outTwitterAccount)
{
    if (outName != NULL)
        *outName = name;

    if (outPhoneNumber != NULL)
        *outPhoneNumber = phoneNumber;

    if (outEmail != NULL)
        *outEmail = email;

    if (outAddress != NULL)
        *outAddress = address;
}

// ���� ����ó ����
void PersonalContact::edit(const string *inName, const string *inPhoneNumber, const string *inEmail, const string *inAddress, const string *inTwitterAccount)
{
    if (inName != NULL)
        name = *inName;

    if (inPhoneNumber != NULL)
        phoneNumber = *inPhoneNumber;

    if (inEmail != NULL)
        email = *inEmail;

    if (inAddress != NULL)
        address = *inAddress;
}

// ���� ����ó ���
void PersonalContact::print()
{
    cout << "����ó �̸�: " << name << endl;
    cout << "����ó ��ȭ��ȣ: " << phoneNumber << endl;
    cout << "����ó �̸���: " << email << endl;
    cout << "����ó �ּ�: " << address << endl;
}

// ��������ó ������ ���Ϸ� ������
void PersonalContact::save(ofstream &saveFile)
{
    saveFile << name << endl;
    saveFile << phoneNumber << endl;
    saveFile << email << endl;
    saveFile << address << endl;
}

// ��������ó ������ ���Ͽ��� �ҷ���
void PersonalContact::load(ifstream &saveFile)
{
    saveFile >> name;
    saveFile >> phoneNumber;
    saveFile >> email;
    saveFile >> address;
}