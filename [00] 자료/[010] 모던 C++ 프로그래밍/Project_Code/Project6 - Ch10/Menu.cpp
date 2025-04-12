#include "Menu.h"

// 생성자 – 메뉴 정보 메모리 할당
Menu::Menu()                
{
    topMenu = new string[numTopMenu];
    ownerMenu = new string[numOwnerMenu];
    contactMenu = new string[numContactMenu];
    twitterMenu = new string[numTwitterMenu];

    topMenu[0] = "1. 소유자 관리 기능";
    topMenu[1] = "2. 연락처 관리 기능";
    topMenu[2] = "3. 트위터 관리 기능";
    topMenu[3] = "4. 프로그램 종료";

    ownerMenu[0] = "1. 소유자 정보 입력";
    ownerMenu[1] = "2. 소유자 정보 조회";
    ownerMenu[2] = "3. 소유자 정보 수정";
    ownerMenu[3] = "4. 이전 메뉴로";

    contactMenu[0] = "1. 연락처 추가 입력";
    contactMenu[1] = "2. 연락처 목록 조회";
    contactMenu[2] = "3. 연락처 상세 조회";
    contactMenu[3] = "4. 개별 연락처 수정";
    contactMenu[4] = "5. 연락처 복사";
    contactMenu[5] = "6. 개별 연락처 제거";
    contactMenu[6] = "7. 이전 메뉴로";

    twitterMenu[0] = "1. 트위터 팔로잉 목록 연락처 동기화";
    twitterMenu[1] = "2. 트위터 타림라인 조회";
    twitterMenu[2] = "3. 특정 사용자 트위터 타임라인 조회";
    twitterMenu[3] = "4. 최근 수신 메시지 조회";
    twitterMenu[4] = "5. 최근 송신 메시지 조회";
    twitterMenu[5] = "6. 새로운 메시지 전송";
    twitterMenu[6] = "7. 이전 메뉴로";

    // 메뉴 기본값 0(최상위 메뉴)
    menuType = 0;
}

// 소멸자 – 메뉴 정보 메모리 해제
Menu::~Menu()                           
{
    delete[] topMenu;
    delete[] ownerMenu;
    delete[] contactMenu;
    delete[] twitterMenu;
}

// 현재 메뉴 선택 상태를 통해 메뉴 목록 출력
void Menu::showMenu()
{
    int i;
    if (menuType == 0)
    {
        for (i = 0; i < numTopMenu; i++)
            cout << topMenu[i] << endl;
    }
    else if (menuType == 1)
    {
        for (i = 0; i < numOwnerMenu; i++)
            cout << ownerMenu[i] << endl;
    }
    else if (menuType == 2)
    {
        for (i = 0; i < numContactMenu; i++)
            cout << contactMenu[i] << endl;
    }
    else if (menuType == 3)
    {
        for (i = 0; i < numTwitterMenu; i++)
            cout << twitterMenu[i] << endl;
    }
}

// 첫번째 단계 메뉴 선택
void Menu::setMenuSelection(int selection)
{
    menuType = selection;
}

// 선택한 메뉴 실행
int Menu::execution()
{
    int selection;
    showMenu();
    cin >> selection;
    return selection;
}