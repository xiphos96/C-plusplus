#include "Menu.h"

// 최상위 메뉴 정보 설정
Menu::Menu()
{
    topMenu.push_back("1. 소유자 관리 기능");
    topMenu.push_back("2. 연락처 관리 기능");
    topMenu.push_back("3. 트위터 관리 기능");
    topMenu.push_back("4. 프로그램 종료");

    ownerMenu.push_back("1. 소유자 정보 입력");
    ownerMenu.push_back("2. 소유자 정보 조회");
    ownerMenu.push_back("3. 소유자 정보 수정");
    ownerMenu.push_back("4. 이전 메뉴로");

    contactMenu.push_back("1. 연락처 추가 입력");
    contactMenu.push_back("2. 연락처 목록 조회");
    contactMenu.push_back("3. 연락처 상세 조회");
    contactMenu.push_back("4. 개별 연락처 수정");
    contactMenu.push_back("5. 연락처 복사");
    contactMenu.push_back("6. 개별 연락처 제거");
    contactMenu.push_back("7. 이전 메뉴로");

    twitterMenu.push_back("1. 트위터 팔로잉 목록 연락처 동기화");
    twitterMenu.push_back("2. 트위터 타림라인 조회");
    twitterMenu.push_back("3. 특정 사용자 트위터 타임라인 조회");
    twitterMenu.push_back("4. 최근 수신 메세지 조회");
    twitterMenu.push_back("5. 최근 송신 메세지 조회");
    twitterMenu.push_back("6. 새로운 메세지 전송");
    twitterMenu.push_back("7. 트위터 연락처 목록 조회"); 
    twitterMenu.push_back("8. 트위터 연락처 상세 조회"); 
    twitterMenu.push_back("9. 이전 메뉴로");

    // 메뉴 기본값 0(최상위 메뉴)
    menuType = 0;
}

// 현재 메뉴 선택 상태를 통해 메뉴 목록 출력
void Menu::showMenu()
{
    int i;
    if (menuType == 0)
    {
        for (i = 0; i < topMenu.size(); i++)
            cout << topMenu[i] << endl;
    }
    else if (menuType == 1)
    {
        for (i = 0; i < ownerMenu.size(); i++)
            cout << ownerMenu[i] << endl;
    }
    else if (menuType == 2)
    {
        for (i = 0; i < contactMenu.size(); i++)
            cout << contactMenu[i] << endl;
    }
    else if (menuType == 3)
    {
        for (i = 0; i < twitterMenu.size(); i++)
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