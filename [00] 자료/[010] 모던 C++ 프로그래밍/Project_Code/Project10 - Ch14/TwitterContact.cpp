#include "TwitterContact.h"
#include <fstream>


// ���� ������
TwitterContact::TwitterContact(TwitterContact &twitterContact)
{
    id = twitterContact.id;
    name = twitterContact.name;
    account = twitterContact.account;
    location = twitterContact.location;
    description = twitterContact.description;
    url = twitterContact.url;
}

// Ʈ���� ����ó �Է�
void TwitterContact::input(const string inId, const string inName, const string inAccount, const string inLocation, const string inDescription, const string inUrl)
{
    id = inId;
    name = inName;
    account = inAccount;
    location = inLocation;
    description = inDescription;
    url = inUrl;
}

// Ʈ���� ����ó ��������
void TwitterContact::get(string *outId, string *outName, string *outAccount, string *outLocation, string *outDescription, string *outUrl)
{
    if (outId != NULL)
        *outId = id;

    if (outName != NULL)
        *outName = name;

    if (outAccount != NULL)
        *outAccount = account;

    if (outLocation != NULL)
        *outLocation = location;

    if (outDescription != NULL)
        *outDescription = description;

    if (outUrl != NULL)
        *outUrl = url;
}

// Ʈ���� ����ó ����
void TwitterContact::edit(const string *inId, const string *inName, const string *inAccount, const string *inLocation, const string *inDescription, const string *inUrl)
{
    if (inId != NULL)
        id = *inId;

    if (inName != NULL)
        name = *inName;

    if (inAccount != NULL)
        account = *inAccount;

    if (inLocation != NULL)
        location = *inLocation;

    if (inDescription != NULL)
        description = *inDescription;

    if (inUrl != NULL)
        url = *inUrl;
}

// Ʈ���� ����ó ���
void TwitterContact::print()
{
    cout << "Ʈ���� ���̵�: " << id << endl;
    cout << "Ʈ���� �̸�: " << name << endl;
    cout << "Ʈ���� ����: " << account << endl;
    cout << "Ʈ��ó ���� ��ġ: " << location << endl;
    cout << "Ʈ���� Description: " << description << endl;
    cout << "Ʈ���� URL: " << url << endl;
}

// ���� Ʈ���� ����ó ���Ϸ� ����
void TwitterContact::save(ofstream &saveFile)
{
    saveFile << id << endl;
    saveFile << name << endl;
    saveFile << account << endl;
    saveFile << location << endl;
    saveFile << description << endl;
    saveFile << url << endl;
}

// ���� Ʈ���� ����ó ���Ϸκ��� �о� ����
void TwitterContact::load(ifstream &saveFile)
{
    getline(saveFile, id);
    getline(saveFile, name);
    getline(saveFile, account);
    getline(saveFile, location);
    getline(saveFile, description);
    getline(saveFile, url);
}