#include "Contact.h"

using namespace std;

// ������
Contact::Contact()
{
    numberOfContact =0;
}

// ����ó ���� �Է�
void Contact::inputContact(char *name, char *phoneNumber, char *email, char *address)
{
    contactInfo[numberOfContact].inputContact(name,phoneNumber,email,
        address);
    numberOfContact++;
}

// ����ó ��ü ��� ��ȸ
void Contact::printContactList()
{
    int i;
    char name[30];
    for(i=0; i< numberOfContact; i++)
    {
        contactInfo[i].getContact(name,NULL,NULL,NULL);
        cout<<i<<" : "<<name<<endl;
    }
}

// ����ó �� ��ȸ: index 
void Contact::printContact(int index)
{
    char name[20];          
    char phoneNumber[13];       
    char email[30];               
    char address[50];           

    contactInfo[index].getContact(name,phoneNumber,email,address);
    cout << index << "�� index�� ���� ����ó ��ȸ" << endl;
    cout << "����ó �̸�: " << name << endl;
    cout << "����ó ��ȭ��ȣ: " << phoneNumber << endl;
    cout << "����ó �̸���: " << email << endl;
    cout << "����ó �ּ�: " << address << endl;
}

// ����ó �� ��ȸ: �̸� (�Լ� �����ε�)
void Contact::printContact(char *inName)
{
    char name[20];          
    char phoneNumber[13];       
    char email[30];               
    char address[50];           

    int i;

    cout << inName << "�� �̸��� ���� ����ó ��ȸ" << endl;
    
    for(i=0; i< numberOfContact; i++)
    {
        contactInfo[i].getContact(name,phoneNumber,email,address);
        if (strcmp(inName, name) == 0)
        {
            
            cout << "����ó �̸�: " << name << endl;
            cout << "����ó ��ȭ��ȣ: " << phoneNumber << endl;
            cout << "����ó �̸���: " << email << endl;
            cout << "����ó �ּ�: " << address << endl;
        }
    }
}


// ����ó ����
void Contact::editContactByIndex(int index, char *name, char *phoneNumber, char *email, char *address)
{
    contactInfo[index].editContact(name,phoneNumber,email,address);
}

// ����ó ����
void Contact::copyContact(int index)
{
    contactInfo[numberOfContact] = PersonalContact(contactInfo[index]);
    numberOfContact++;
}

// ����ó ����
void Contact::removeContactByIndex(int index)
{
    // index�� 0���� �۰ų� contactNumber���� ũ�� ���� �Ұ�
 	if ((index >= numberOfContact) || (index < 0))
  	{
        cout<<index<<"�� ������ �Ұ����� �ε��� �Դϴ�. "<<endl;
        return ;
    }

    int i;
  	for (i = index + 1; i < numberOfContact; i++)
  	{
  		contactInfo[i - 1] = contactInfo[i];
  	}
  
  	numberOfContact--;
}