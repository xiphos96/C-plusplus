#include <iostream>

class PersonalContact  {
private:
    char name[20];               // �̸�
    char phoneNumber[13];        // ��ȭ��ȣ
    char email[30];              // �̸���
    char address[50];            // �ּ�

public:
    // �⺻ ������
    PersonalContact(){}

    // ���� ������
    PersonalContact(PersonalContact &personal);

    // ����ó �Է�
    void inputContact(char *inName, char *inPhoneNumber = NULL, char *inEmail = NULL, char *inAddress = NULL);
    
    // ����ó ��ȸ
    void getContact(char *outName, char *outPhoneNumber, char *outEmail, char *outAddress);
    
    // ����ó ����
    void editContact(char *inName, char *inPhoneNumber = NULL, char *inEmail = NULL, char *inAddress = NULL);
};

