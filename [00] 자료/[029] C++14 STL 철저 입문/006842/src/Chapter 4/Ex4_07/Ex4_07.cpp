// Ex4_07.cpp
#include <iostream>                              // ǥ�� ��Ʈ��
#include <cctype>                                // toupper()
#include <string>                                // string Ŭ����
#include <unordered_map>                         // unordered_map �����̳�

#include "Record_IO.h"
#include "My_Templates.h"
#include "Hash_Function_Objects.h"

using std::string;
using std::unordered_multimap;
using Name = std::pair < string, string >;
using Phone = std::tuple < string, string, string >;

// ��� ������Ʈ�� ǥ���Ѵ�
void show_operations()
{
  std::cout << "Operations:\n"
    << "A: Add an element.\n"
    << "D: Delete elements.\n"
    << "F: Find elements.\n"
    << "L: List all elements.\n"
    << "Q: Quit the program.\n\n";
}

int main()
{
  unordered_multimap<Name, Phone, NameHash> by_name {8, NameHash()};
  unordered_multimap<Phone, Name, PhoneHash> by_number {8, PhoneHash()};
  show_operations();

  char choice {};                                     // ó���� �۾� ����
  Phone number {};                                    // ���ڸ� ���
  Name name {};                                       // �̸��� ���

  while(std::toupper(choice) != 'Q')                  // ������ ������ ��� ����...
  {
    std::cout << "Enter a command: ";
    std::cin >> choice;
    switch(std::toupper(choice))
    {
    case 'A':                                         // ���ڵ带 �߰�
      std::cout << "Enter first & second names, area code, exchange, and number separated by spaces:\n";
      std::cin >> name >> number;
      by_name.emplace(name, number);                  // �� �����̳� ���...
      by_number.emplace(number, name);                // ...���ο��� ����
      break;

    case 'D':                                         // ���ڵ� ����
    {
      std::cout << "Enter a name: ";                  // �̸����� ã��
      auto pr = find_elements(by_name);
      auto count = std::distance(pr.first, pr.second);  // ������ ����
      if(count == 1)
      {                                               // ���Ұ� �ϳ��� �ִٸ顦
        by_number.erase(pr.first->second);            // ... by_numbers �����̳ʿ��� ����
        by_name.erase(pr.first);                      // ... by_names �����̳ʿ��� ����
      }
      else if(count > 1)
      { // �� �� �̻��̸�
        std::cout << "There are " << count << " records for "
                  << pr.first->first << ". Delete all(Y or N)? ";
        std::cin >> choice;

        if(std::toupper(choice) == 'Y')
        { // by_number �����̳ʺ��� ���ڵ带 ����
          for(auto iter = pr.first; iter != pr.second; ++iter)
          {
            by_number.erase(iter->second);
          }
          by_name.erase(pr.first, pr.second);         // by_name �����̳ʿ����� ����
        }
      }
    }
    break;

    case 'F':                                         // ���ڵ带 ã��
      std::cout << "Find by name(Y or N)? ";
      std::cin >> choice;
      if(std::toupper(choice) == 'Y')
      {
        std::cout << "Enter first name and second name: ";
        list_range(find_elements(by_name));
      }
      else
      {
        std::cout << "Enter area code, exchange, and number separated by spaces: ";
        list_range(find_elements(by_number));
      }
      break;

    case 'L':                                         // ��� ���ڵ带 ���
      std::cout << "List by name(Y or N)? ";
      std::cin >> choice;
      if(std::toupper(choice) == 'Y')
        list_elements(by_name);
      else
        list_elements(by_number);
      break;
    case 'Q':
      break;

    default:
      std::cout << "Invalid command - try again.\n";
    }
  }
}