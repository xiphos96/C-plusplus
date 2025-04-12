#include "Owner.h"
#include <fstream>
#include "OwnerException.h"
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
    
    // ��ȭ��ȣ ����ó��
    // ���ڿ� ������ ���
    string::iterator it = phoneNumber.begin();
    for (it = phoneNumber.begin(); it != phoneNumber.end(); it++)
    {
        if (!(*it >= 48 && *it <= 57) && (*it != 45))
        {
            OwnerException e("Owner Ŭ���� ��ȭ��ȣ �Է½� �߸��� ���� �Է��߽��ϴ�.");
            throw e;
        }
    }
    
    email = inEmail;
    // �̸��� ���� ó��
    // @ üũ
    if (email.find("@") == string::npos)
    {
        OwnerException e("Owner Ŭ���� �̸��� �ּ� �Է½� @���� �����ϴ�.");
        throw e;
    }
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
    {
        // ��ȭ��ȣ ����ó��
        // ���ڿ� ������ ���
        string::iterator it = phoneNumber.begin();
        for (it = phoneNumber.begin(); it != phoneNumber.end(); it++)
        {
            if (!(*it >= 48 && *it <= 57) && (*it != 45))
            {
                OwnerException e("Owner Ŭ���� ��ȭ��ȣ �Է½� �߸��� ���� �Է��߽��ϴ�.");
                throw e;
            }
        }
        phoneNumber = *inPhoneNumber;
    }
       
    if (inEmail != NULL)
    {
        // �̸��� ���� ó��
        // @ üũ
        if (email.find("@") == string::npos)
        {
            OwnerException e("Owner Ŭ���� �̸��� �ּ� �Է½� @���� �����ϴ�.");
            throw e;
        }
        email = *inEmail;
    }

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

    // ������ �������� �����ϰų� �߸��Ǿ����� ���ܸ� ������. 
    saveFile.exceptions(std::ofstream::failbit | std::ofstream::badbit);
    saveFile.open("owner.dat");

    saveFile << name << endl;
    saveFile << phoneNumber << endl;
    saveFile << email << endl;
    saveFile << address << endl;
    saveFile << twitterAccount << endl;
}

// ������ ������ ���Ͽ��� �ҷ���
void Owner::load()
{
    ifstream saveFile;

    // ������ �������� �����ϰų� �߸��Ǿ����� ���ܸ� ������. 
    saveFile.exceptions(std::ifstream::failbit | std::ifstream::badbit);
    saveFile.open("owner.dat");

    saveFile >> name;
    saveFile >> phoneNumber;
    saveFile >> email;
    saveFile >> address;
    saveFile >> twitterAccount;
}