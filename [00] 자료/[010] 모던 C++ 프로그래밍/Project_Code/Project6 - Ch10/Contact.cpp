#include "Contact.h"

using namespace std;

// 생성자: numberOfContact 멤버 변수 초기화 및 contactInfo 메모리 할당
Contact::Contact()
{
    contactInfo = new PersonalContact[100]; // 동적할당
    numberOfContact = 0;			        // 연락처 숫자 초기화 
}

// 소멸자: contactInfo 메모리 해제
Contact::~Contact()
{
    delete[] contactInfo; 	// 동적할당 해제
    numberOfContact = 0;    // 연락처 숫자 초기화
}

// 연락처 정보 입력
void Contact::inputContact(const string inName, const string inPhoneNumber , const string inEmail , const string inAddress )
{
    contactInfo[numberOfContact].input(inName, inPhoneNumber, inEmail, inAddress);
    numberOfContact++;
}

// 연락처 전체 목록 조회
void Contact::printContactList()
{
    int i;
    string name;
    for (i = 0; i< numberOfContact; i++)
    {
        contactInfo[i].get(&name, NULL, NULL, NULL);
        cout << i << " : "<< name << endl;
    }
}

// 연락처 상세 조회 - index 
void Contact::printContact(int index)
{
    string name;
    string phoneNumber;
    string email;
    string address;

    contactInfo[index].get(&name, &phoneNumber, &email, &address);
    cout << index << "의 index를 가진 연락처 조회" << endl;
    cout << "연락처 이름: " << name << endl;
    cout << "연락처 전화번호: " << phoneNumber << endl;
    cout << "연락처 이메일: " << email << endl;
    cout << "연락처 주소: " << address << endl;
}

// 연락처 상세 조회 - 이름 (함수 오버로딩)
void Contact::printContact(const string inName)
{
    string name;
    string phoneNumber;
    string email;
    string address;

    int i;

    cout << inName << "의 이름을 가진 연락처 조회" << endl;

    for (i = 0; i< numberOfContact; i++)
    {
        contactInfo[i].get(&name, &phoneNumber, &email, &address);
        if (inName.compare(name) == 0)
        {
            cout << "연락처 이름: " << name << endl;
            cout << "연락처 전화번호: " << phoneNumber << endl;
            cout << "연락처 이메일: " << email << endl;
            cout << "연락처 주소: " << address << endl;
        }
    }
}

// 연락처 수정
void Contact::editContactByIndex(int index, const string *inName, const string *inPhoneNumber , const string *inEmail , const string *inAddress )
{
    contactInfo[index].edit(inName, inPhoneNumber, inEmail, inAddress);
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