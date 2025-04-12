#ifndef _CONTACT_H_
#define _CONTACT_H_

#include <iostream>
#include <string>
#include <vector>
#include <map>

#include "PersonalContact.h"
#include <fstream>
using namespace std;

template <typename ContactType>
class Contact  {
private:
    vector<ContactType> contactInfo;        // 연락처 저장 가능한 순차 컨테이너 vector
    multimap<string, int> multiMap;         // 연락처 이름 검색을 위한 mutimap 컨테이너
    string saveFileName;
public:
    // 생성자: 연락처 저장 파일 설정
    Contact(string pSaveFileName);

    // 소멸자
    ~Contact();

    // 연락처 정보 입력
    void inputContact(ContactType contact);

    // 연락처 전체 목록 조회
    void printContactList();

    // 연락처 상세 조회: 함수 오버로딩
    void printContact(int index);
    void printContact(const string pName);

    // 연락처 수정
    void editContactByIndex(int index, ContactType contact);

    // 연락처 복사
    void copyContact(int index);

    // 연락처 제거
    void removeContactByIndex(int index);

    // 연락처 얻어오기
    ContactType getContact(int index);

    // 파일에 연락처 저장하기
    void save();
};

// 생성자: 연락처 저장 파일 설정
template <typename ContactType>
Contact<ContactType>::Contact(string pSaveFileName)
{
    saveFileName = pSaveFileName;
    ifstream saveFile;
    saveFile.open(saveFileName);
    if (saveFile.fail())
        return;

    int num, i;
    char temp;
    saveFile >> num;
    saveFile.get(temp);
    ContactType contact;
    for (i = 0; i < num; i++)
    {
        contact.load(saveFile);
        inputContact(contact);
    }
}

// 소멸자
template <typename ContactType>
Contact<ContactType>::~Contact()
{
}

// 연락처 정보 입력
template <typename ContactType>
void Contact<ContactType>::inputContact(ContactType contact)
{
    // 이름 검색을 위한 Map 에 새로운 키워드와 index를 넣어준다. 
    multiMap.insert(pair<string, int>(contact.getName(), contactInfo.size()));

    // 연락처 저장을 위한 vector에 연락처 정보를 넣어준다. 
    contactInfo.push_back(ContactType(contact));
}

// 연락처 전체 목록 조회
template <typename ContactType>
void Contact<ContactType>::printContactList()
{
    int i;
    string name;
    int numberOfContact = contactInfo.size();
    for (i = 0; i< numberOfContact; i++)
    {
        cout << i << " : " << contactInfo[i].getName() << endl;
    }
}

// 연락처 상세 조회: index
template <typename ContactType>
void Contact<ContactType>::printContact(int index)
{
    cout << index << "의 index를 가진 연락처 조회" << endl;
    contactInfo[index].print();
}

// 연락처 상세 조회: 이름(함수 오버로딩)
template <typename ContactType>
void Contact<ContactType>::printContact(const string pName)
{
    cout << pName << "의 이름을 가진 연락처 조회" << endl;
    multimap<string, int>::iterator it = multiMap.find(pName);
    if (it != multiMap.end())
        contactInfo[it->second].print();
}

// 연락처 수정
template <typename ContactType>
void Contact<ContactType>::editContactByIndex(int index, ContactType contact)
{
    // 연락처의 이름이 변경된 경우 multimap 수정
    if (contactInfo[index].getName().compare(contact.getName()) != 0){
        multimap<string, int>::iterator it = multiMap.find(contactInfo[index].getName());
        multiMap.erase(it);
        multiMap.insert(pair<string, int>(contact.getName(), index));
    }

    // 연락처 수정
    contactInfo[index] = ContactType(contact);
}

// 연락처 복사
template <typename ContactType>
void Contact<ContactType>::copyContact(int index)
{
    // 이름 검색을 위한 Map 에 새로운 키워드와 index를 넣어준다. 
    multiMap.insert(pair<string, int>(contactInfo[index].getName(), contactInfo.size()));
    contactInfo.push_back(ContactType(contactInfo[index]));
}

// 연락처 제거
template <typename ContactType>
void Contact<ContactType>::removeContactByIndex(int index)
{
    // index가 0보다 작거나 contactNumber보다 크면 삭제 불가
    int numberOfContact = contactInfo.size();

    if ((index >= numberOfContact) || (index < 0))
    {
        cout << index << "는 삭제가 불가능한 인덱스 입니다. " << endl;
        return;
    }

    multimap<string, int>::iterator it = multiMap.find(contactInfo[index].getName());
    contactInfo.erase(contactInfo.begin() + index);
    multiMap.erase(it);
}

// 연락처 얻어오기 
template <typename ContactType>
ContactType Contact<ContactType>::getContact(int index)
{
    return contactInfo[index];
}

// 파일에 연락처 저장하기
template <typename ContactType>
void Contact<ContactType>::save()
{
    ofstream saveFile;
    saveFile.open(saveFileName);
    if (saveFile.fail())
        return;

    int num, i;
    num = contactInfo.size();
    saveFile << num << endl;
    ContactType contact;
    for (i = 0; i < num; i++)
        contactInfo[i].save(saveFile);
}
#endif