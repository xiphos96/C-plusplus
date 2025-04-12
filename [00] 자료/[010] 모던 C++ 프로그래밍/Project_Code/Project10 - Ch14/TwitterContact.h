#ifndef _TWITTER_CONTACT_H_
#define _TWITTER_CONTACT_H_

#include <iostream>
#include "PersonalInfo.h"

class TwitterContact : public PersonalInfo {
private:
    string id;          // 트위터 아이디(숫자)
    string account;     // 트위터 계정(Screen_name)
    string location;    // 트위터 접속 위치
    string description; // Description
    string url;         // URL

public:
    // 생성자 
    TwitterContact(){};

    // 복사 생성자
    TwitterContact(TwitterContact &twitterContact);

    // 트위터 연락처 입력
    void input(const string inId, const string inName, const string inAccount, const string inLocation, const string inDescription, const string inUrl);

    // 트위터 연락처 가져오기
    void get(string *outId, string *outName, string *outAccount, string *outLocation, string *outDescription, string *outUrl);

    // 트위터 연락처 편집
    void edit(const string *inId, const string *inName, const string *inAccount, const string *inLocation, const string *inDescription, const string *inUrl);

    // 트위터 연락처 출력
    void print();

    // 개별 연락처 정보를 파일로 저장함
    void save(ofstream &saveFile);

    // 개별 연락처 정보를 파일에서 불러옴
    void load(ifstream &saveFile);
};

#endif