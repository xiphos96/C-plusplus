#include <iostream>

class Owner  {
private:
    char name[20];              // �̸�
    char phoneNumber[13];       // ��ȭ��ȣ
    char email[30];             // �̸���
    char address[50];           // �ּ�
    char twitterAccount[20];    // Ʈ���� ����

public: 
    // ������ ���� �Է�
    void inputOwnerInfo(char *inName, char *inPhoneNumber=NULL, char *inEmail=NULL, char *inAddress=NULL, char *inTwitterAccount=NULL);

    // ������ ���� ���
    void printOwnerInfo();         

    // ������ ���� ����
    void editOwnerInfo(char *inName, char *inPhoneNumber = NULL, char *inEmail = NULL, char *inAddress = NULL, char *inTwitterAccount = NULL);
};
