#include <iostream>

using namespace std;

#define UNDERVALUEEXCEPTION -1
#define OVERVALUEEXCEPTION -2
#define NOTMULTIVALUEEXCEPTION -3

int main()
{
    int value;
    try
    {
        cout << "10과 20사이의 7의 배수를 입력하세요: ";
        cin >> value;

        if (value < 10)
            throw UNDERVALUEEXCEPTION;
        else if (value > 20)
            throw OVERVALUEEXCEPTION;
        else if (value % 7 != 0)
            throw NOTMULTIVALUEEXCEPTION;
        else
            cout << "정답!! 10과 20사이의 7의 배수는 " << value << "입니다" << endl;
    }    
    catch (int e)
    {
        if (e == UNDERVALUEEXCEPTION)
            cout << "10이상의 값을 입력하세요" << endl;
        else if (e == OVERVALUEEXCEPTION)
            cout << "20이하의 값을 입력하세요" << endl;
        else if (e == NOTMULTIVALUEEXCEPTION)
            cout << "7의 배수 값을 입력하세요" << endl;            
    }
    return 0;
}