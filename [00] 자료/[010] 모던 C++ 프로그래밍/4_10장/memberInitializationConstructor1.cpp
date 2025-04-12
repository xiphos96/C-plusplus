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
	Chulsoo(char * name, char * sex, char * job, char * character, int age, bool marriageStatus)
	{
		cout << "Chulsoo::Chulsoo(name,sex,job,character,age,marriageStatus) ������ ����" << endl;
		strcpy_s(this->name, name);
		strcpy_s(this->sex, sex);
		strcpy_s(this->job, job);
		strcpy_s(this->character, character);
		this->age = age;
		this->marriageStatus = marriageStatus;
		cout << "Chulsoo::Chulsoo(name,sex,job,character,age,marriageStatus) ������ �Ϸ�" << endl;
	}
	Chulsoo() 
	{
		cout << "Chulsoo::Chulsoo() ������ �Ϸ�" << endl;
	}
	void introduce();
	void eat(char * food);
	void sleep();
	void drive(char * destination);
	void write();
	void read();
};

class Younghee
{
private:
	char name[NAME_LEN];
	char sex[SEX_LEN];
	char job[JOB_LEN];
	char character[CHARACTER_LEN];
	int age;
	bool marriageStatus;
public:
	Younghee(char * name, char * sex, char * job, char * character, int age, bool marriageStatus)
	{
		cout << "Younghee::Younghee(name,sex,job,character,age,marriageStatus) ������ ����" << endl;
		strcpy_s(this->name, name);
		strcpy_s(this->sex, sex);
		strcpy_s(this->job, job);
		strcpy_s(this->character, character);
		this->age = age;
		this->marriageStatus = marriageStatus;
		cout << "Younghee::Younghee(name,sex,job,character,age,marriageStatus) ������ �Ϸ�" << endl;
	}
	Younghee() 
	{
		cout << "Younghee::Younghee() ������ �Ϸ�" << endl;
	}
	void introduce();
	void eat(char * food);
	void sleep();
	void shopping();
};

class DailyLife
{
private:
	Chulsoo chulsoo; // ��ü�� private ����� ������.
	Younghee younghee; // ��ü�� private ����� ������.
public:
	DailyLife(Chulsoo chulsooObject, Younghee youngheeObject)
	{
		cout << "DailyLife::DailyLife(chulsooObject, youngheeObject) ������ ����" << endl;
		chulsoo = chulsooObject;
		younghee = youngheeObject;
		cout << "DailyLife::DailyLife(chulsooObject, youngheeObject) ������ �Ϸ�" << endl;
	}
	void run()
	{
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
	}
};

int main(void)
{
	Chulsoo chulsoo("ö��", "����", "�۰�", "diligent", 32, true);
	Younghee younghee("����", "����", "�ֺ�", "impatient", 32, true);
	DailyLife dailylife(chulsoo, younghee);
	dailylife.run();
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

void Younghee::introduce()
{
	cout << "�̸�: " << name << endl;
	cout << "����: " << sex << endl;
	cout << "����: " << job << endl;
	cout << "����: " << character << endl;
	cout << "����: " << age << endl;
	cout << "��ȥ����: " << (marriageStatus ? "YES" : "NO") << endl;
}

void Younghee::eat(char * food)
{
	cout << "����� " << food << "�� �Դ´�" << endl;
}

void Younghee::sleep()
{
	cout << "����� �ܴ�" << endl;
}

void Younghee::shopping()
{
	cout << "����� ������ �Ѵ�" << endl;
}