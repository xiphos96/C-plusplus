#include "Contact.h"
#include "freelectwitcurl.h"
#include "Owner.h"

using namespace std;

// 생성자
Contact::Contact()
{
    contactInfo = new PersonalContact[100]; // 동적할당
    numberOfContact = 0;			        // 연락처 숫자 초기화 
}

// 소멸자: contactInfo 메모리 해제
Contact::~Contact()
{
    delete[] contactInfo; 	// 동적할당해제
}

// 연락처 정보 입력
void Contact::inputContact(char *name, char *phoneNumber, char *email, char *address)
{
    contactInfo[numberOfContact].inputContact(name, phoneNumber, email, address);
    numberOfContact++;
}

// 연락처 전체 목록 조회
void Contact::printContactList()
{
    int i;
    char name[30];
    for (i = 0; i< numberOfContact; i++)
    {
        contactInfo[i].getContact(name, NULL, NULL, NULL);
        cout << i << " : " << name << endl;
    }
}

// 연락처 상세 조회: index
void Contact::printContact(int index)
{
    char name[20];
    char phoneNumber[13];
    char email[30];
    char address[50];

    contactInfo[index].getContact(name, phoneNumber, email, address);
    cout << index << "의 index를 가진 연락처 조회" << endl;
    cout << "연락처 이름: " << name << endl;
    cout << "연락처 전화번호: " << phoneNumber << endl;
    cout << "연락처 이메일: " << email << endl;
    cout << "연락처 주소: " << address << endl;
}

// 연락처 상세 조회: 이름 (함수 오버로딩)
void Contact::printContact(char *inName)
{
    char name[20];
    char phoneNumber[13];
    char email[30];
    char address[50];

    int i;

    cout << inName << "의 이름을 가진 연락처 조회" << endl;

    for (i = 0; i< numberOfContact; i++)
    {
        contactInfo[i].getContact(name, phoneNumber, email, address);
        if (strcmp(inName, name) == 0)
        {

            cout << "연락처 이름: " << name << endl;
            cout << "연락처 전화번호: " << phoneNumber << endl;
            cout << "연락처 이메일: " << email << endl;
            cout << "연락처 주소: " << address << endl;
        }
    }
}

// 연락처 수정
void Contact::editContactByIndex(int index, char *name, char *phoneNumber, char *email, char *address)
{
    contactInfo[index].editContact(name, phoneNumber, email, address);
}

// 연락처 복사
void Contact::copyContact(int index)
{
    contactInfo[numberOfContact] = PersonalContact(contactInfo[index]);
    numberOfContact++;
}

// 연락처 제거
void Contact::removeContactByIndex(int index)
{
    // index가 0보다 작거나 contactNumber보다 크면 삭제 불가
    if ((index >= numberOfContact) || (index < 0))
    {
        cout << index << "는 삭제가 불가능한 인덱스 입니다. " << endl;
        return;
    }

    int i;
    for (i = index + 1; i < numberOfContact; i++)
    {
        contactInfo[i - 1] = contactInfo[i];
    }

    numberOfContact--;
}

// 트위터 연락처 연동
void Contact::retrieveTwitterFollowing(Owner &owner)
{
    // freelect-twitCurl 객체
    freelecTwitCurl twitterObj;

    // 트위터 아이디 및 비밀번호 설정
    char passWord[50];

    // 트위터 비밀번호 받기
    cout << "트위터 비밀번호 : ";
    cin >> passWord;

    // twitCurl 객체에 아이디 패스워드 설정
    twitterObj.setTwitterUsername(owner.twitterAccount);
    twitterObj.setTwitterPassword(passWord);

    // ConsumerKey 및 SecretKey 생성
    twitterObj.setConsumerKey("LJ4uJuOE4hEYG3OiCrftQ");
    twitterObj.setConsumerSecret("vlYbnhUwLp0pEt8fISQyqet5Iw5wu5kW4RWOtERx8");

    // 인증 하기 
    if (twitterObj.performAuth() == false)
    {
        cout << "Twitter 인증에 실패했습니다." << endl;
        return;
    }

    // 트위터 follow 아이디 불러오기 
    // friendsIdsGet 함수 호출, friends/ids에 request를 보낸다. 
    if (twitterObj.friendsIdsGet("", owner.twitterAccount) == false){
        cout << "friends/ids 요청에 실패했습니다." << endl;
        return;
    }

    // ids항목을 파싱해서 가져온다. 
    std::string result = twitterObj.friendsIdsParse("ids");

    // ids 항복 상세 조회를 위한 userLookup 함수 호출
    if (twitterObj.userLookup(result, true) == false){
        cout << "user/lookup 요청에 실패했습니다." << endl;
        return;
    };

    // name 항목 파싱후 가져오기
    result = twitterObj.userLookupParse("name");

    // string char* 변환
    char buffer[1000];
    int bufferSize = result.size();
    strcpy_s(buffer, result.c_str());

    // deliminator 분리
    int i, pos = 0;
    char name[20];
    for (i = 0; i < bufferSize; i++)
    {
        if (buffer[i] == ',')
        {
            strncpy_s(name, &buffer[pos], i - pos);
            inputContact(name, NULL, NULL, NULL);
            cout << name << " 연동 완료" << endl;

            pos = i + 1;
        }
    }

    strncpy_s(name, &buffer[pos], i - pos);
    inputContact(name, NULL, NULL, NULL);
    cout << name << " 연동 완료" << endl;
}