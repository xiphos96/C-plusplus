#include "Owner.h"

using namespace std;

// ������ ���� �Է�
void Owner::inputOwnerInfo(char *inName, char *inPhoneNumber, char *inEmail, char *inAddress, char *inTwitterAccount)
{
    if (inName != NULL)
        strcpy_s(name, 20, inName);

    if (inPhoneNumber != NULL)
        strcpy_s(phoneNumber, 13, inPhoneNumber);

    if (inEmail != NULL)
        strcpy_s(email, 30, inEmail);

    if (inAddress != NULL)
        strcpy_s(address, 50, inAddress);

    if (inTwitterAccount != NULL)
        strcpy_s(twitterAccount, 20, inTwitterAccount);
}

// ������ ���� ���
void Owner::printOwnerInfo()
{
    cout << "������ �̸�: " << name << endl;
    cout << "������ ��ȭ��ȣ: " << phoneNumber << endl;
    cout << "������ �̸���: " << email << endl;
    cout << "������ �ּ�: " << address << endl;
    cout << "������ Ʈ���� ����: " << twitterAccount << endl;
}

// ������ ���� ����
void Owner::editOwnerInfo(char *inName, char *inPhoneNumber, char *inEmail, char *inAddress, char *inTwitterAccount)
{
    if (inName != NULL)
        strcpy_s(name, 20, inName);

    if (inPhoneNumber != NULL)
        strcpy_s(phoneNumber, 13, inPhoneNumber);

    if (inEmail != NULL)
        strcpy_s(email, 30, inEmail);

    if (inAddress != NULL)
        strcpy_s(address, 50, inAddress);

    if (inTwitterAccount != NULL)
        strcpy_s(twitterAccount, 20, inTwitterAccount);
}
