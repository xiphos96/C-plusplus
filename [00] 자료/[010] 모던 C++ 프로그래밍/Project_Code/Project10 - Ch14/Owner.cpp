#include "Owner.h"
#include <fstream>
#include "OwnerException.h"
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
    
    // 전화번호 예외처리
    // 숫자와 하이폰 허용
    string::iterator it = phoneNumber.begin();
    for (it = phoneNumber.begin(); it != phoneNumber.end(); it++)
    {
        if (!(*it >= 48 && *it <= 57) && (*it != 45))
        {
            OwnerException e("Owner 클래스 전화번호 입력시 잘못된 값을 입력했습니다.");
            throw e;
        }
    }
    
    email = inEmail;
    // 이메일 예외 처리
    // @ 체크
    if (email.find("@") == string::npos)
    {
        OwnerException e("Owner 클래스 이메일 주소 입력시 @값이 없습니다.");
        throw e;
    }
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
    {
        // 전화번호 예외처리
        // 숫자와 하이폰 허용
        string::iterator it = phoneNumber.begin();
        for (it = phoneNumber.begin(); it != phoneNumber.end(); it++)
        {
            if (!(*it >= 48 && *it <= 57) && (*it != 45))
            {
                OwnerException e("Owner 클래스 전화번호 입력시 잘못된 값을 입력했습니다.");
                throw e;
            }
        }
        phoneNumber = *inPhoneNumber;
    }
       
    if (inEmail != NULL)
    {
        // 이메일 예외 처리
        // @ 체크
        if (email.find("@") == string::npos)
        {
            OwnerException e("Owner 클래스 이메일 주소 입력시 @값이 없습니다.");
            throw e;
        }
        email = *inEmail;
    }

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

    // 파일을 저장핟때 실패하거나 잘못되었을때 예외를 던진다. 
    saveFile.exceptions(std::ofstream::failbit | std::ofstream::badbit);
    saveFile.open("owner.dat");

    saveFile << name << endl;
    saveFile << phoneNumber << endl;
    saveFile << email << endl;
    saveFile << address << endl;
    saveFile << twitterAccount << endl;
}

// 소유자 정보를 파일에서 불러옴
void Owner::load()
{
    ifstream saveFile;

    // 파일을 저장핟때 실패하거나 잘못되었을때 예외를 던진다. 
    saveFile.exceptions(std::ifstream::failbit | std::ifstream::badbit);
    saveFile.open("owner.dat");

    saveFile >> name;
    saveFile >> phoneNumber;
    saveFile >> email;
    saveFile >> address;
    saveFile >> twitterAccount;
}