#ifndef _TWITTER_CONTACT_H_
#define _TWITTER_CONTACT_H_

#include <iostream>
#include "PersonalInfo.h"

class TwitterContact : public PersonalInfo {
private:
    string id;          // Ʈ���� ���̵�(����)
    string account;     // Ʈ���� ����(Screen_name)
    string location;    // Ʈ���� ���� ��ġ
    string description; // Description
    string url;         // URL

public:
    // ������ 
    TwitterContact(){};

    // ���� ������
    TwitterContact(TwitterContact &twitterContact);

    // Ʈ���� ����ó �Է�
    void input(const string inId, const string inName, const string inAccount, const string inLocation, const string inDescription, const string inUrl);

    // Ʈ���� ����ó ��������
    void get(string *outId, string *outName, string *outAccount, string *outLocation, string *outDescription, string *outUrl);

    // Ʈ���� ����ó ����
    void edit(const string *inId, const string *inName, const string *inAccount, const string *inLocation, const string *inDescription, const string *inUrl);

    // Ʈ���� ����ó ���
    void print();

    // ���� ����ó ������ ���Ϸ� ������
    void save(ofstream &saveFile);

    // ���� ����ó ������ ���Ͽ��� �ҷ���
    void load(ifstream &saveFile);
};

#endif