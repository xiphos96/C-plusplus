#ifndef _PERSONAL_CONTACT_H_
#define _PERSONAL_CONTACT_H_

#include <iostream>
#include "PersonalInfo.h"

using namespace std;
class PersonalContact : public PersonalInfo  {
public:
    // 기본 생성자
    PersonalContact(){}

    // 복사 생성자
    PersonalContact(PersonalContact &personal);

    // 개인정보 입력
    void input(const string inName, const string inPhoneNumber, const string inEmail, const string inAddress, const string inTwitterAccount = "");

    // 개인정보 가져오기
    void get(string *outName, string *outPhoneNumber, string *outEmail, string *outAddress, string *outTwitterAccount = NULL) ;

    // 개인정보 편집
    void edit(const string *inName, const string *inPhoneNumber, const string *inEmail, const string *inAddress, const string *inTwitterAccount = NULL);
};

#endif