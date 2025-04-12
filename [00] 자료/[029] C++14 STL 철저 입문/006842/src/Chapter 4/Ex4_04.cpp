// Ex4_04.cpp
// tuple�� pair ����ϱ�
#include <iostream>                                        // ǥ�� ��Ʈ��
#include <iomanip>                                         // ��Ʈ�� ������
#include <string>                                          // string Ŭ����
#include <cctype>                                          // toupper()
#include <map>                                             // map �����̳�
#include <vector>                                          // vector �����̳�
#include <tuple>                                           // tuple ���ø�
#include <algorithm>                                       // sort() ���ø�

using std::string;
using Name = std::pair < string, string >;                 // �̸� pair�� ����
using DOB = std::tuple <size_t, size_t, size_t>;           // ��, ��, ���� tuple
using Details = std::tuple < DOB, size_t, string > ;       // �����(DOB), Ű(��ġ), ����
using Element_type = std::map<Name, Details>::value_type;  // map ������ Ÿ��
using People = std::map<Name, Details>;                    // people �����̳��� Ÿ��

// ǥ�� �Է¿��� people ������ �Է� �ޱ�
void get_people(People& people)
{
  string first {}, second {};                              // �̸� �Է��� ����
  size_t month {}, day {}, year {};                        // DOB �Է��� ����
  size_t height {};                                        // Ű �Է��� ����
  string occupation {};                                    // ���� �Է��� ����
  char answer {'Y'};

  while(std::toupper(answer) == 'Y')
  {
    std::cout << "Enter a first name and a second name: ";
    std::cin >> std::ws >> first >> second;

    std::cout << "Enter date of birth as month day year (integers): ";
    std::cin >> month >> day >> year;
    DOB dob {month, day, year};                            // DOB tuple�� ����

    std::cout << "Enter height in inches: ";
    std::cin >> height; 
    
    std::cout << "Enter occupation: ";
    std::getline(std::cin >> std::ws, occupation, '\n');

    // Name pair�� tuple ��ü�� ��� pair�� �� ���ҷ� ���ο��� ����
    people.emplace(std::make_pair(Name {first, second}, std::make_tuple(dob, height, occupation)));

    std::cout << "Do you want to enter another(Y or N): ";
    std::cin >> answer;
  }
}

// �̸�, �����(date-of-birth, DOB), ������ ���
void list_DOB_Job(const People& people)
{
  DOB dob;
  string occupation {};
  std::cout << '\n';
  for(auto iter = std::begin(people); iter != std::end(people); ++iter)
  {
    std::tie(dob, std::ignore, occupation) = iter->second;
    std::cout << std::setw(20) << std::left << (iter->first.first + " " + iter->first.second)
      << "DOB: " << std::right << std::setw(2) << std::get<0>(dob) << "-"
      << std::setw(2) << std::setfill('0') << std::get<1>(dob) << "-"
      << std::setw(4) << std::get<2>(dob) << std::setfill(' ')
      << "  Occupation: " << occupation << std::endl;
  }
}

// �Լ� ��ü�� �����ؼ� ������ �������� �ִ� �� ���Ҹ� ���
template<typename Compare>
void list_sorted_people(const People& people, Compare comp)
{
  std::vector<const Element_type*> folks;
  for(const auto& pr : people)
    folks.push_back(&pr);

  // �����ͷ� ���ҵ��� ���ϴ� ����
  auto ptr_comp = 
       [&comp](const Element_type* pr1, const Element_type* pr2)->bool
              {  return comp(*pr1, *pr2);  };

  std::sort(std::begin(folks), std::end(folks), ptr_comp); // ���ҿ� ���� �����͸� ����

  // ���ĵ� ���ҵ��� ���
  DOB dob {};
  size_t height {};
  string occupation {};
  std::cout << '\n';

  for(const auto& p : folks) 
  {
    std::tie(dob, height, occupation) = p->second;
    std::cout << std::setw(20) << std::left << (p->first.first + " " + p->first.second)
      << "DOB: " << std::right << std::setw(2) << std::get<0>(dob) << "-"
      << std::setw(2) << std::setfill('0') << std::get<1>(dob) << "-"
      << std::setw(4) << std::get<2>(dob) << std::setfill(' ')
      << "  Height: " << height
      << "  Occupation: " << occupation << std::endl;
  }
}

int main()
{
  std::map<Name, Details> people;                     // people�� ���ڵ�
  get_people(people);                                 // people�� ��� �д´�

  std::cout << "\nThe DOB & jobs are: \n";
  list_DOB_Job(people);                               // �̸�, �����, ������ ���

  // ������� Ű�� ���ϴ� �ɷ� ����
  auto comp = [](const Element_type& pr1, const Element_type& pr2)
  {
    return std::get<1>(pr1.second) < std::get<1>(pr2.second);
  };

  std::cout << "\nThe people in height order are : \n";
  list_sorted_people(people, comp);
}
