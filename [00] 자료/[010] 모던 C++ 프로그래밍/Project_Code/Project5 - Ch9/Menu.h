#ifndef _MENU_H_
#define _MENU_H_

#include <iostream>

class Menu  {
private:
    char **topMenu;                   // 최상위 메뉴 정보
    char **ownerMenu;                 // 소유자 메뉴 정보
    char **contactMenu;               // 연락처 메뉴 정보
    int menuType;                     // 0: 최상위 메뉴, 1: 소유자 메뉴, 2: 연락처 메뉴

    const int numTopMenu = 3;         // Top메뉴 숫자
    const int numOwnerMenu = 4;       // 소유자 관리 메뉴 숫자
    const int numContactMenu = 8;     // 연락처 관리 메뉴 숫자
public:
    // Menu 생성자
    Menu();

    // Menu 소멸자
    ~Menu();

    // 현재 메뉴 선택 상태를 통해 메뉴 목록 출력
    void showMenu();

    // 첫번째 단계 메뉴 선택
    void setMenuSelection(int selection);

    // 선택한 메뉴 실행
    int execution();
};

#endif