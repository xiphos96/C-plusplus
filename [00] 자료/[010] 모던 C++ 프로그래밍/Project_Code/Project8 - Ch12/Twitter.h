#ifndef _TWITTER_H_
#define _TWITTER_H_

#include <iostream>
#include <string>
#include "freelectwitcurl.h"
#include "Contact.h"
#include "TwitterContact.h"
using namespace std;

class Twitter  {
private:
    string userName;             // Ʈ���� ���̵�
    string password;             // ��й�ȣ
    string consumerKey;          // App ConsumerKey
    string consumerSecret;       // App ConsumerSecret

    freelecTwitCurl twitterObj;  // freelec-twitcurl ��ü

public:
    // ������ 
    Twitter();

    // �Ҹ��� 
    ~Twitter();

    // ����� ID����
    void setUserName(const string inUserName);

    // ��й�ȣ ����
    void setPassword(const string inPassword);

    // ConsumerKey ����
    void setConsumerKey(const string inConsumerKey);

    // ConsumerSecret ����
    void setConsumerSecret(const string inConsumerSecret);

    // Ʈ���� ���� ����
    bool performAuth();

    // Ʈ���� �ȷ��� ��� ����ó ����ȭ
    void syncContacts(Contact<TwitterContact> &inContact);

    // Ʈ���� Ÿ�Ӷ��� ��ȸ
    void getTimeline();

    // Ư�� ����� Ʈ���� Ÿ�Ӷ��� ��ȸ
    void getUserTimeline(const string screen_name);

    // �ֱ� ���� �޽��� ��ȸ
    void getReceivedMessages();

    // �ֱ� �۽� �޽��� ��ȸ
    void getSentMessages();

    // ���ο� �޽��� ����
    bool sentMessage(string screen_name, string text);
};

#endif