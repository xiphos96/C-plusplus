#ifndef _OWNER_H_
#define _OWNER_H_

#include <iostream>
#include <string>
#include "PersonalInfo.h"

using namespace std;
class Owner : public PersonalInfo  {
protected:
    string twitterAccount;  // 트위터 아이디
    string phoneNumber;     // 전화번호
    string email;           // 이메일
    string address;         // 주소

public:
    // 생성자
    Owner();

    // 소유자 정보 입력
    void input(const string inName, const string inPhoneNumber, const string inEmail, const string inAddress, const string inTwitterAccount = "");

    // 소유자 정보 가져오기
    void get(string *outName, string *outPhoneNumber, string *outEmail, string *outAddress, string *outTwitterAccount = NULL);

    // 소유자 정보 편집
    void edit(const string *inName, const string *inPhoneNumber, const string *inEmail, const string *inAddress, const string *inTwitterAccount);

    // 소유자 정보 출력
    void print();

    // 소유자 정보를 파일로 저장함
    void save();

    // 소유자 정보를 파일에서 불러옴
    void load();
};

#endif