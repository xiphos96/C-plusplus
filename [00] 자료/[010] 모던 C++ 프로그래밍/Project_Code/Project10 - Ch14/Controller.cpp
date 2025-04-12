#include "Controller.h"
using namespace std;

// ������ - ����ó�� ���� ���� �̸� ����
Controller::Controller() : contacts("contact.dat"), twitterContacts("twitcontact.dat")
{
}

// ������ ���� �Է�
void Controller::inputOwnerInfo()
{
    string name;              // �̸�
    string phoneNumber;       // ��ȭ��ȣ
    string email;             // �̸���
    string address;           // �ּ�
    string twitterAccount;    // Ʈ���� ����

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

    owner.input(name, phoneNumber, email, address, twitterAccount);
}

// ������ ���� ���
void Controller::printOwnerInfo()
{
    owner.print();
}

// ������ ���� ����
void Controller::editOwnerInfo()
{
    string editString;
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
        owner.edit(&editString, NULL, NULL, NULL, NULL);
        cout << "�������� �̸��� �����Ǿ����ϴ�. " << endl;
        break;
    case 2:
        cout << "������ ��ȭ��ȣ : ";
        cin >> editString;
        owner.edit(NULL, &editString, NULL, NULL, NULL);
        cout << "�������� ��ȭ��ȣ�� �����Ǿ����ϴ�. " << endl;
        break;
    case 3:
        cout << "������ �̸��� : ";
        cin >> editString;
        owner.edit(NULL, NULL, &editString, NULL, NULL);
        cout << "�������� �̸����� �����Ǿ����ϴ�. " << endl;
        break;
    case 4:
        cout << "������ �ּ� : ";
        cin >> editString;
        owner.edit(NULL, NULL, NULL, &editString, NULL);
        cout << "�������� �ּҰ� �����Ǿ����ϴ�. " << endl;
        break;
    case 5:
        cout << "������ Ʈ���� ���� : ";
        cin >> editString;
        owner.edit(NULL, NULL, NULL, NULL, &editString);
        cout << "�������� Ʈ���� ������ �����Ǿ����ϴ�. " << endl;
        break;

    default:
        cout << "�ƹ��͵� �������� �ʾҽ��ϴ�." << endl;
    }
}

// ����ó ���� �Է�
void Controller::addContact()
{
    string name;              // �̸�
    string phoneNumber;       // ��ȭ��ȣ
    string email;             // �̸���
    string address;           // �ּ�
    cout << "����ó �̸�: ";
    cin >> name;
    cout << "����ó ��ȭ��ȣ: ";
    cin >> phoneNumber;
    cout << "����ó �̸���: ";
    cin >> email;
    cout << "����ó �ּ�: ";
    cin >> address;

    PersonalContact personalContact;
    personalContact.input(name, phoneNumber, email, address);
    contacts.inputContact(personalContact);
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
    string name;
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

    string editString;
    int inputNum;
    cout << "1. ����ó �̸� ����" << endl;
    cout << "2. ����ó ��ȭ��ȣ ����" << endl;
    cout << "3. ����ó �̸��� ����" << endl;
    cout << "4. ����ó �ּ� ����" << endl;
    cout << "5. ���� ���� ���� �޴���" << endl;
    cin >> inputNum;

    PersonalContact personalContact = contacts.getContact(index);

    switch (inputNum)
    {
    case 1:
        cout << "������ �̸� : ";
        cin >> editString;
        personalContact.edit(&editString, NULL, NULL, NULL);
        cout << "����ó �̸��� �����Ǿ����ϴ�. " << endl;
        break;
    case 2:
        cout << "������ ��ȭ��ȣ : ";
        cin >> editString;
        personalContact.edit(NULL, &editString, NULL, NULL);
        cout << "����ó ��ȭ��ȣ�� �����Ǿ����ϴ�. " << endl;
        break;
    case 3:
        cout << "������ �̸��� : ";
        cin >> editString;
        personalContact.edit(NULL, NULL, &editString, NULL);
        cout << "����ó �̸����� �����Ǿ����ϴ�. " << endl;
        break;
    case 4:
        cout << "������ �ּ� : ";
        cin >> editString;
        personalContact.edit(NULL, NULL, NULL, &editString);
        cout << "����ó �ּҰ� �����Ǿ����ϴ�. " << endl;
        break;
    default:
        cout << "�ƹ��͵� �������� �ʾҽ��ϴ�." << endl;
    }

    contacts.editContactByIndex(index, personalContact);
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

// Ʈ���� �ȷ��� ��� ����ó ����ȭ
void Controller::syncTwitter()
{
    twitter.syncContacts(twitterContacts);
}

// Ʈ���� Ÿ�Ӷ��� ��ȸ
void Controller::getTwitterTimeline()
{
    twitter.getTimeline();
}

// Ư�� ����� Ʈ���� Ÿ�Ӷ��� ��ȸ
void Controller::getTwitterUserTimeline()
{
    string screen_id;
    cout << "Ÿ�Ӷ����� ��ȸ�� Ʈ���� ���̵� : ";
    cin >> screen_id;
    twitter.getUserTimeline(screen_id);
}

// �ֱ� ���� �޽��� ��ȸ
void Controller::getTwitterReceivedMessages()
{
    twitter.getReceivedMessages();
}

// �ֱ� �۽� �޽��� ��ȸ
void Controller::getTwitterSentMessages()
{
    twitter.getSentMessages();
}

// ���ο� �޽��� ����
void Controller::sendTwitterMessage()
{
    string screen_name;
    string text;
    cout << "�޽ý� ���� Ʈ���� �̸� : ";
    cin >> screen_name;
    cout << "�޽��� ���� : ";
    cin >> text;
    if (twitter.sentMessage(screen_name, text) == false)
    {
        cout << "�޽��� ���ۿ� �����߽��ϴ�." << endl;
    }
    else
    {
        cout << "�޽��� ���ۿ� �����߽��ϴ�." << endl;
    }
}

// Ʈ���� ����ó ��� ��ȸ
void Controller::printTwitterContactList()
{
    twitterContacts.printContactList();
}

// Ʈ���� ����ó �� ��ȸ
void Controller::printTwitterContactDetail()
{
    int inputNum;
    int index;
    string name;
    cout << "1. index�� ����ó ��ȸ" << endl;
    cout << "2. �̸����� ����ó ��ȸ" << endl;
    cin >> inputNum;

    switch (inputNum)
    {
    case 1:
        cout << "��ȸ�� ����ó index : ";
        cin >> index;
        twitterContacts.printContact(index);
        break;
    case 2:
        cout << "��ȸ�� ����ó �̸� : ";
        cin >> name;
        twitterContacts.printContact(name);
        break;
    default:
        cout << "�߸� �Է��߽��ϴ�. �����޴��� ���ư��ϴ�." << endl;
    }
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
            saveOwnerInfo();                // ������ ���� ��� �߰�
            break;
        case 5:
            cout << "���� �޴��� ���� ���ϴ�." << endl;
            break;
        default:
            cout << "�߸� �Է� �߽��ϴ�. �ٽ� ���ּ���" << endl;
        }
    } while (menuNum != 5);

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
            saveScontact();              // ����ó ���� ��� �߰�
            break;
        case 8:
            cout << "���� �޴��� ���� ���ϴ�." << endl;
            break;
        default:
            cout << "�߸� �Է� �߽��ϴ�. �ٽ� ���ּ���" << endl;
        }
    } while (menuNum != 8);
}

// Ʈ���� �޴� ����
void Controller::runTwitterMenu()
{
    // password �ޱ�
    string id, pw;

    // Ʈ���� ��й�ȣ �ޱ�
    cout << "Ʈ���� ��й�ȣ : ";
    cin >> pw;

    // �����ڷ� ���� Ʈ���� ���̵� ������
    owner.get(NULL, NULL, NULL, NULL, &id);
    twitter.setUserName(id);
    twitter.setPassword(pw);

    // ConsumerKey �� SecretKey ����
    twitter.setConsumerKey(string("LJ4uJuOE4hEYG3OiCrftQ"));
    twitter.setConsumerSecret(string("vlYbnhUwLp0pEt8fISQyqet5Iw5wu5kW4RWOtERx8"));

    if (twitter.performAuth() == false)
    {
        cout << "Ʈ���� ���� ������ �����߽��ϴ�. Ʈ���� ���� �޴��� ������ �� �����ϴ�. " << endl;
        return;
    }

    int menuNum;
    do{
        menu.setMenuSelection(3);
        menuNum = menu.execution();

        switch (menuNum)
        {
        case 1:
            syncTwitter();
            break;
        case 2:
            getTwitterTimeline();
            break;
        case 3:
            getTwitterUserTimeline();
            break;
        case 4:
            getTwitterReceivedMessages();
            break;
        case 5:
            getTwitterSentMessages();
            break;
        case 6:
            sendTwitterMessage();
            break;
        case 7:
            printTwitterContactList();
            break;
        case 8:
            printTwitterContactDetail();
            break;
        case 9:
            saveTwitterContact();           // Ʈ���� ����ó ���� ��� �߰�
            break;
        case 10:
            cout << "���� �޴��� ���� ���ϴ�." << endl;
            break;
        default:
            cout << "�߸� �Է� �߽��ϴ�. �ٽ� ���ּ���" << endl;
        }
    } while (menuNum != 10);
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
            runTwitterMenu();
            break;
        case 4:
            cout << "���α׷��� �����մϴ�" << endl;
            break;
        default:
            cout << "�߸� �Է� �߽��ϴ�. �ٽ� ���ּ���" << endl;
        }
    } while (menuNum != 4);
}

// ������ ���� ���� ����
void Controller::saveOwnerInfo()
{
    owner.save();
}

// ����ó ���� ����
void Controller::saveScontact()
{
    contacts.save();
    cout << "�������� �Ϸ��߽��ϴ�" << endl;
}

// Ʈ��ó ����ó ���� ����
void Controller::saveTwitterContact()
{
    twitterContacts.save();
    cout << "�������� �Ϸ��߽��ϴ�" << endl;
}