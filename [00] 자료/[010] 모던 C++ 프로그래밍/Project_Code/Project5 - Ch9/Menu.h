#ifndef _MENU_H_
#define _MENU_H_

#include <iostream>

class Menu  {
private:
    char **topMenu;                   // �ֻ��� �޴� ����
    char **ownerMenu;                 // ������ �޴� ����
    char **contactMenu;               // ����ó �޴� ����
    int menuType;                     // 0: �ֻ��� �޴�, 1: ������ �޴�, 2: ����ó �޴�

    const int numTopMenu = 3;         // Top�޴� ����
    const int numOwnerMenu = 4;       // ������ ���� �޴� ����
    const int numContactMenu = 8;     // ����ó ���� �޴� ����
public:
    // Menu ������
    Menu();

    // Menu �Ҹ���
    ~Menu();

    // ���� �޴� ���� ���¸� ���� �޴� ��� ���
    void showMenu();

    // ù��° �ܰ� �޴� ����
    void setMenuSelection(int selection);

    // ������ �޴� ����
    int execution();
};

#endif