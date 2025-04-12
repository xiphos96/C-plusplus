#ifndef _PERSONAL_INFO_H_
#define _PERSONAL_INFO_H_
#include <iostream>
using namespace std;
class PersonalInfo  {
protected:
    string name;               // 이름
    string phoneNumber;        // 전화번호
    string email;              // 이메일
    string address;            // 주소
public:
    // 개인정보 입력
    virtual void input(const string inName, const string inPhoneNumber, const string inEmail, const string inAddress, const string inTwitterAccount = "") = 0;

    // 개인정보 가져오기
    virtual void get(string *outName, string *outPhoneNumber, string *outEmail, string *outAddress, string *outTwitterAccount = NULL) = 0;

    // 개인정보 편집
    virtual void edit(const string *inName, const string *inPhoneNumber, const string *inEmail, const string *inAddress, const string *inTwitterAccount = NULL) = 0;
};

#endif