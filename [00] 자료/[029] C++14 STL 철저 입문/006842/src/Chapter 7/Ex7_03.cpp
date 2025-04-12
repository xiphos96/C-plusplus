// Ex7_03.cpp
// �ܾ��� ���ڵ�� ��� ������ ���ϱ�
#include <iostream>                                      // ǥ�� ��Ʈ��
#include <iterator>                                      // �ݺ���, begin(), end()
#include <string>                                        // string Ŭ����
#include <vector>                                        // vector �����̳�
#include <algorithm>                                     // next_permutation()
using std::string;

int main()
{
  std::vector<string> words;
  string word;
  while(true)
  {
    std::cout << "\nEnter a word, or Ctrl+z to end: ";
    if((std::cin >> word).eof()) break;
    string word_copy {word};
    do
    {
      words.push_back(word);
      std::next_permutation(std::begin(word), std::end(word));
    } while(word != word_copy);

    size_t count{}, max{8};
    for(const auto& wrd : words)
      std::cout << wrd << ((++count % max == 0) ? '\n' : ' ');
    std::cout << std::endl;
    words.clear();                                         // ���� ������ ����
  }
}