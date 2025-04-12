#include <iostream>

using namespace std;

int main()
{
    char name[512];
    try
    {
        cout << "이름을 입력하세요: ";
        cin >> name;

        if (strlen(name) <= 2)
        {
            throw name;
        }

        cout << "저의 이름은 " << name << "입니다." << endl;
    }
    catch (char *e)
    {
        cout << "예외 발생. 잘못된 입력 값: " << e << '\n';
    }
    return 0;
}