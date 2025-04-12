// Ex9_07.cpp
// ��Ʈ�� �ݺ��ڸ� ����� ���Ͽ� �Ǻ���ġ ���� ���� ����
#include <iostream>                                        // ǥ�� ��Ʈ��
#include <iterator>                                        // �ݺ���, begin(), end()
#include <iomanip>                                         // ��Ʈ�� ������
#include <fstream>                                         // fstream
#include <algorithm>                                       // generate_n(), for_each()
#include <string>
using std::string;

int main()
{
  string file_name {"fibonacci.txt"};
  std::fstream fibonacci {file_name, std::ios_base::in | std::ios_base::out | 
                          std::ios_base::trunc};
  if(!fibonacci)
  {
    std::cerr << file_name << " not open." << std::endl;
    exit(1);
  }
  unsigned long long first {0ULL}, second {1ULL};
  auto iter = std::ostream_iterator<unsigned long long> {fibonacci, " "};
  (iter = first) = second;                                 // ó�� �� ���� ����

  const size_t n {50};
  std::generate_n(iter, n, [&first, &second]
  { auto result = first + second;
  first = second;
  second = result;
  return result; });
  fibonacci.seekg(0);                                      // ���� ó������ ���ư���
  std::for_each(std::istream_iterator<unsigned long long> {fibonacci},
    std::istream_iterator<unsigned long long> {},
    [](unsigned long long k)
  { const size_t perline {6};
  static size_t count {};
  std::cout << std::setw(12) << k << ((++count % perline) ? " " : "\n");
  });
  std::cout << std::endl;
  fibonacci.close();                                       // ������ �ݴ´�
}
