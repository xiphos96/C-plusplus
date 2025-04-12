// Ex5_04.cpp 
// �ܾ� �󵵼� �˾Ƴ���
#include <iostream>                               // ǥ�� ��Ʈ��
#include <iomanip>                                // ��Ʈ�� ������
#include <string>                                 // string Ŭ����
#include <sstream>                                // istringstream
#include <algorithm>                              // replace_if(), for_each()
#include <set>                                    // set �����̳�
#include <iterator>                               // advance()
#include <cctype>                                 // isalpha()

using std::string;

int main()
{
  std::cout << "Enter some text and enter * to end:\n";
  string text_in {};
  std::getline(std::cin, text_in, '*');

  // ���ĺ��� ������ ���ڸ� �������� �ٲ۴�
  std::replace_if(std::begin(text_in), std::end(text_in), [](const char& ch){ return !isalpha(ch); }, ' ');

  std::istringstream text(text_in);             // �ؽ�Ʈ �Է� ���ڿ��� ��Ʈ������ ��ȯ
  std::istream_iterator<string> begin(text);    // ��Ʈ�� �ݺ��� 
  std::istream_iterator<string> end;            // �� ��Ʈ�� �ݺ���

  std::multiset<string> words;                  // �ܾ ������ �����̳�
  size_t max_len {};                            // �ܾ� �ִ� ����

  // �ܾ ������ �����̳ʿ� �����ϰ� �ִ� ���̸� ã�´�
  std::for_each(begin, end, [&max_len, &words](const string& word)
                            {  words.emplace(word);
                               max_len = std::max(max_len, word.length());
  });

  size_t per_line {4},                           // �� �ٴ� ����� �ܾ� ��
         count {};                               // �ܾ� ��� ����
  
  for(auto iter = std::begin(words); iter != std::end(words); iter = words.upper_bound(*iter))
  {
    std::cout << std::left << std::setw(max_len + 1) << *iter
              << std::setw(3) << std::right << words.count(*iter) << "  ";
    if(++count % per_line == 0)  std::cout << std::endl;
  }
  std::cout << std::endl;
}
