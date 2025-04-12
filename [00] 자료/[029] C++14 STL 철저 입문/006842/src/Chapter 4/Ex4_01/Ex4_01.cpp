#pragma setlocale("ko-KR")
  
// Ex4_01.cpp
// �̸��� ���̸� ����
#include <iostream>                              // ǥ�� ��Ʈ��
#include <iomanip>                               // ��Ʈ�� ������
#include <string>                                // string Ŭ����
#include <map>                                   // map �����̳� Ŭ����
#include <utility>                               // pair<>, make_pair<>()
#include <cctype>                                // toupper()
#include "Name.h"

using std::string;
using Entry = std::pair<const Name, size_t>;
using std::make_pair;
using std::map;


// �Է¿��� �� �׸��� ����
Entry get_entry()
{
  std::cout << "Enter first and second names followed by the age: ";
  Name name {};
  size_t age {};
  std::cin >> name >> age;
  return make_pair(name, age);
}

// �ʿ� �ִ� ���ҵ鸦 ���
void list_entries(const map<Name, size_t>& people)
{
  for(auto& entry : people)
  {
    std::cout << std::left << std::setw(30) << entry.first
              << std::right << std::setw(4) << entry.second << std::endl;
  }
}


int main()
{
  map<Name, size_t> people {{{"Ann", "Dante"}, 25}, {{"Bill", "Hook"}, 46}, {{"Jim", "Jams"}, 32}, {{"Mark", "Time"}, 32}};

  std::cout << "\nThe initial contents of the map is:\n";
  list_entries(people);

  char answer {'Y'};
  std::cout << "\nEnter a Name and age entry.\n";
  while(std::toupper(answer) == 'Y')
  {
    Entry entry {get_entry()};
    auto pr = people.insert(entry);
    if(!pr.second)
    { // �ʿ� �̹� ������ ������Ʈ�ؾ� �ϴ��� �˻�
      std::cout << "Key \"" << pr.first->first << "\" already present. Do you want to update the age (Y or N)? ";
      std::cin >> answer;
      if(std::toupper(answer) == 'Y')
        pr.first->second = entry.second;
    }
    // �Է��� �׸��� �� �ִ��� Ȯ��
    std::cout << "Do you want to enter another entry(Y or N)? ";
    std::cin >> answer;
  }

  std::cout << "\nThe map now contains the following entries:\n";
  list_entries(people);
}