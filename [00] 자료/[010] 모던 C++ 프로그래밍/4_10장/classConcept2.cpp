#include <iostream>
using namespace std;

#define NAME_LEN 20
#define SEX_LEN 10
#define JOB_LEN 20
#define CHARACTER_LEN 20

class Chulsoo
{
	char name[NAME_LEN];
	char sex[SEX_LEN];
	char job[JOB_LEN];
	char character[CHARACTER_LEN];
	int age;
	bool marriageStatus;
	
	void introduce()
	{
		cout << "�̸�: " << name << endl;
		cout << "����: " << sex << endl;
		cout << "����: " << job << endl;
		cout << "����: " << character << endl;
		cout << "����: " << age << endl;
		cout << "��ȥ����: " << (marriageStatus ? "YES" : "NO") << endl;
	}

	void eat(char * food)
	{
		cout << "ö���� " << food << "�� �Դ´�" << endl;
	}

	void sleep()
	{
		cout << "ö���� �ܴ�" << endl;
	}

	void drive(char * destination)
	{
		cout << "ö���� " << destination << "���� �����Ѵ�" << endl;
	}

	void write()
	{
		cout << "ö���� å�� ����" << endl;
	}

	void read()
	{
		cout << "ö���� å�� �д´�" << endl;
	}

public:
	void constructor(char * name, char * sex, char * job, char * character, int age, bool marriageStatus)
	{
		strcpy_s(this->name, name);
		strcpy_s(this->sex, sex);
		strcpy_s(this->job, job);
		strcpy_s(this->character, character);
		this->age = age;
		this->marriageStatus = marriageStatus;
	}
};

class Younghee
{
	char name[NAME_LEN];
	char sex[SEX_LEN];
	char job[JOB_LEN];
	char character[CHARACTER_LEN];
	int age;
	bool marriageStatus;

	void introduce()
	{
		cout << "�̸�: " << name << endl;
		cout << "����: " << sex << endl;
		cout << "����: " << job << endl;
		cout << "����: " << character << endl;
		cout << "����: " << age << endl;
		cout << "��ȥ����: " << (marriageStatus ? "YES" : "NO") << endl;
	}

	void eat(char * food)
	{
		cout << "����� " << food << "�� �Դ´�" << endl;
	}

	void sleep()
	{
		cout << "����� �ܴ�" << endl;
	}

	void shopping()
	{
		cout << "����� ������ �Ѵ�" << endl;
	}

public:
	void constructor(char * name, char * sex, char * job, char * character, int age, bool marriageStatus)
	{
		strcpy_s(this->name, name);
		strcpy_s(this->sex, sex);
		strcpy_s(this->job, job);
		strcpy_s(this->character, character);
		this->age = age;
		this->marriageStatus = marriageStatus;
	}
};

int main(void)
{
	Chulsoo chulsoo;
	Younghee younghee;
	chulsoo.constructor("ö��", "����", "�۰�", "diligent", 32, true);
	younghee.constructor("����", "����", "�ֺ�", "impatient", 32, true);

	chulsoo.drive("�������");
	chulsoo.eat("������ũ");
	younghee.eat("������ũ");
	chulsoo.drive("��");
	younghee.sleep();
	chulsoo.write();
	chulsoo.read();
	chulsoo.sleep();
	cout << endl;
	chulsoo.introduce();
	cout << endl;
	younghee.introduce();

	return 0;
}