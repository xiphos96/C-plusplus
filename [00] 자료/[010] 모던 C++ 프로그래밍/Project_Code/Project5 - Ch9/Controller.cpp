#include "Controller.h"
using namespace std;

// ������ ���� �Է�
void Controller::inputOwnerInfo()
{
    char name[20];               // �̸�
    char phoneNumber[13];        // ��ȭ��ȣ
    char email[30];              // �̸���
    char address[50];            // �ּ�
    char twitterAccount[20];     // Ʈ���� ����

    cout << "������ �̸�: ";
    cin >> name;
    cout << "������ ��ȭ��ȣ: ";
    cin >> phoneNumber;
    cout << "������ �̸���: ";
    cin >> email;
    cout << "������ �ּ�: ";
    cin >> address;
    cout << "������ Ʈ���� ����: ";
    cin >> twitterAccount;
    cout << "�Է��� �Ϸ� �Ǿ����ϴ�." << endl;

    owner.inputOwnerInfo(name, phoneNumber, email, address, twitterAccount);
}

// ������ ���� ���
void Controller::printOwnerInfo()
{
    owner.printOwnerInfo();
}

// ������ ���� ����
void Controller::editOwnerInfo()
{
    char editString[50];
    int inputNum;
    cout << "1. ������ �̸� ����" << endl;
    cout << "2. ������ ��ȭ��ȣ ����" << endl;
    cout << "3. ������ �̸��� ����" << endl;
    cout << "4. ������ �ּ� ����" << endl;
    cout << "5. ������ Ʈ���� ���� ����" << endl;
    cout << "6. ���� ���� ���� �޴���" << endl;
    cin >> inputNum;

    switch (inputNum)
    {
    case 1:
        cout << "������ �̸� : ";
        cin >> editString;
        owner.editOwnerInfo(editString, NULL, NULL, NULL, NULL);
        cout << "�������� �̸��� �����Ǿ����ϴ�. " << endl;
        break;
    case 2:
        cout << "������ ��ȭ��ȣ : ";
        cin >> editString;
        owner.editOwnerInfo(NULL, editString, NULL, NULL, NULL);
        cout << "�������� ��ȭ��ȣ�� �����Ǿ����ϴ�. " << endl;
        break;
    case 3:
        cout << "������ �̸��� : ";
        cin >> editString;
        owner.editOwnerInfo(NULL, NULL, editString, NULL, NULL);
        cout << "�������� �̸����� �����Ǿ����ϴ�. " << endl;
        break;
    case 4:
        cout << "������ �ּ� : ";
        cin >> editString;
        owner.editOwnerInfo(NULL, NULL, NULL, editString, NULL);
        cout << "�������� �ּҰ� �����Ǿ����ϴ�. " << endl;
        break;
    case 5:
        cout << "������ Ʈ���� ���� : ";
        cin >> editString;
        owner.editOwnerInfo(NULL, NULL, NULL, NULL, editString);
        cout << "�������� Ʈ���� ������ �����Ǿ����ϴ�. " << endl;
        break;

    default:
        cout << "�ƹ��͵� �������� �ʾҽ��ϴ�." << endl;
    }
}

// ����ó ���� �Է�
void Controller::addContact()
{
    char name[20];               // �̸�
    char phoneNumber[13];        // ��ȭ��ȣ
    char email[30];              // �̸���
    char address[50];            // �ּ�
    cout << "����ó �̸�: ";
    cin >> name;
    cout << "����ó ��ȭ��ȣ: ";
    cin >> phoneNumber;
    cout << "����ó �̸���: ";
    cin >> email;
    cout << "����ó �ּ�: ";
    cin >> address;

    contacts.inputContact(name, phoneNumber, email, address);
}

// ����ó ��ü ��� ��ȸ
void Controller::printContactList()
{
    contacts.printContactList();
}

// ����ó �� ��ȸ
void Controller::printContactDetail()
{
    int inputNum;
    int index;
    char name[20];
    cout << "1. index�� ����ó ��ȸ" << endl;
    cout << "2. �̸����� ����ó ��ȸ" << endl;
    cin >> inputNum;

    switch (inputNum)
    {
    case 1:
        cout << "��ȸ�� ����ó index : ";
        cin >> index;
        contacts.printContact(index);
        break;
    case 2:
        cout << "��ȸ�� ����ó �̸� : ";
        cin >> name;
        contacts.printContact(name);
        break;
    default:
        cout << "�߸� �Է��߽��ϴ�. �����޴��� ���ư��ϴ�." << endl;
    }
}

// ����ó ����
void Controller::editContact()
{
    int index;
    cout << "������ ����ó index : ";
    cin >> index;

    char editString[50];
    int inputNum;
    cout << "1. ����ó �̸� ����" << endl;
    cout << "2. ����ó ��ȭ��ȣ ����" << endl;
    cout << "3. ����ó �̸��� ����" << endl;
    cout << "4. ����ó �ּ� ����" << endl;
    cout << "5. ���� ���� ���� �޴���" << endl;
    cin >> inputNum;

    switch (inputNum)
    {
    case 1:
        cout << "������ �̸� : ";
        cin >> editString;
        contacts.editContactByIndex(index, editString, NULL, NULL, NULL);
        cout << "����ó �̸��� �����Ǿ����ϴ�. " << endl;
        break;
    case 2:
        cout << "������ ��ȭ��ȣ : ";
        cin >> editString;
        contacts.editContactByIndex(index, NULL, editString, NULL, NULL);
        cout << "����ó ��ȭ��ȣ�� �����Ǿ����ϴ�. " << endl;
        break;
    case 3:
        cout << "������ �̸��� : ";
        cin >> editString;
        contacts.editContactByIndex(index, NULL, NULL, editString, NULL);
        cout << "����ó �̸����� �����Ǿ����ϴ�. " << endl;
        break;
    case 4:
        cout << "������ �ּ� : ";
        cin >> editString;
        contacts.editContactByIndex(index, NULL, NULL, NULL, editString);
        cout << "����ó �ּҰ� �����Ǿ����ϴ�. " << endl;
        break;
    default:
        cout << "�ƹ��͵� �������� �ʾҽ��ϴ�." << endl;
    }
}

// ����ó ����
void Controller::copyContact()
{
    int index;
    cout << "������ ����ó index : ";
    cin >> index;

    contacts.copyContact(index);
}

// ����ó ����
void Controller::removeContact()
{
    int index;
    cout << "������ ����ó index : ";
    cin >> index;

    contacts.removeContactByIndex(index);
}

// Ʈ���� ���� ����
void Controller::syncTwitter()
{
    contacts.retrieveTwitterFollowing(owner);
}

// ������ �޴� ����
void Controller::runOwnerMenu()
{
    int menuNum;
    do{
        menu.setMenuSelection(1);
        menuNum = menu.execution();

        switch (menuNum)
        {
        case 1:
            inputOwnerInfo();
            break;
        case 2:
            printOwnerInfo();
            break;
        case 3:
            editOwnerInfo();
            break;
        case 4:
            cout << "���� �޴��� ���� ���ϴ�." << endl;
            break;
        default:
            cout << "�߸� �Է� �߽��ϴ�. �ٽ� ���ּ���" << endl;
        }
    } while (menuNum != 4);

}

// ����ó �޴� ����
void Controller::runContactMenu()
{
    int menuNum;
    do{
        menu.setMenuSelection(2);
        menuNum = menu.execution();

        switch (menuNum)
        {
        case 1:
            addContact();
            break;
        case 2:
            printContactList();
            break;
        case 3:
            printContactDetail();
            break;
        case 4:
            editContact();
            break;
        case 5:
            copyContact();
            break;
        case 6:
            removeContact();
            break;
        case 7:
            syncTwitter();
            break;
        case 8:
            cout << "���� �޴��� ���� ���ϴ�." << endl;
            break;
        default:
            cout << "�߸� �Է� �߽��ϴ�. �ٽ� ���ּ���" << endl;
        }
    } while (menuNum != 8);
}

// ����ó �޴� ����
void Controller::runMainMenu()
{
    int menuNum;
    do{
        menu.setMenuSelection(0);   // �ֻ��� �޴� ����
        menuNum = menu.execution(); // �޴� ����

        switch (menuNum)
        {
        case 1:
            runOwnerMenu();
            break;
        case 2:
            runContactMenu();
            break;
        case 3:
            cout << "���α׷��� �����մϴ�" << endl;
            break;
        default:
            cout << "�߸� �Է� �߽��ϴ�. �ٽ� ���ּ���" << endl;
        }
    } while (menuNum != 3);
}