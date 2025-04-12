#include <iostream>

using namespace std;

void inputName(char *name)
{
    cout << "�̸��� �Է��ϼ���: ";
    cin >> name;

    if (strlen(name) <= 2)
        throw name;    
}

int inputAge()
{
    int age;
    cout << "���̸� �Է��ϼ���: ";
    cin >> age;

    if (age < 1)
        throw age;

    return age;
}

int main()
{
    char name[512];
    int age;
    try
    {
        inputName(name);
        age = inputAge();
        
        cout << "���� �̸��� " << name << "�Դϴ�." << endl;
        cout << "���� ���̴� " << age << "�Դϴ�." << endl;
    }
    catch (char *e)
    {
        cout << "���� �߻�. �߸��� �̸� �Է�: " << e << '\n';
    }
    catch (int e)
    {
        cout << "���� �߻�. �߸��� ���� �Է�: " << e << '\n';
    }
    return 0;
}