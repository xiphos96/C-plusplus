#include "Menu.h"
using namespace std;

Menu::Menu()                // 최상위 메뉴 정보 설정
{
    topMenu = new char*[numTopMenu];
    ownerMenu = new char*[numOwnerMenu];
    contactMenu = new char*[numContactMenu];

    int i;
    for (i = 0; i < numTopMenu; i++)
        topMenu[i] = new char[50];

    for (i = 0; i < numOwnerMenu; i++)
        ownerMenu[i] = new char[50];

    for (i = 0; i < numContactMenu; i++)
        contactMenu[i] = new char[50];

    strcpy_s(topMenu[0], 50, "1. 소유자 관리 기능");
    strcpy_s(topMenu[1], 50, "2. 연락처 관리 기능");
    strcpy_s(topMenu[2], 50, "3. 프로그램 종료");

    strcpy_s(ownerMenu[0], 50, "1. 소유자 정보 입력");
    strcpy_s(ownerMenu[1], 50, "2. 소유자 정보 조회");
    strcpy_s(ownerMenu[2], 50, "3. 소유자 정보 수정");
    strcpy_s(ownerMenu[3], 50, "4. 이전 메뉴로");

    strcpy_s(contactMenu[0], 50, "1. 연락처 추가 입력");
    strcpy_s(contactMenu[1], 50, "2. 연락처 목록 조회");
    strcpy_s(contactMenu[2], 50, "3. 연락처 상세 조회");
    strcpy_s(contactMenu[3], 50, "4. 개별 연락처 수정");
    strcpy_s(contactMenu[4], 50, "5. 연락처 복사");
    strcpy_s(contactMenu[5], 50, "6. 개별 연락처 제거");
    strcpy_s(contactMenu[6], 50, "7. 트위터 연락처 연동");
    strcpy_s(contactMenu[7], 50, "8. 이전 메뉴로");

    // 메뉴 기본값 0(최상위 메뉴)
    menuType = 0;
}

Menu::~Menu()                           // 소멸자 – 메뉴 정보 메모리 해제
{
    int i;
    for (i = 0; i < numTopMenu; i++)
        delete[] topMenu[i];

    for (i = 0; i < numOwnerMenu; i++)
        delete[] ownerMenu[i];

    for (i = 0; i < numContactMenu; i++)
        delete[] contactMenu[i];

    delete[] topMenu;
    delete[] ownerMenu;
    delete[] contactMenu;
}

void Menu::showMenu()                 // 현재 메뉴 선택 상태를 통해 메뉴 목록 출력
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
}

void Menu::setMenuSelection(int selection)       // 첫번째 단계 메뉴 선택
{
    menuType = selection;
}

int Menu::execution()                  // 선택한 메뉴 실행
{
    int selection;
    showMenu();
    cin >> selection;
    return selection;
}