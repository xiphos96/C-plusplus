
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
	
	// �߰�
	GameCharacter Character1(12, 7, 1000 );
	Characters.insert(std::unordered_map<int, GameCharacter>::value_type(12, Character1));
	GameCharacter Character2(15, 20, 111000 );
	Characters.insert(std::unordered_map<int, GameCharacter>::value_type(15, Character2));
	GameCharacter Character3(200, 34, 3345000 );
	Characters.insert(std::unordered_map<int, GameCharacter>::value_type(200, Character3));
	
	// iterator�� begin, end ���
	// ������ ��Ҹ� ���������� ��ȸ
	for( auto Iter1 = Characters.begin(); Iter1 != Characters.end(); ++Iter1 )
	{
		std::cout << "ĳ���� �ڵ� : " << Iter1->second._CharCd;
		std::cout << " | ���� : " << Iter1->second._Level;
		std::cout << "| ���� �� : " << Iter1->second._Money << std::endl;
	}
	std::cout << std::endl;

	
	// rbegin, rend ���
	// ������ ����� ���������μ�ȸ
	for( auto RIter = Characters.rbegin(); RIter != Characters.rend(); ++RIter )
	{
		std::cout << "ĳ���� �ڵ� : " << RIter->second._CharCd;
		std::cout << " | ���� : " << RIter->second._Level;
		std::cout << "| ���� �� : " << RIter->second._Money << std::endl;
	}
	std::cout << std::endl << std::endl;
	
	
	// Characters�� ������ ��� ��
	int CharacterCount = Characters.size();
	
	// �˻�.
	// ĳ���� �ڵ� 15�� ĳ���͸� ã�´�.
	auto FindIter = Characters.find(15);
	
	// ã�� ���ߴٸ� FindIter�� end ��ġ�� �ݺ��ڰ� ���ϵȴ�.
	if( Characters.end() == FindIter )
	{
		std::cout << "ĳ���� �ڵ尡 20�� ĳ���Ͱ� �����ϴ�" << std::endl;
	}
	else
	{
		std::cout << "ĳ���� �ڵ尡 15�� ĳ���͸� ã�ҽ��ϴ�." << std::endl;
		std::cout << "ĳ���� �ڵ� : " << FindIter->second._CharCd;
		std::cout <<  " | ���� : " << FindIter->second._Level;
		std::cout << "| ���� �� : " << FindIter->second._Money << std::endl;
	}
	std::cout << std::endl;


	for( auto Iter1 = Characters.begin(); Iter1 != Characters.end(); ++Iter1 )
	{
		std::cout << "ĳ���� �ڵ� : " << Iter1->second._CharCd; 
		std::cout << " | ���� : " << Iter1->second._Level;
		std::cout << "| ���� �� : " << Iter1->second._Money << std::endl;
	}
	std::cout << std::endl << std::endl;
	
	
	// ����
	// ĳ���� �ڵ尡 15�� ĳ���͸� �����Ѵ�.
	Characters.erase( 15 );
	
	for( auto Iter1 = Characters.begin(); Iter1 != Characters.end(); ++Iter1 )
	{
		std::cout << "ĳ���� �ڵ� : " << Iter1->second._CharCd;
		std::cout << " | ���� : " << Iter1->second._Level;
		std::cout << "| ���� �� : " << Iter1->second._Money << std::endl;
	}
	std::cout << std::endl << std::endl;
	
	
	// ��� ĳ���͸� �����Ѵ�.
	Characters.erase( Characters.begin(), Characters.end() );
	
	// Characters ���� ����
	if( Characters.empty() )
	{
		std::cout << "Characters�� ��� �ֽ��ϴ�." << std::endl;
	}

	return 0;
}

