#include <iostream>
using namespace std;

class File
{
public:
	void load()
	{
		cout << "mp3 ������ �޸𸮿� �ø��ϴ�." << endl;
	}
};

class PowerDevice
{
public:
	void powerUp()
	{
		cout << "mp3 play�� ���� �Ŀ��� �ø��ϴ�." << endl;
	}
};

class Memory
{
public:
	void expand()
	{
		cout << "mp3 play�� ���� �޸𸮸� �ø��ϴ�." << endl;
	}
};

class Mp3
{
private:
	File file;
	PowerDevice powerdevice;
	Memory memory;
public:
	void play()
	{
		powerdevice.powerUp();
		memory.expand();
		file.load();
		cout << "mp3�� play �մϴ�." << endl;
	}
};

int main()
{
	Mp3 mp3;
	mp3.play();
}