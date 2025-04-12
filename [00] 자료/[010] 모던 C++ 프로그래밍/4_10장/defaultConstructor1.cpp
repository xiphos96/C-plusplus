#include <iostream>
using namespace std;

#define NAME_LEN 20
#define SEX_LEN 10
#define JOB_LEN 20
#define CHARACTER_LEN 20

class Chulsoo
{
private:
	char name[NAME_LEN];
	char sex[SEX_LEN];
	char job[JOB_LEN];
	char character[CHARACTER_LEN];
	int age;
	bool marriageStatus;
public:
	void introduce();
	void eat(char * food);
	void sleep();
	void drive(char * destination);
	void write();
	void read();
};

int main(void)
{
	Chulsoo chulsoo; // ö�� ��ü ���� -> ����Ʈ ������ ȣ��
	chulsoo.drive("�������");
	chulsoo.eat("������ũ");
	chulsoo.drive("��");
	chulsoo.write();
	chulsoo.read();
	chulsoo.sleep();
	cout << endl;
	chulsoo.introduce();
	return 0;
}

void Chulsoo::introduce()
{
	cout << "�̸�: " << name << endl;
	cout << "����: " << sex << endl;
	cout << "����: " << job << endl;
	cout << "����: " << character << endl;
	cout << "����: " << age << endl;
	cout << "��ȥ����: " << (marriageStatus ? "YES" : "NO") << endl;
}

void Chulsoo::eat(char * food)
{
	cout << "ö���� " << food << "�� �Դ´�" << endl;
}

void Chulsoo::sleep()
{
	cout << "ö���� �ܴ�" << endl;
}

void Chulsoo::drive(char * destination)
{
	cout << "ö���� " << destination << "���� �����Ѵ�" << endl;
}

void Chulsoo::write()
{
	cout << "ö���� å�� ����" << endl;
}

void Chulsoo::read()
{
	cout << "ö���� å�� �д´�" << endl;
}