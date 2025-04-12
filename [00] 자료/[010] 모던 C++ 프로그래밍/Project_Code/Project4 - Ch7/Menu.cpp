#include "Menu.h"
using namespace std;

// �ֻ��� �޴� ���� ����
Menu::Menu()                
{
    strcpy_s(topMenu[0], 32, "1. ������ ���� ���");
    strcpy_s(topMenu[1], 32, "2. ����ó ���� ���� ���");
    strcpy_s(topMenu[2], 32, "3. ���α׷� ����");

    strcpy_s(ownerMenu[0], 32, "1. ������ ���� �Է�");
    strcpy_s(ownerMenu[1], 32, "2. ������ ���� ��ȸ");
    strcpy_s(ownerMenu[2], 32, "3. ������ ���� ����");
    strcpy_s(ownerMenu[3], 32, "4. ���� �޴���");

    strcpy_s(contactMenu[0], 32, "1. ����ó �߰� �Է�");
    strcpy_s(contactMenu[1], 32, "2. ����ó ��� ��ȸ");
    strcpy_s(contactMenu[2], 32, "3. ����ó �� ��ȸ");
    strcpy_s(contactMenu[3], 32, "4. ���� ����ó ����");
    strcpy_s(contactMenu[4], 32, "5. ����ó ����");
    strcpy_s(contactMenu[5], 32, "6. ���� ����ó ����");
    strcpy_s(contactMenu[6], 32, "7. ���� �޴���");

    // �޴� �⺻�� 0(�ֻ��� �޴�)
    menuType = 0;
}

// ���� �޴� ���� ���¸� ���� �޴� ��� ���
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

// ù��° �ܰ� �޴� ����
void Menu::setMenuSelection(int selection)       
{
    menuType = selection;
}

// ������ �޴� ����
int Menu::execution()                  
{
    int selection;
    showMenu();
    cin>>selection;
    return selection;
}