#include "Contact.h"
#include "freelectwitcurl.h"
#include "Owner.h"

using namespace std;

// ������
Contact::Contact()
{
    contactInfo = new PersonalContact[100]; // �����Ҵ�
    numberOfContact = 0;			        // ����ó ���� �ʱ�ȭ 
}

// �Ҹ���: contactInfo �޸� ����
Contact::~Contact()
{
    delete[] contactInfo; 	// �����Ҵ�����
}

// ����ó ���� �Է�
void Contact::inputContact(char *name, char *phoneNumber, char *email, char *address)
{
    contactInfo[numberOfContact].inputContact(name, phoneNumber, email, address);
    numberOfContact++;
}

// ����ó ��ü ��� ��ȸ
void Contact::printContactList()
{
    int i;
    char name[30];
    for (i = 0; i< numberOfContact; i++)
    {
        contactInfo[i].getContact(name, NULL, NULL, NULL);
        cout << i << " : " << name << endl;
    }
}

// ����ó �� ��ȸ: index
void Contact::printContact(int index)
{
    char name[20];
    char phoneNumber[13];
    char email[30];
    char address[50];

    contactInfo[index].getContact(name, phoneNumber, email, address);
    cout << index << "�� index�� ���� ����ó ��ȸ" << endl;
    cout << "����ó �̸�: " << name << endl;
    cout << "����ó ��ȭ��ȣ: " << phoneNumber << endl;
    cout << "����ó �̸���: " << email << endl;
    cout << "����ó �ּ�: " << address << endl;
}

// ����ó �� ��ȸ: �̸� (�Լ� �����ε�)
void Contact::printContact(char *inName)
{
    char name[20];
    char phoneNumber[13];
    char email[30];
    char address[50];

    int i;

    cout << inName << "�� �̸��� ���� ����ó ��ȸ" << endl;

    for (i = 0; i< numberOfContact; i++)
    {
        contactInfo[i].getContact(name, phoneNumber, email, address);
        if (strcmp(inName, name) == 0)
        {

            cout << "����ó �̸�: " << name << endl;
            cout << "����ó ��ȭ��ȣ: " << phoneNumber << endl;
            cout << "����ó �̸���: " << email << endl;
            cout << "����ó �ּ�: " << address << endl;
        }
    }
}

// ����ó ����
void Contact::editContactByIndex(int index, char *name, char *phoneNumber, char *email, char *address)
{
    contactInfo[index].editContact(name, phoneNumber, email, address);
}

// ����ó ����
void Contact::copyContact(int index)
{
    contactInfo[numberOfContact] = PersonalContact(contactInfo[index]);
    numberOfContact++;
}

// ����ó ����
void Contact::removeContactByIndex(int index)
{
    // index�� 0���� �۰ų� contactNumber���� ũ�� ���� �Ұ�
    if ((index >= numberOfContact) || (index < 0))
    {
        cout << index << "�� ������ �Ұ����� �ε��� �Դϴ�. " << endl;
        return;
    }

    int i;
    for (i = index + 1; i < numberOfContact; i++)
    {
        contactInfo[i - 1] = contactInfo[i];
    }

    numberOfContact--;
}

// Ʈ���� ����ó ����
void Contact::retrieveTwitterFollowing(Owner &owner)
{
    // freelect-twitCurl ��ü
    freelecTwitCurl twitterObj;

    // Ʈ���� ���̵� �� ��й�ȣ ����
    char passWord[50];

    // Ʈ���� ��й�ȣ �ޱ�
    cout << "Ʈ���� ��й�ȣ : ";
    cin >> passWord;

    // twitCurl ��ü�� ���̵� �н����� ����
    twitterObj.setTwitterUsername(owner.twitterAccount);
    twitterObj.setTwitterPassword(passWord);

    // ConsumerKey �� SecretKey ����
    twitterObj.setConsumerKey("LJ4uJuOE4hEYG3OiCrftQ");
    twitterObj.setConsumerSecret("vlYbnhUwLp0pEt8fISQyqet5Iw5wu5kW4RWOtERx8");

    // ���� �ϱ� 
    if (twitterObj.performAuth() == false)
    {
        cout << "Twitter ������ �����߽��ϴ�." << endl;
        return;
    }

    // Ʈ���� follow ���̵� �ҷ����� 
    // friendsIdsGet �Լ� ȣ��, friends/ids�� request�� ������. 
    if (twitterObj.friendsIdsGet("", owner.twitterAccount) == false){
        cout << "friends/ids ��û�� �����߽��ϴ�." << endl;
        return;
    }

    // ids�׸��� �Ľ��ؼ� �����´�. 
    std::string result = twitterObj.friendsIdsParse("ids");

    // ids �׺� �� ��ȸ�� ���� userLookup �Լ� ȣ��
    if (twitterObj.userLookup(result, true) == false){
        cout << "user/lookup ��û�� �����߽��ϴ�." << endl;
        return;
    };

    // name �׸� �Ľ��� ��������
    result = twitterObj.userLookupParse("name");

    // string char* ��ȯ
    char buffer[1000];
    int bufferSize = result.size();
    strcpy_s(buffer, result.c_str());

    // deliminator �и�
    int i, pos = 0;
    char name[20];
    for (i = 0; i < bufferSize; i++)
    {
        if (buffer[i] == ',')
        {
            strncpy_s(name, &buffer[pos], i - pos);
            inputContact(name, NULL, NULL, NULL);
            cout << name << " ���� �Ϸ�" << endl;

            pos = i + 1;
        }
    }

    strncpy_s(name, &buffer[pos], i - pos);
    inputContact(name, NULL, NULL, NULL);
    cout << name << " ���� �Ϸ�" << endl;
}