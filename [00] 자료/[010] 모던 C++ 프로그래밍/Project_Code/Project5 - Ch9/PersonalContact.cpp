#include "PersonalContact.h"

// 복사 생성자
PersonalContact::PersonalContact(PersonalContact &personal)
{
    strcpy_s(name, 20, personal.name);
    strcpy_s(phoneNumber, 13, personal.phoneNumber);
    strcpy_s(email, 30, personal.email);
    strcpy_s(address, 50, personal.address);
}

// 연락처 입력
void PersonalContact::inputContact(char *inName, char *inPhoneNumber, char *inEmail, char *inAddress)
{
    if (inName != NULL)
        strcpy_s(name, 20, inName);

    if (inPhoneNumber != NULL)
        strcpy_s(phoneNumber, 13, inPhoneNumber);

    if (inEmail != NULL)
        strcpy_s(email, 30, inEmail);

    if (inAddress != NULL)
        strcpy_s(address, 50, inAddress);
}

// 연락처 조회
void PersonalContact::getContact(char *outName, char *outPhoneNumber, char *outEmail, char *outAddress)
{
    if (outName != NULL)
        strcpy_s(outName, 20, name);

    if (outPhoneNumber != NULL)
        strcpy_s(outPhoneNumber, 13, phoneNumber);

    if (outEmail != NULL)
        strcpy_s(outEmail, 30, email);

    if (outAddress != NULL)
        strcpy_s(outAddress, 50, address);
}

// 연락처 수정
void PersonalContact::editContact(char *inName, char *inPhoneNumber, char *inEmail, char *inAddress)
{
    if (inName != NULL)
        strcpy_s(name, 20, inName);

    if (inPhoneNumber != NULL)
        strcpy_s(phoneNumber, 13, inPhoneNumber);

    if (inEmail != NULL)
        strcpy_s(email, 30, inEmail);

    if (inAddress != NULL)
        strcpy_s(address, 50, inAddress);
}
