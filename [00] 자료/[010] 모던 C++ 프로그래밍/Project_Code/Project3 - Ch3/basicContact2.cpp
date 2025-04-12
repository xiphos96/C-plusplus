#include <iostream>
using namespace std;

struct OwnerInfo {
    char name[20];           // 이름
    char phoneNumber[13];    // 전화번호
    char email[30];          // 이메일
    char address[50];        // 주소
    char twitterAccount[20]; // 트위터 계정
};

struct ContactInfo {
    char name[20];           // 이름
    char phoneNumber[13];    // 전화번호
    char email[30];          // 이메일
    char address[50];        // 주소
};

OwnerInfo owner;
ContactInfo contacts[100];
int contactNumber = 0;

void inputOwnerInfo();		 // 소유자 정보 입력
void ouputOwnerInfo();		 // 소유자 정보 조회
void editOwnerInfo();        // 소유자 정보 수정

void addContact();                      // 연락처 추가 입력
void ouputContactList();                // 연락처 목록 조회
int removeContactByIndex(int index);    // 연락처 삭제
void printContactInfoByIndex(int index);// 연락처 상세 조회

void runMainMenu();            // 메인메뉴 실행
void runOwnerMenu();           // 소유자 관리 메뉴실행
void runContactMenu();         // 연락처 관리 메뉴실행

// 소유자 정보 입력
void inputOwnerInfo()
{
    cout << "소유자 이름: ";
    cin >> owner.name;

    cout << "소유자 전화번호: ";
    cin >> owner.phoneNumber;

    cout << "소유자 이메일: ";
    cin >> owner.email;

    cout << "소유자 주소: ";
    cin >> owner.address;

    cout << "소유자 트위터 계정: ";
    cin >> owner.twitterAccount;

    cout << "입력이 완료 되었습니다." << endl;
}

// 소유자 정보 조회
void ouputOwnerInfo()
{
    cout << "소유자 이름: " << owner.name << endl;
    cout << "소유자 전화번호: " << owner.phoneNumber << endl;
    cout << "소유자 이메일: " << owner.email << endl;
    cout << "소유자 주소: " << owner.address << endl;
    cout << "소유자 트위터 계정: " << owner.twitterAccount << endl;
}

// 소유자 정보 수정
void editOwnerInfo()
{
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
        cin >> owner.name;
        cout << "소유자의 이름이 수정되었습니다. " << endl;
        break;
    case 2:
        cin >> owner.phoneNumber;
        cout << "소유자의 전화번호가 수정되었습니다. " << endl;
        break;
    case 3:
        cin >> owner.email;
        cout << "소유자의 이메일이 수정되었습니다. " << endl;
        break;
    case 4:
        cin >> owner.address;
        cout << "소유자의 주소가 수정되었습니다. " << endl;
        break;
    case 5:
        cin >> owner.twitterAccount;
        cout << "소유자의 트위터 계정이 수정되었습니다. " << endl;
        break;
    default:
        cout << "아무것도 수정되지 않았습니다." << endl;
    }
}

// 연락처 추가 입력
void addContact()
{
    cout << "연락처 이름: ";
    cin >> contacts[contactNumber].name;

    cout << "연락처 전화번호: ";
    cin >> contacts[contactNumber].phoneNumber;

    cout << "연락처 이메일: ";
    cin >> contacts[contactNumber].email;

    cout << "연락처 주소: ";
    cin >> contacts[contactNumber].address;

    contactNumber++;
    cout << "입력이 완료 되었습니다." << endl;
}

// 연락처 목록 조회
void ouputContactList()
{
    int i;

    for (i = 0; i < contactNumber; i++)
    {
        cout << i << " : " << contacts[i].name << endl;
    }
}

// 연락처 삭제
int removeContactByIndex(int index)
{
    // index가 0보다 작거나 contactNumber보다 크면 삭제 불가
    if ((index >= contactNumber) || (index < 0))
        return 0;
    int i;
    for (i = index + 1; i < contactNumber; i++)
    {
        *(contacts + i - 1) = *(contacts + i);
    }
    contactNumber--;
 
    return 1;
}

// 연락처 상세 조회
void printContactInfoByIndex(int index)
{
    cout << index << "의 index를 가진 연락처 조회" << endl;
    cout << "연락처 이름: " << contacts[index].name << endl;
    cout << "연락처 전화번호: " << contacts[index].phoneNumber << endl;
    cout << "연락처 이메일: " << contacts[index].email << endl;
    cout << "연락처 주소: " << contacts[index].address << endl;
}

// 메인메뉴 실행
void runMainMenu()
{
    int menuNum;

    do{
        cout << "1. 소유자 관리 기능" << endl;
        cout << "2. 연락처 관리 기능" << endl;
        cout << "3. 프로그램 종료" << endl;
        cin >> menuNum;

        switch (menuNum)
        {
        case 1:
            runOwnerMenu();
            break;
        case 2:
            runContactMenu();
            break;
        case 3:
            cout << "프로그램을 종료 합니다." << endl;
            break;
        default:
            cout << "잘못 입력 했습니다. 다시 해주세요" << endl;

        }

    } while (menuNum != 3);

}

// 소유자 관리 메뉴실행
void runOwnerMenu()
{
    int menuNum;

    do{
        cout << "1. 소유자 정보 입력" << endl;
        cout << "2. 소유자 정보 조회" << endl;
        cout << "3. 소유자 정보 수정" << endl;
        cout << "4. 이전 화면" << endl;
        cin >> menuNum;
        switch (menuNum)
        {
        case 1:
            inputOwnerInfo();
            break;
        case 2:
            ouputOwnerInfo();
            break;
        case 3:
            editOwnerInfo();
            break;
        case 4:
            cout << "이전 화면으로 돌아 갑니다." << endl;
            break;
        default:
            cout << "잘못 입력 했습니다. 다시 해주세요" << endl;
        }
    } while (menuNum != 4);
}

// 연락처 관리 메뉴실행
void runContactMenu()
{
    int menuNum;
    int result;
    int index;
    do{
        cout << "1. 연락처 추가 입력" << endl;
        cout << "2. 연락처 목록 조회" << endl;
        cout << "3. 연락처 삭제" << endl;
        cout << "4. 연락처 상세 조회" << endl;
        cout << "5. 이전 화면" << endl;
        cin >> menuNum;
        switch (menuNum)
        {
        case 1:
            addContact();
            break;
        case 2:
            ouputContactList();
            break;
        case 3:
            cout << "삭제할 연락처 index : ";
            cin >> index;
            result = removeContactByIndex(index);
            if (result == 1)
                cout << "정상적으로 삭제되었습니다." << endl;
            else
                cout << "정상적으로 삭제되지 않았습니다." << endl;
            break;
        case 4:
            cout << "조회할 연락처 index : ";
            cin >> index;
            printContactInfoByIndex(index);
            break;
        case 5:
            cout << "이전 화면으로 돌아 갑니다." << endl;
            break;
        default:
            cout << "잘못 입력 했습니다. 다시 해주세요" << endl;
        }
    } while (menuNum != 5);
}

int main()
{
    runMainMenu();
    return 0;
}
