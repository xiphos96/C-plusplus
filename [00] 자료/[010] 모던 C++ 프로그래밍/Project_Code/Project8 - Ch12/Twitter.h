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
    string userName;             // 트위터 아이디
    string password;             // 비밀번호
    string consumerKey;          // App ConsumerKey
    string consumerSecret;       // App ConsumerSecret

    freelecTwitCurl twitterObj;  // freelec-twitcurl 객체

public:
    // 생성자 
    Twitter();

    // 소멸자 
    ~Twitter();

    // 사용자 ID설정
    void setUserName(const string inUserName);

    // 비밀번호 설정
    void setPassword(const string inPassword);

    // ConsumerKey 설정
    void setConsumerKey(const string inConsumerKey);

    // ConsumerSecret 설정
    void setConsumerSecret(const string inConsumerSecret);

    // 트위터 인증 수행
    bool performAuth();

    // 트위터 팔로잉 목록 연락처 동기화
    void syncContacts(Contact<TwitterContact> &inContact);

    // 트위터 타임라인 조회
    void getTimeline();

    // 특정 사용자 트위터 타임라인 조회
    void getUserTimeline(const string screen_name);

    // 최근 수신 메시지 조회
    void getReceivedMessages();

    // 최근 송신 메시지 조회
    void getSentMessages();

    // 새로운 메시지 전송
    bool sentMessage(string screen_name, string text);
};

#endif