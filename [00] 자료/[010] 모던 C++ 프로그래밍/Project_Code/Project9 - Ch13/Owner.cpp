#include "Owner.h"
#include <fstream>

// ������
Owner::Owner()
{
    load();
}

// ������ ���� �Է�
void Owner::input(const string inName, const string inPhoneNumber, const string inEmail, const string inAddress, const string inTwitterAccount)
{
    name = inName;
    phoneNumber = inPhoneNumber;
    email = inEmail;
    address = inAddress;
    twitterAccount = inTwitterAccount;
}

// ������ ���� ��������
void Owner::get(string *outName, string *outPhoneNumber, string *outEmail, string *outAddress, string *outTwitterAccount)
{
    if (outName != NULL)
        *outName = name;

    if (outPhoneNumber != NULL)
        *outPhoneNumber = phoneNumber;

    if (outEmail != NULL)
        *outEmail = email;

    if (outAddress != NULL)
        *outAddress = address;

    if (outTwitterAccount != NULL)
        *outTwitterAccount = twitterAccount;
}

// ������ ���� ����
void Owner::edit(const string *inName, const string *inPhoneNumber, const string *inEmail, const string *inAddress, const string *inTwitterAccount)
{
    if (inName != NULL)
        name = *inName;

    if (inPhoneNumber != NULL)
        phoneNumber = *inPhoneNumber;

    if (inEmail != NULL)
        email = *inEmail;

    if (inAddress != NULL)
        address = *inAddress;

    if (inTwitterAccount != NULL)
        twitterAccount = *inTwitterAccount;
}

// ������ ���� ���
void Owner::print()
{
    cout << "������ �̸�: " << name << endl;
    cout << "������ ��ȭ��ȣ: " << phoneNumber << endl;
    cout << "������ �̸���: " << email << endl;
    cout << "������ �ּ�: " << address << endl;
    cout << "������ Ʈ���� ����: " << twitterAccount << endl;
}

// ������ ������ ���Ϸ� ������
void Owner::save()
{
    ofstream saveFile;
    saveFile.open("owner.dat");
    if (saveFile.fail())
    {
        cout << "���������߿� ������ �߻��߽��ϴ�." << endl;
        return;
    }

    saveFile << name << endl;
    saveFile << phoneNumber << endl;
    saveFile << email << endl;
    saveFile << address << endl;
    saveFile << twitterAccount << endl;
}

// ������
void Owner::load()
{
    ifstream saveFile;
    saveFile.open("owner.dat");
    if (saveFile.fail())
        return;

    saveFile >> name;
    saveFile >> phoneNumber;
    saveFile >> email;
    saveFile >> address;
    saveFile >> twitterAccount;
}