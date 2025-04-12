#include <iostream>
using namespace std;

class File
{
public :
	void load()
	{
		cout << "mp3 파일을 메모리에 올립니다." << endl;
	}
};

class PowerDevice
{
public :
	void powerUp()
	{
		cout << "mp3 play를 위한 파워를 올립니다." << endl;
	}
};

class Memory
{
public :
	void expand()
	{
		cout << "mp3 play를 위한 메모리를 늘립니다." << endl;
	}
};

class Mp3
{
public:
	void play()
	{

		cout << "mp3를 play 합니다." << endl;
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