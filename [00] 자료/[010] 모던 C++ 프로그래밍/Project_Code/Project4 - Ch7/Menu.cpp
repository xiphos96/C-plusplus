#include "Menu.h"
using namespace std;

// 최상위 메뉴 정보 설정
Menu::Menu()                
{
    strcpy_s(topMenu[0], 32, "1. 소유자 관리 기능");
    strcpy_s(topMenu[1], 32, "2. 연락처 정보 관리 기능");
    strcpy_s(topMenu[2], 32, "3. 프로그램 종료");

    strcpy_s(ownerMenu[0], 32, "1. 소유자 정보 입력");
    strcpy_s(ownerMenu[1], 32, "2. 소유자 정보 조회");
    strcpy_s(ownerMenu[2], 32, "3. 소유자 정보 수정");
    strcpy_s(ownerMenu[3], 32, "4. 이전 메뉴로");

    strcpy_s(contactMenu[0], 32, "1. 연락처 추가 입력");
    strcpy_s(contactMenu[1], 32, "2. 연락처 목록 조회");
    strcpy_s(contactMenu[2], 32, "3. 연락처 상세 조회");
    strcpy_s(contactMenu[3], 32, "4. 개별 연락처 수정");
    strcpy_s(contactMenu[4], 32, "5. 연락처 복사");
    strcpy_s(contactMenu[5], 32, "6. 개별 연락처 제거");
    strcpy_s(contactMenu[6], 32, "7. 이전 메뉴로");

    // 메뉴 기본값 0(최상위 메뉴)
    menuType = 0;
}

// 현재 메뉴 선택 상태를 통해 메뉴 목록 출력
void Menu::showMenu()                 
{
    if( menuType == 0)
    {
        cout<<topMenu[0]<<endl;
        cout<<topMenu[1]<<endl;
        cout<<topMenu[2]<<endl;
    }
    else if(menuType ==1)
    {
        cout<<ownerMenu[0]<<endl;
        cout<<ownerMenu[1]<<endl;
        cout<<ownerMenu[2]<<endl;
        cout<<ownerMenu[3]<<endl;
    }
    else if(menuType == 2)
    {
        cout<<contactMenu[0]<<endl;
        cout<<contactMenu[1]<<endl;
        cout<<contactMenu[2]<<endl;
        cout<<contactMenu[3]<<endl;
        cout<<contactMenu[4]<<endl;
        cout<<contactMenu[5]<<endl;
        cout<<contactMenu[6]<<endl;
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
    cin>>selection;
    return selection;
}