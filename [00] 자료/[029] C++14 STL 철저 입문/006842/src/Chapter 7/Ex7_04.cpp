// Ex7_04.cpp
// reverse_copy()�� ����� ȸ�� �׽�Ʈ�ϱ�
#include <iostream>                                      // ǥ�� ��Ʈ��
#include <iterator>                                      // ��Ʈ�� �ݺ���, begin(), end()
#include <algorithm>                                     // reverse_copy(), copy_if()
#include <cctype>                                        // toupper(), isalpha()
#include <string>
using std::string;

int main()
{
  while(true)
  {
    string sentence;
    std::cout << "Enter a sentence or Ctrl+Z to end: ";
    std::getline(std::cin, sentence);
    if(std::cin.eof()) break;

    // ���ڰ� ���ĺ��̸� �����ϰ� �빮�ڷ� ��ȯ�Ѵ�
    string only_letters;
    std::copy_if(std::begin(sentence), std::end(sentence), std::back_inserter(only_letters),
      [](char ch) { return std::isalpha(ch); });
    std::for_each(std::begin(only_letters), std::end(only_letters), [](char& ch) { ch = toupper(ch); });

    // ������ �������� �����
    string reversed;
    std::reverse_copy(std::begin(only_letters), std::end(only_letters), std::back_inserter(reversed));
    std::cout << '"' << sentence << '"'
      << (only_letters == reversed ? " is" : " is not") << " a palindrome." << std::endl;
  }
}
