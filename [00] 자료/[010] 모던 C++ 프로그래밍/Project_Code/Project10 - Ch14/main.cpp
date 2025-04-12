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
        cout << "Owner Ŭ�������� ���� ������ �߻� �߽��ϴ�. ������ ������ �����ϴ�." << endl;
        cout << e.what() << endl;
    }
    catch (std::ios_base::failure e)
    {
        cout << "Owner Ŭ�������� ������ �а�/���� �߿� ������ �߻� �߽��ϴ�. ������ ������ �����ϴ�." << endl;
        cout << e.what() << endl;
    }
    return 0;
}