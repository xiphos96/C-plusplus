#include <iostream>
#include <unordered_map>

// ���� ĳ����
struct GameCharacter
{
	// �Ʒ��� ���ڸ� ������ �����ڸ� ������ ����
	// �� �⺻ �����ڸ� �����ؾ� �����̳ʿ��� ����� �� �ִ�.
	GameCharacter() { }
	GameCharacter( int CharCd, int Level, int Money )
	{
		_CharCd = CharCd;
		_Level = Level;
		_Money = Money;
	}

	int _CharCd; // ĳ���� �ڵ�
	int _Level; // ����
	int _Money; // ��
};

int main()
{
	std::unordered_map<int, GameCharacter> Characters;
	
	GameCharacter Character1(12, 7, 1000 );
	Characters.insert( std::pair<int, GameCharacter>(12, Character1) );

	GameCharacter Character2(14, 8, 1001 );
	Characters[14] = Character2;

	GameCharacter Character3(15, 8, 1002 );
	Characters[15] = Character3;
	
	for( auto& Iter1 : Characters )
	{
		std::cout << "ĳ���� �ڵ� : " << Iter1.second._CharCd;
		std::cout << " | ���� : " << Iter1.second._Level;
		std::cout << "| ���� �� : " << Iter1.second._Money << std::endl;
	}


	// [] ������Ʈ�� �˻�
	Characters[12]._Level = 17;
	std::cout << "[] ĳ���� 12 ���� : " << Characters[12]._Level << std::endl;

	// at ������Ʈ�� �˻�
	Characters.at(15)._Level = 9;
	std::cout << "at ĳ���� 15 ���� : " << Characters.at(15)._Level << std::endl;


	for( auto& Iter1 : Characters )
	{
		std::cout << "ĳ���� �ڵ� : " << Iter1.second._CharCd;
		std::cout << " | ���� : " << Iter1.second._Level;
		std::cout << "| ���� �� : " << Iter1.second._Money << std::endl;
	}

	
	// [] �˻� - ���� �� 16
	std::cout << "[] ĳ���� 16 ���� : " << Characters[16]._Level << std::endl;

	for( auto& Iter1 : Characters )
	{
		std::cout << "ĳ���� �ڵ� : " << Iter1.second._CharCd;
		std::cout << " | ���� : " << Iter1.second._Level;
		std::cout << "| ���� �� : " << Iter1.second._Money << std::endl;
	}

	return 0;
}