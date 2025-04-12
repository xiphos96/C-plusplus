
#include <iostream>
#include <string>
#include <unordered_map>

void PrintAll(std::unordered_map<std::string, int>& CharInfo)
{
	std::cout << "����� ĳ���� ����Ʈ" << std::endl;

	for( auto& info : CharInfo )
	{
		std::cout << "ĳ���� �̸� : " << info.first;
		std::cout << "| ���� �� : " << info.second << std::endl;
	}
	std::cout << std::endl;
}

int main()
{
	std::unordered_map<std::string, int> CharacterMoneys;
	
	// �߰�
	CharacterMoneys.insert(std::pair<std::string, int>("test1", 1100));
	CharacterMoneys.insert(std::pair<std::string, int>("test2", 2100));
	CharacterMoneys.insert(std::pair<std::string, int>("test3", 3100));
	
	PrintAll(CharacterMoneys);

	
	auto Iter1 = CharacterMoneys.emplace_hint(CharacterMoneys.begin(), "test2", 4000);
	
	std::cout << "ĳ���� �̸� : " << Iter1->first;
	std::cout << "| ���� �� : " << Iter1->second << std::endl;

	PrintAll(CharacterMoneys);


	auto Iter2 = CharacterMoneys.emplace_hint(CharacterMoneys.begin(), "test4", 4000);
	
	std::cout << "ĳ���� �̸� : " << Iter2->first;
	std::cout << "| ���� �� : " << Iter2->second << std::endl;

	PrintAll(CharacterMoneys);

	return 0;
}

