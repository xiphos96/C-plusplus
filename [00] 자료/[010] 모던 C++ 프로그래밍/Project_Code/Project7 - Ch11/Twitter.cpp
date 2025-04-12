#include "Twitter.h"

// 생성자 
Twitter::Twitter()
{
}

// 소멸자 
Twitter::~Twitter()
{
}

// 사용자 ID설정
void Twitter::setUserName(const string inUserName)
{
    userName = inUserName;
}

// 비밀번호 설정
void Twitter::setPassword(const string inPassword)
{
    password = inPassword;
}

// ConsumerKey 설정
void Twitter::setConsumerKey(const string inConsumerKey)
{
    consumerKey = inConsumerKey;
}

// ConsumerSecret 설정
void Twitter::setConsumerSecret(const string inConsumerSecret)
{
    consumerSecret = inConsumerSecret;
}

// 트위터 인증 수행
bool Twitter::performAuth()
{
    twitterObj.setTwitterUsername(userName);
    twitterObj.setTwitterPassword(password);

    // ConsumerKey 및 SecretKey 생성
    twitterObj.setConsumerKey(consumerKey);
    twitterObj.setConsumerSecret(consumerSecret);

    if (twitterObj.performAuth() == false)
    {
        return false;
    }

    return true;
}

// 트위터 팔로잉 목록 연락처 동기화
void Twitter::syncContacts(Contact<TwitterContact> &inContact)
{
    // 트위터 팔로잉 아이디 불러오기 
    // friendsIdsGet 함수 호출, friends/ids에 request를 보낸다. 
    string cursor="";
    if (twitterObj.friendsIdsGet(cursor, userName) == false){
        cout << "friends/ids 요청에 실패했습니다." << endl;
        return;
    }
    string result;
    
    // ids항목을 파싱해서 가져온다. 
    result = twitterObj.friendsIdsParse("ids");
    // 사용자 아이디를 이요한 user/lookup 조회
    if (twitterObj.userLookup(result, true) == false){
        cout << "user/lookup 요청에 실패했습니다." << endl;
        return;
    };
    
    // name 항목 파싱후 가져오기
    string resultName = twitterObj.userLookupParse("name");
    string resultId = twitterObj.userLookupParse("id_str");
    string resultLocation = twitterObj.userLookupParse("location");
    string resultUrl = twitterObj.userLookupParse("url");
    string resultAccount = twitterObj.userLookupParse("screen_name");

    // deliminator 분리
    string delimiter = ",";
    int pos = 0;
    string name,id,location,url,account,description;
    int i;
    int numberTimeline = twitterObj.userLookupNumber();
    for (i = 0; i < numberTimeline; i++)
    {
        pos = resultName.find(delimiter);
        name = resultName.substr(0, pos);
        resultName.erase(0, pos + delimiter.length());

        pos = resultId.find(delimiter);
        id = resultId.substr(0, pos);
        resultId.erase(0, pos + delimiter.length());

        pos = resultLocation.find(delimiter);
        location = resultLocation.substr(0, pos);
        resultLocation.erase(0, pos + delimiter.length());

        pos = resultUrl.find(delimiter);
        url = resultUrl.substr(0, pos);
        resultUrl.erase(0, pos + delimiter.length());

        pos = resultAccount.find(delimiter);
        account = resultAccount.substr(0, pos);
        resultAccount.erase(0, pos + delimiter.length());


        description = twitterObj.userLookupParse(i);

        TwitterContact twitterContact;
        twitterContact.input(id, name, account, location, description, url);
        inContact.inputContact(twitterContact);
        cout << name << " 연동 완료" << endl;
    }
}

// 트위터 타임라인 조회
void Twitter::getTimeline()
{
    string result_name;
    string result_screen_name;
    string result_created_at;
    if (twitterObj.timelineHomeGet() == false){
        cout << "Error!!" << endl;
    }

    result_name = twitterObj.timelineParse("name") + ",";
    result_screen_name = twitterObj.timelineParse("screen_name") +",";
    result_created_at = twitterObj.timelineParse("created_at")+",";

    cout << "-----------------------------------------------------------------" << endl;
    // deliminator 분리
    string delimiter = ",";
    int pos = 0;
    string token;
    int i;
    int numberTimeline = twitterObj.timelineNumber();
    for (i = 0; i < numberTimeline; i++)
    {
        pos = result_name.find(delimiter);
        token = result_name.substr(0, pos);
        result_name.erase(0, pos + delimiter.length());
        cout << token << "@";

        pos = result_screen_name.find(delimiter);
        token = result_screen_name.substr(0, pos);
        result_screen_name.erase(0, pos + delimiter.length());
        cout << token << " - ";

        pos = result_created_at.find(delimiter);
        token = result_created_at.substr(0, pos);
        result_created_at.erase(0, pos + delimiter.length());
        cout << token << endl;

        token = twitterObj.timelineParse(i);
        cout << token << endl;
        cout << "-----------------------------------------------------------------" << endl;
    }
    
}

// 특정 사용자 트위터 타임라인 조회
void Twitter::getUserTimeline(const string screen_name)
{
    string result_name;
    string result_screen_name;
    string result_created_at;
    if (twitterObj.timelineUserGet(false, false, 10, screen_name, false) == false){
        cout << "Error!!" << endl;
    }

    result_name = twitterObj.timelineParse("name") + ",";
    result_screen_name = twitterObj.timelineParse("screen_name") + ",";
    result_created_at = twitterObj.timelineParse("created_at") + ",";

    cout << "-----------------------------------------------------------------" << endl;
    // deliminator 분리
    string delimiter = ",";
    int pos = 0;
    string token;
    int i;
    int numberTimeline = twitterObj.timelineNumber();
    for (i = 0; i < numberTimeline; i++)
    {
        pos = result_name.find(delimiter);
        token = result_name.substr(0, pos);
        result_name.erase(0, pos + delimiter.length());
        cout << token << "@";

        pos = result_screen_name.find(delimiter);
        token = result_screen_name.substr(0, pos);
        result_screen_name.erase(0, pos + delimiter.length());
        cout << token << " - ";

        pos = result_created_at.find(delimiter);
        token = result_created_at.substr(0, pos);
        result_created_at.erase(0, pos + delimiter.length());
        cout << token << endl;

        token = twitterObj.timelineParse(i);
        cout << token << endl;
        cout << "-----------------------------------------------------------------" << endl;
    }
}

// 최근 수신 메시지 조회
void Twitter::getReceivedMessages()
{
    // 받은 메시지 조회
    if (twitterObj.directMessageGet() == false){
        cout << "Error!!" << endl;
    }
    string resultSenderName;
    string resultSenderScreenName;
    string resultCreatedAt;

    resultSenderName = twitterObj.directMessageGetParse("s_name") + ",";
    resultSenderScreenName = twitterObj.directMessageGetParse("s_screen_name") + ",";
    resultCreatedAt = twitterObj.directMessageGetParse("created_at") + ",";

    cout << "-----------------------------------------------------------------" << endl;
    // deliminator 분리
    string delimiter = ",";
    int pos = 0;
    string token;
    int i;
    int numberTimeline = twitterObj.directMessageGetNumber();
    for (i = 0; i < numberTimeline; i++)
    {
        pos = resultSenderName.find(delimiter);
        token = resultSenderName.substr(0, pos);
        resultSenderName.erase(0, pos + delimiter.length());
        cout <<"보낸 사람 : "<< token << "@";

        pos = resultSenderScreenName.find(delimiter);
        token = resultSenderScreenName.substr(0, pos);
        resultSenderScreenName.erase(0, pos + delimiter.length());
        cout << token << " - ";

        pos = resultCreatedAt.find(delimiter);
        token = resultCreatedAt.substr(0, pos);
        resultCreatedAt.erase(0, pos + delimiter.length());
        cout << token << endl;

        token = twitterObj.timelineParse(i);
        cout << token << endl;
        cout << "-----------------------------------------------------------------" << endl;
    }
}

// 최근 송신 메시지 조회
void Twitter::getSentMessages()
{
    if (twitterObj.directMessageGetSent() == false){
        cout << "Error!!" << endl;
    }
    
    string resultRecipientName;
    string resultRecipientScreenName;
    string resultCreatedAt;

    resultRecipientName = twitterObj.directMessageGetParse("r_name") + ",";
    resultRecipientScreenName = twitterObj.directMessageGetParse("r_screen_name") + ",";
    resultCreatedAt = twitterObj.directMessageGetParse("created_at") + ",";

    cout << "-----------------------------------------------------------------" << endl;
    // deliminator 분리
    string delimiter = ",";
    int pos = 0;
    string token;
    int i;
    int numberTimeline = twitterObj.directMessageGetNumber();
    for (i = 0; i < numberTimeline; i++)
    {
        pos = resultRecipientName.find(delimiter);
        token = resultRecipientName.substr(0, pos);
        resultRecipientName.erase(0, pos + delimiter.length());
        cout <<"받은 사람 : "<< token << "@";

        pos = resultRecipientScreenName.find(delimiter);
        token = resultRecipientScreenName.substr(0, pos);
        resultRecipientScreenName.erase(0, pos + delimiter.length());
        cout << token << " - ";

        pos = resultCreatedAt.find(delimiter);
        token = resultCreatedAt.substr(0, pos);
        resultCreatedAt.erase(0, pos + delimiter.length());
        cout << token << endl;

        token = twitterObj.timelineParse(i);
        cout << token << endl;
        cout << "-----------------------------------------------------------------" << endl;
    }

}

// 새로운 메시지 전송
bool Twitter::sentMessage(string screen_name, string text)
{
    if (twitterObj.directMessageSend(screen_name, text, false) == false){
        return false;
    }

    return true;
}