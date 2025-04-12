#include "Controller.h"
using namespace std;

// 생성자 - 연락처별 저장 파일 이름 설정
Controller::Controller() : contacts("contact.dat"), twitterContacts("twitcontact.dat")
{
}

// 소유자 정보 입력
void Controller::inputOwnerInfo()
{
    string name;              // 이름
    string phoneNumber;       // 전화번호
    string email;             // 이메일
    string address;           // 주소
    string twitterAccount;    // 트위터 계정

    cout << "소유자 이름: ";
    cin >> name;
    cout << "소유자 전화번호: ";
    cin >> phoneNumber;
    cout << "소유자 이메일: ";
    cin >> email;
    cout << "소유자 주소: ";
    cin >> address;
    cout << "소유자 트위터 계정: ";
    cin >> twitterAccount;
    cout << "입력이 완료 되었습니다." << endl;

    owner.input(name, phoneNumber, email, address, twitterAccount);
}

// 소유자 정보 출력
void Controller::printOwnerInfo()
{
    owner.print();
}

// 소유자 정보 수정
void Controller::editOwnerInfo()
{
    string editString;
    int inputNum;
    cout << "1. 소유자 이름 수정" << endl;
    cout << "2. 소유자 전화번호 수정" << endl;
    cout << "3. 소유자 이메일 수정" << endl;
    cout << "4. 소유자 주소 수정" << endl;
    cout << "5. 소유자 트위터 계정 수정" << endl;
    cout << "6. 수정 없이 이전 메뉴로" << endl;
    cin >> inputNum;

    switch (inputNum)
    {
    case 1:
        cout << "수정할 이름 : ";
        cin >> editString;
        owner.edit(&editString, NULL, NULL, NULL, NULL);
        cout << "소유자의 이름이 수정되었습니다. " << endl;
        break;
    case 2:
        cout << "수정할 전화번호 : ";
        cin >> editString;
        owner.edit(NULL, &editString, NULL, NULL, NULL);
        cout << "소유자의 전화번호가 수정되었습니다. " << endl;
        break;
    case 3:
        cout << "수정할 이메일 : ";
        cin >> editString;
        owner.edit(NULL, NULL, &editString, NULL, NULL);
        cout << "소유자의 이메일이 수정되었습니다. " << endl;
        break;
    case 4:
        cout << "수정할 주소 : ";
        cin >> editString;
        owner.edit(NULL, NULL, NULL, &editString, NULL);
        cout << "소유자의 주소가 수정되었습니다. " << endl;
        break;
    case 5:
        cout << "수정할 트위터 계정 : ";
        cin >> editString;
        owner.edit(NULL, NULL, NULL, NULL, &editString);
        cout << "소유자의 트위터 계정이 수정되었습니다. " << endl;
        break;

    default:
        cout << "아무것도 수정되지 않았습니다." << endl;
    }
}

// 연락처 정보 입력
void Controller::addContact()
{
    string name;              // 이름
    string phoneNumber;       // 전화번호
    string email;             // 이메일
    string address;           // 주소
    cout << "연락처 이름: ";
    cin >> name;
    cout << "연락처 전화번호: ";
    cin >> phoneNumber;
    cout << "연락처 이메일: ";
    cin >> email;
    cout << "연락처 주소: ";
    cin >> address;

    PersonalContact personalContact;
    personalContact.input(name, phoneNumber, email, address);
    contacts.inputContact(personalContact);
}

// 연락처 전체 목록 조회
void Controller::printContactList()
{
    contacts.printContactList();
}

// 연락처 상세 조회
void Controller::printContactDetail()
{
    int inputNum;
    int index;
    string name;
    cout << "1. index로 연락처 조회" << endl;
    cout << "2. 이름으로 연락처 조회" << endl;
    cin >> inputNum;

    switch (inputNum)
    {
    case 1:
        cout << "조회할 연락처 index : ";
        cin >> index;
        contacts.printContact(index);
        break;
    case 2:
        cout << "조회할 연락처 이름 : ";
        cin >> name;
        contacts.printContact(name);
        break;
    default:
        cout << "잘못 입력했습니다. 이전메뉴로 돌아갑니다." << endl;
    }
}

// 연락처 수정
void Controller::editContact()
{
    int index;
    cout << "수정할 연락처 index : ";
    cin >> index;

    string editString;
    int inputNum;
    cout << "1. 연락처 이름 수정" << endl;
    cout << "2. 연락처 전화번호 수정" << endl;
    cout << "3. 연락처 이메일 수정" << endl;
    cout << "4. 연락처 주소 수정" << endl;
    cout << "5. 수정 없이 이전 메뉴로" << endl;
    cin >> inputNum;

    PersonalContact personalContact = contacts.getContact(index);

    switch (inputNum)
    {
    case 1:
        cout << "수정할 이름 : ";
        cin >> editString;
        personalContact.edit(&editString, NULL, NULL, NULL);
        cout << "연락처 이름이 수정되었습니다. " << endl;
        break;
    case 2:
        cout << "수정할 전화번호 : ";
        cin >> editString;
        personalContact.edit(NULL, &editString, NULL, NULL);
        cout << "연락처 전화번호가 수정되었습니다. " << endl;
        break;
    case 3:
        cout << "수정할 이메일 : ";
        cin >> editString;
        personalContact.edit(NULL, NULL, &editString, NULL);
        cout << "연락처 이메일이 수정되었습니다. " << endl;
        break;
    case 4:
        cout << "수정할 주소 : ";
        cin >> editString;
        personalContact.edit(NULL, NULL, NULL, &editString);
        cout << "연락처 주소가 수정되었습니다. " << endl;
        break;
    default:
        cout << "아무것도 수정되지 않았습니다." << endl;
    }

    contacts.editContactByIndex(index, personalContact);
}

// 연락처 복사
void Controller::copyContact()
{
    int index;
    cout << "복사할 연락처 index : ";
    cin >> index;

    contacts.copyContact(index);
}

// 연락처 제거
void Controller::removeContact()
{
    int index;
    cout << "삭제할 연락처 index : ";
    cin >> index;

    contacts.removeContactByIndex(index);
}

// 트위터 팔로잉 목록 연락처 동기화
void Controller::syncTwitter()
{
    twitter.syncContacts(twitterContacts);
}

// 트위터 타임라인 조회
void Controller::getTwitterTimeline()
{
    twitter.getTimeline();
}

// 특정 사용자 트위터 타임라인 조회
void Controller::getTwitterUserTimeline()
{
    string screen_id;
    cout << "타임라인을 조회할 트위터 아이디 : ";
    cin >> screen_id;
    twitter.getUserTimeline(screen_id);
}

// 최근 수신 메시지 조회
void Controller::getTwitterReceivedMessages()
{
    twitter.getReceivedMessages();
}

// 최근 송신 메시지 조회
void Controller::getTwitterSentMessages()
{
    twitter.getSentMessages();
}

// 새로운 메시지 전송
void Controller::sendTwitterMessage()
{
    string screen_name;
    string text;
    cout << "메시시 받을 트위터 이름 : ";
    cin >> screen_name;
    cout << "메시지 내용 : ";
    cin >> text;
    if (twitter.sentMessage(screen_name, text) == false)
    {
        cout << "메시지 전송에 실패했습니다." << endl;
    }
    else
    {
        cout << "메시지 전송에 성공했습니다." << endl;
    }
}

// 트위터 연락처 목록 조회
void Controller::printTwitterContactList()
{
    twitterContacts.printContactList();
}

// 트위터 연락처 상세 조회
void Controller::printTwitterContactDetail()
{
    int inputNum;
    int index;
    string name;
    cout << "1. index로 연락처 조회" << endl;
    cout << "2. 이름으로 연락처 조회" << endl;
    cin >> inputNum;

    switch (inputNum)
    {
    case 1:
        cout << "조회할 연락처 index : ";
        cin >> index;
        twitterContacts.printContact(index);
        break;
    case 2:
        cout << "조회할 연락처 이름 : ";
        cin >> name;
        twitterContacts.printContact(name);
        break;
    default:
        cout << "잘못 입력했습니다. 이전메뉴로 돌아갑니다." << endl;
    }
}

// 소유자 메뉴 실행
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
            saveOwnerInfo();                // 소유자 저장 기능 추가
            break;
        case 5:
            cout << "이전 메뉴로 돌아 갑니다." << endl;
            break;
        default:
            cout << "잘못 입력 했습니다. 다시 해주세요" << endl;
        }
    } while (menuNum != 5);

}

// 연락처 메뉴 실행
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
            saveScontact();              // 연락처 저장 기능 추가
            break;
        case 8:
            cout << "이전 메뉴로 돌아 갑니다." << endl;
            break;
        default:
            cout << "잘못 입력 했습니다. 다시 해주세요" << endl;
        }
    } while (menuNum != 8);
}

// 트위터 메뉴 실행
void Controller::runTwitterMenu()
{
    // password 받기
    string id, pw;

    // 트위터 비밀번호 받기
    cout << "트위터 비밀번호 : ";
    cin >> pw;

    // 소유자로 부터 트위터 아이디 얻어오기
    owner.get(NULL, NULL, NULL, NULL, &id);
    twitter.setUserName(id);
    twitter.setPassword(pw);

    // ConsumerKey 및 SecretKey 설정
    twitter.setConsumerKey(string("LJ4uJuOE4hEYG3OiCrftQ"));
    twitter.setConsumerSecret(string("vlYbnhUwLp0pEt8fISQyqet5Iw5wu5kW4RWOtERx8"));

    if (twitter.performAuth() == false)
    {
        cout << "트위터 접속 인증에 실패했습니다. 트위터 관리 메뉴를 실행할 수 없습니다. " << endl;
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
            saveTwitterContact();           // 트위터 연락처 자장 기능 추가
            break;
        case 10:
            cout << "이전 메뉴로 돌아 갑니다." << endl;
            break;
        default:
            cout << "잘못 입력 했습니다. 다시 해주세요" << endl;
        }
    } while (menuNum != 10);
}

// 연락처 메뉴 실행
void Controller::runMainMenu()
{
    int menuNum;
    do{
        menu.setMenuSelection(0);   // 최상위 메뉴 설정
        menuNum = menu.execution(); // 메뉴 실행

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
            cout << "프로그램을 종료합니다" << endl;
            break;
        default:
            cout << "잘못 입력 했습니다. 다시 해주세요" << endl;
        }
    } while (menuNum != 4);
}

// 소유자 정보 파일 저장
void Controller::saveOwnerInfo()
{
    owner.save();
}

// 연락처 파일 저장
void Controller::saveScontact()
{
    contacts.save();
    cout << "파일저장 완료했습니다" << endl;
}

// 트위처 연락처 파일 저장
void Controller::saveTwitterContact()
{
    twitterContacts.save();
    cout << "파일저장 완료했습니다" << endl;
}