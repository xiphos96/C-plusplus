#include "Owner.h"
#include <fstream>

// 생성자
Owner::Owner()
{
    load();
}

// 소유자 정보 입력
void Owner::input(const string inName, const string inPhoneNumber, const string inEmail, const string inAddress, const string inTwitterAccount)
{
    name = inName;
    phoneNumber = inPhoneNumber;
    email = inEmail;
    address = inAddress;
    twitterAccount = inTwitterAccount;
}

// 소유자 정보 가져오기
void Owner::get(string *outName, string *outPhoneNumber, string *outEmail, string *outAddress, string *outTwitterAccount)
{
    if (outName != NULL)
        *outName = name;

    if (outPhoneNumber != NULL)
        *outPhoneNumber = phoneNumber;

    if (outEmail != NULL)
        *outEmail = email;

    if (outAddress != NULL)
        *outAddress = address;

    if (outTwitterAccount != NULL)
        *outTwitterAccount = twitterAccount;
}

// 소유자 정보 편집
void Owner::edit(const string *inName, const string *inPhoneNumber, const string *inEmail, const string *inAddress, const string *inTwitterAccount)
{
    if (inName != NULL)
        name = *inName;

    if (inPhoneNumber != NULL)
        phoneNumber = *inPhoneNumber;

    if (inEmail != NULL)
        email = *inEmail;

    if (inAddress != NULL)
        address = *inAddress;

    if (inTwitterAccount != NULL)
        twitterAccount = *inTwitterAccount;
}

// 소유자 정보 출력
void Owner::print()
{
    cout << "소유자 이름: " << name << endl;
    cout << "소유자 전화번호: " << phoneNumber << endl;
    cout << "소유자 이메일: " << email << endl;
    cout << "소유자 주소: " << address << endl;
    cout << "소유자 트위터 계정: " << twitterAccount << endl;
}

// 소유자 정보를 파일로 저장함
void Owner::save()
{
    ofstream saveFile;
    saveFile.open("owner.dat");
    if (saveFile.fail())
    {
        cout << "파일저장중에 오류가 발생했습니다." << endl;
        return;
    }

    saveFile << name << endl;
    saveFile << phoneNumber << endl;
    saveFile << email << endl;
    saveFile << address << endl;
    saveFile << twitterAccount << endl;
}

// 생성자
void Owner::load()
{
    ifstream saveFile;
    saveFile.open("owner.dat");
    if (saveFile.fail())
        return;

    saveFile >> name;
    saveFile >> phoneNumber;
    saveFile >> email;
    saveFile >> address;
    saveFile >> twitterAccount;
}