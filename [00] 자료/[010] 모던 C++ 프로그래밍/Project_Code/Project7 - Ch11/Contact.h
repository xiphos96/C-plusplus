#ifndef _CONTACT_H_
#define _CONTACT_H_

#include <iostream>
#include <string>

#include "PersonalContact.h"

using namespace std;

template <typename ContactType>
class Contact  {
private:
    ContactType *contactInfo;        // 연락처 저장 가능한 포인터: 동적할당
    int numberOfContact;             // 현재 저장된 연락처 개수

public:
    // 생성자: numberOfContact 멤버 변수 초기화 및 contactInfo 메모리 할당
    Contact();

    // 소멸자: contactInfo 메모리 해제
    ~Contact();

    // 연락처 정보 입력
    void inputContact(ContactType contact);

    // 연락처 전체 목록 조회
    void printContactList();

    // 연락처 상세 조회: index 
    void printContact(int index);

    // 연락처 상세 조회: 이름 (함수 오버로딩)
    void printContact(const string inName);

    // 연락처 수정
    void editContactByIndex(int index, ContactType contact);

    // 연락처 복사
    void copyContact(int index);

    // 연락처 제거
    void removeContactByIndex(int index);

    // 연락처 얻어오기
    ContactType getContact(int index);
};

// 생성자: numberOfContact 멤버 변수 초기화 및 contactInfo 메모리 할당
template <typename ContactType>
Contact<ContactType>::Contact()
{
    contactInfo = new ContactType[100]; // 동적할당
    numberOfContact = 0;			    // 연락처 숫자 초기화 
}

// 소멸자: contactInfo 메모리 해제
template <typename ContactType>
Contact<ContactType>::~Contact()
{
    delete[] contactInfo; 	// 동적할당 해제
    numberOfContact = 0;    // 연락처 숫자 초기화
}

// 연락처 정보 입력
template <typename ContactType>
void Contact<ContactType>::inputContact(ContactType contact)
{
    contactInfo[numberOfContact] = ContactType(contact);
    numberOfContact++;
}

// 연락처 전체 목록 조회
template <typename ContactType>
void Contact<ContactType>::printContactList()
{
    int i;
    string name;
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

// 연락처 상세 조회: 이름 (함수 오버로딩)
template <typename ContactType>
void Contact<ContactType>::printContact(const string inName)
{
    int i;

    cout << inName << "의 이름을 가진 연락처 조회" << endl;

    for (i = 0; i< numberOfContact; i++)
    {
        if (contactInfo[i].getName().compare(inName) == 0)
            contactInfo[i].print();
    }
}


// 연락처 수정
template <typename ContactType>
void Contact<ContactType>::editContactByIndex(int index, ContactType contact)
{
    contactInfo[index] = ContactType(contact);
}

// 연락처 복사
template <typename ContactType>
void Contact<ContactType>::copyContact(int index)
{
    contactInfo[numberOfContact] = ContactType(contactInfo[index]);
    numberOfContact++;
}

// 연락처 제거
template <typename ContactType>
void Contact<ContactType>::removeContactByIndex(int index)
{
    // index가 0보다 작거나 contactNumber보다 크면 삭제 불가
    if ((index >= numberOfContact) || (index < 0))
    {
        cout << index << "는 삭제가 불가능한 인덱스 입니다. " << endl;
        return;
    }

    int i;
    for (i = index + 1; i < numberOfContact; i++)
    {
        contactInfo[i - 1] = contactInfo[i];
    }

    numberOfContact--;
}

template <typename ContactType>
ContactType Contact<ContactType>::getContact(int index)
{
    return contactInfo[index];
}

#endif