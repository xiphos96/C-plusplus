#include <iostream>

class Menu  {
private:
    char topMenu[3][32];                 // �ֻ��� �޴� ����
    char ownerMenu[4][32];               // ������ �޴� ����
    char contactMenu[7][32];             // ����ó �޴� ����
    int menuType;   // 0 top menu, 1 ownermenu, 2 contactmenu

public:
    // ������
    Menu();    

    // ���� �޴� ���� ���¸� ���� �޴� ��� ���
    void showMenu();             

    // ù��° �ܰ� �޴� ����
    void setMenuSelection(int selection); 

    // ������ �޴� ����
    int execution();                      
};
