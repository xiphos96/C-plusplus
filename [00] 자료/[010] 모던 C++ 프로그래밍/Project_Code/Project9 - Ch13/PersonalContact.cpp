#include "PersonalContact.h"
#include <fstream>

// 복사 생성자
PersonalContact::PersonalContact(PersonalContact &personal)
{
    name = personal.name;
    phoneNumber = personal.phoneNumber;
    email = personal.email;
    address = personal.address;
}

// 개인 연락처 입력
void PersonalContact::input(const string inName, const string inPhoneNumber, const string inEmail, const string inAddress, const string inTwitterAccount)
{
    name = inName;
    phoneNumber = inPhoneNumber;
    email = inEmail;
    address = inAddress;
}

// 개인 연락처 가져오기
void PersonalContact::get(string *outName, string *outPhoneNumber, string *outEmail, string *outAddress, string *outTwitterAccount)
{
    if (outName != NULL)
        *outName = name;

    if (outPhoneNumber != NULL)
        *outPhoneNumber = phoneNumber;

    if (outEmail != NULL)
        *outEmail = email;

    if (outAddress != NULL)
        *outAddress = address;
}

// 개인 연락처 편집
void PersonalContact::edit(const string *inName, const string *inPhoneNumber, const string *inEmail, const string *inAddress, const string *inTwitterAccount)
{
    if (inName != NULL)
        name = *inName;

    if (inPhoneNumber != NULL)
        phoneNumber = *inPhoneNumber;

    if (inEmail != NULL)
        email = *inEmail;

    if (inAddress != NULL)
        address = *inAddress;
}

// 개인 연락처 출력
void PersonalContact::print()
{
    cout << "연락처 이름: " << name << endl;
    cout << "연락처 전화번호: " << phoneNumber << endl;
    cout << "연락처 이메일: " << email << endl;
    cout << "연락처 주소: " << address << endl;
}

// 개별연락처 정보를 파일로 저장함
void PersonalContact::save(ofstream &saveFile)
{
    saveFile << name << endl;
    saveFile << phoneNumber << endl;
    saveFile << email << endl;
    saveFile << address << endl;
}

// 개별연락처 정보를 파일에서 불러옴
void PersonalContact::load(ifstream &saveFile)
{
    saveFile >> name;
    saveFile >> phoneNumber;
    saveFile >> email;
    saveFile >> address;
}