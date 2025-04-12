#ifndef _MENU_H_
#define _MENU_H_

#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Menu  {
private:
    vector<string> topMenu;        // 최상위 메뉴 정보
    vector<string> ownerMenu;      // 소유자 메뉴 정보
    vector<string> contactMenu;    // 연락처 메뉴 정보
    vector<string> twitterMenu;    // 트위터 메뉴 정보
    int menuType;           // 0: 최상위 메뉴, 1: 소유자 메뉴, 2: 연락처 메뉴, 3: 트위터 메뉴

public:
    // 생성자: 메뉴 정보 메모리 할당
    Menu();

    // 현재 메뉴 선택 상태를 통해 메뉴 목록 출력
    void showMenu();

    // 메뉴 선택
    void setMenuSelection(int selection);

    // 선택한 메뉴 실행
    int execution();
};

#endif