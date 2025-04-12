#ifndef _CONTACT_H_
#define _CONTACT_H_

#include <iostream>
#include "PersonalContact.h"

using namespace std;

class Owner;

class Contact  {
private:
    PersonalContact *contactInfo;        // 연락처 저장 가능한 포인터: 동적할당
    int numberOfContact;                 // 현재 저장된 연락처 개수

public:
    // 생성자: numberOfContact 멤버 변수 초기화 및 contactInfo 메모리 할당
    Contact();

    // 소멸자: contactInfo 메모리 해제
    ~Contact();

    // 연락처 정보 입력
    void inputContact(char *name, char *phoneNumber = NULL, char *email = NULL, char *address = NULL);

    // 연락처 전체 목록 조회
    void printContactList();

    // 연락처 상세 조회 - index 
    void printContact(int index);

    // 연락처 상세 조회 - 이름 (함수 오버로딩)
    void printContact(char *name);

    // 연락처 수정
    void editContactByIndex(int index, char *name, char *phoneNumber = NULL, char *email = NULL, char *address = NULL);

    // 연락처 복사
    void copyContact(int index);

    // 연락처 제거
    void removeContactByIndex(int index);

    // 트위터 연락처 연동
    void retrieveTwitterFollowing(Owner &owner);
};

#endif