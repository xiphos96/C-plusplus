#include <iostream>
using namespace std;

class File
{
public :
	void load()
	{
		cout << "mp3 ������ �޸𸮿� �ø��ϴ�." << endl;
	}
};

class PowerDevice
{
public :
	void powerUp()
	{
		cout << "mp3 play�� ���� �Ŀ��� �ø��ϴ�." << endl;
	}
};

class Memory
{
public :
	void expand()
	{
		cout << "mp3 play�� ���� �޸𸮸� �ø��ϴ�." << endl;
	}
};

class Mp3
{
public:
	void play()
	{

		cout << "mp3�� play �մϴ�." << endl;
	}
};

int main()
{
	PowerDevice powerdevice;
	Memory memory;
	File file;
	Mp3 mp3;

	powerdevice.powerUp();
	memory.expand();
	file.load();
	mp3.play();
}