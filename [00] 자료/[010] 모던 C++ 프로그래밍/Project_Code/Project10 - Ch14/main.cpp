#include "Controller.h"
#include "OwnerException.h"
//#include <exception>
int main()
{
    try{
        Controller control;
        control.runMainMenu();
    }
    catch (OwnerException e)
    {
        cout << "Owner 클래스에서 예외 오류가 발생 했습니다. 오류는 다음과 같습니다." << endl;
        cout << e.what() << endl;
    }
    catch (std::ios_base::failure e)
    {
        cout << "Owner 클래스에서 파일을 읽고/쓰는 중에 오류가 발생 했습니다. 오류는 다음과 같습니다." << endl;
        cout << e.what() << endl;
    }
    return 0;
}