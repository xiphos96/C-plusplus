#include <iostream>
#include <string>
#include <tuple>

using namespace std;

tuple<int, string> getAgeandName()
{
    int age;
    string name;
    cout << "���̸� �Է��ϼ���: ";
    cin >> age;

    cout << "�̸��� �Է��ϼ���: ";
    cin >> name;

    return make_tuple(age, name);
}

int main()
{
    tuple<int, string> personInfo;

    personInfo = getAgeandName();

    cout << "����: " << get<0>(personInfo) << endl;
    cout << "�̸�: " << get<1>(personInfo) << endl;

    return 0;
}