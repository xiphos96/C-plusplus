#ifndef _PERSONAL_CONTACT_H_
#define _PERSONAL_CONTACT_H_

#include <iostream>
#include "PersonalInfo.h"

using namespace std;
class PersonalContact : public PersonalInfo  {
protected:
    string phoneNumber;     // 전화번호
    string email;           // 이메일
    string address;         // 주소

public:
    // 기본 생성자
    PersonalContact(){}

    // 복사 생성자
    PersonalContact(PersonalContact &personal);

    // 개인 연락처 입력
    void input(const string inName, const string inPhoneNumber, const string inEmail, const string inAddress, const string inTwitterAccount = "");

    // 개인 연락처 가져오기
    void get(string *outName, string *outPhoneNumber, string *outEmail, string *outAddress, string *outTwitterAccount = NULL);

    // 개인 연락처 편집
    void edit(const string *inName, const string *inPhoneNumber, const string *inEmail, const string *inAddress, const string *inTwitterAccount = NULL);

    // 개인 연락처 출력
    void print();
};

#endif