#include "Twitter.h"

// ������ 
Twitter::Twitter()
{
}

// �Ҹ��� 
Twitter::~Twitter()
{
}

// ����� ID����
void Twitter::setUserName(const string inUserName)
{
    userName = inUserName;
}

// ��й�ȣ ����
void Twitter::setPassword(const string inPassword)
{
    password = inPassword;
}

// ConsumerKey ����
void Twitter::setConsumerKey(const string inConsumerKey)
{
    consumerKey = inConsumerKey;
}

// ConsumerSecret ����
void Twitter::setConsumerSecret(const string inConsumerSecret)
{
    consumerSecret = inConsumerSecret;
}

// Ʈ���� ���� ����
bool Twitter::performAuth()
{
    twitterObj.setTwitterUsername(userName);
    twitterObj.setTwitterPassword(password);

    // ConsumerKey �� SecretKey ����
    twitterObj.setConsumerKey(consumerKey);
    twitterObj.setConsumerSecret(consumerSecret);

    if (twitterObj.performAuth() == false)
    {
        return false;
    }

    return true;
}

// Ʈ���� �ȷ��� ��� ����ó ����ȭ
void Twitter::syncContacts(Contact &inContact)
{
    // Ʈ���� follow ���̵� �ҷ����� 
    // friendsIdsGet �Լ� ȣ��, friends/ids�� request�� ������. 
    string cursor="";
    if (twitterObj.friendsIdsGet(cursor, userName) == false){
        cout << "friends/ids ��û�� �����߽��ϴ�." << endl;
        return;
    }
    string result;
    
    // ids�׸��� �Ľ��ؼ� �����´�. 
    result = twitterObj.friendsIdsParse("ids");
    // ����� ���̵� �̿��� user/lookup ��ȸ
    if (twitterObj.userLookup(result, true) == false){
        cout << "user/lookup ��û�� �����߽��ϴ�." << endl;
        return;
    };

    // name �׸� �Ľ��� ��������
    result = twitterObj.userLookupParse("name");
    
    // deliminator �и�
    std::string delimiter = ",";
    int pos = 0;
    std::string token;
    while ((pos = result.find(delimiter)) != std::string::npos) {
        token = result.substr(0, pos);
        
        inContact.inputContact(token, "", "", "");
        cout << token << " ���� �Ϸ�" << endl;
        
        result.erase(0, pos + delimiter.length());
    }
    
    inContact.inputContact(result, "", "", "");
    cout << result << " ���� �Ϸ�" << endl;
}

// Ʈ���� Ÿ�Ӷ��� ��ȸ
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
    // deliminator �и�
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

// Ư�� ����� Ʈ���� Ÿ�Ӷ��� ��ȸ
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
    // deliminator �и�
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

// �ֱ� ���� �޽��� ��ȸ
void Twitter::getReceivedMessages()
{
    // ���� �޽��� ��ȸ
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
    // deliminator �и�
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
        cout <<"���� ��� : "<< token << "@";

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

// �ֱ� �۽� �޽��� ��ȸ
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
    // deliminator �и�
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
        cout <<"���� ��� : "<< token << "@";

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

// ���ο� �޽��� ����
bool Twitter::sendMessage(string screen_name, string text)
{
    if (twitterObj.directMessageSend(screen_name, text, false) == false){
        return false;
    }

    return true;
}