#include "TwitterContact.h"
#include <fstream>


// 복사 생성자
TwitterContact::TwitterContact(TwitterContact &twitterContact)
{
    id = twitterContact.id;
    name = twitterContact.name;
    account = twitterContact.account;
    location = twitterContact.location;
    description = twitterContact.description;
    url = twitterContact.url;
}

// 트위터 연락처 입력
void TwitterContact::input(const string inId, const string inName, const string inAccount, const string inLocation, const string inDescription, const string inUrl)
{
    id = inId;
    name = inName;
    account = inAccount;
    location = inLocation;
    description = inDescription;
    url = inUrl;
}

// 트위터 연락처 가져오기
void TwitterContact::get(string *outId, string *outName, string *outAccount, string *outLocation, string *outDescription, string *outUrl)
{
    if (outId != NULL)
        *outId = id;

    if (outName != NULL)
        *outName = name;

    if (outAccount != NULL)
        *outAccount = account;

    if (outLocation != NULL)
        *outLocation = location;

    if (outDescription != NULL)
        *outDescription = description;

    if (outUrl != NULL)
        *outUrl = url;
}

// 트위터 연락처 편집
void TwitterContact::edit(const string *inId, const string *inName, const string *inAccount, const string *inLocation, const string *inDescription, const string *inUrl)
{
    if (inId != NULL)
        id = *inId;

    if (inName != NULL)
        name = *inName;

    if (inAccount != NULL)
        account = *inAccount;

    if (inLocation != NULL)
        location = *inLocation;

    if (inDescription != NULL)
        description = *inDescription;

    if (inUrl != NULL)
        url = *inUrl;
}

// 트위터 연락처 출력
void TwitterContact::print()
{
    cout << "트위터 아이디: " << id << endl;
    cout << "트위터 이름: " << name << endl;
    cout << "트위터 계정: " << account << endl;
    cout << "트위처 접속 위치: " << location << endl;
    cout << "트위터 Description: " << description << endl;
    cout << "트위터 URL: " << url << endl;
}

// 개별 트위터 연락처 파일로 저장
void TwitterContact::save(ofstream &saveFile)
{
    saveFile << id << endl;
    saveFile << name << endl;
    saveFile << account << endl;
    saveFile << location << endl;
    saveFile << description << endl;
    saveFile << url << endl;
}

// 개별 트위터 연락처 파일로부터 읽어 오기
void TwitterContact::load(ifstream &saveFile)
{
    getline(saveFile, id);
    getline(saveFile, name);
    getline(saveFile, account);
    getline(saveFile, location);
    getline(saveFile, description);
    getline(saveFile, url);
}