#ifndef _CONTROLLER_H_
#define _CONTROLLER_H_

#include "Contact.h"
#include "Menu.h"
#include "Owner.h"
#include "Twitter.h"
#include "TwitterContact.h"

class Controller{
private:
    Contact<PersonalContact> contacts;         // 연락처 관리
    Contact<TwitterContact>  twitterContacts;  // 트위터 연락처 관리
    Menu    menu;       // 메뉴 
    Owner   owner;      // 소유자 관리
    Twitter twitter;    // 트위터 관리

    // 소유자 정보 입력
    void inputOwnerInfo();

    // 소유자 정보 출력
    void printOwnerInfo();

    // 소유자 정보 수정
    void editOwnerInfo();

    // 소유자 정보 파일 저장
    void saveOwnerInfo();


    // 연락처 정보 입력
    void addContact();

    // 연락처 전체 목록 조회
    void printContactList();

    // 연락처 상세 조회
    void printContactDetail();

    // 연락처 수정
    void editContact();

    // 연락처 복사
    void copyContact();

    // 연락처 제거
    void removeContact();

    // 연락처 파일 저장
    void saveScontact();


    // 트위터 following 목록 연락처 동기화
    void syncTwitter();

    // 트위터 타임라인 조회
    void getTwitterTimeline();

    // 특정 사용자 트위터 타임라인 조회
    void getTwitterUserTimeline();

    // 최근 수신 메시지 조회
    void getTwitterReceivedMessages();

    // 최근 송신 메시지 조회
    void getTwitterSentMessages();

    // 새로운 메시지 전송
    void sendTwitterMessage();

    // 트위터 연락처 목록 조회
    void printTwitterContactList();

    // 트위터 연락처 상세 조회
    void printTwitterContactDetail();

    // 트위처 연락처 파일 저장
    void saveTwitterContact();


    // 소유자 메뉴 실행
    void runOwnerMenu();

    // 연락처 메뉴 실행
    void runContactMenu();

    // 트위터 메뉴 실행
    void runTwitterMenu();

public:
    // 메인 메뉴 실행
    void runMainMenu();

    // 생성자
    Controller();
};

#endif