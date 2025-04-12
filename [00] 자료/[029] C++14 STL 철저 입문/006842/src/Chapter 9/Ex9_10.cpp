// Ex9_10.cpp
// ���ڿ� ��Ʈ���� ���� �ҽ��� ����ؼ� �ܾ��� �ֳʱ׷��� ã�� ����
#include <iostream>                                      // ǥ�� ��Ʈ��
#include <fstream>                                       // ���� ��Ʈ��
#include <iterator>                                      // �ݺ���, begin(), end()
#include <string>                                        // string Ŭ����
#include <set>                                           // set �����̳�
#include <vector>                                        // vector �����̳�
#include <algorithm>                                     // next_permutation()
#include <sstream>                                       // ���ڿ� ��Ʈ��
using std::string;

int main()
{
  string file_in {"dictionary.txt"};
  std::ifstream in {file_in};
  if(!in)
  {
    std::cerr << file_in << " not open." << std::endl;
    exit(1);
  }
  std::stringstream instr;                              // ���� ������ ���� ���ڿ� ��Ʈ��
  std::copy(std::istreambuf_iterator<char>{in}, std::istreambuf_iterator<char>(),
                                                std::ostreambuf_iterator<char>{instr});
  in.close();                                           // ���� �ݱ�

  std::vector<string> words;
  string word;
  auto end_iter = std::istream_iterator<string> {};     // �� ��Ʈ�� �ݺ���
  while(true)
  {
    std::cout << "\nEnter a word, or Ctrl+z to end: ";
    if((std::cin >> word).eof()) break;

    string word_copy {word};
    do
    {
      instr.clear();                                 // ���ڿ� ��Ʈ�� EOF ����
      instr.seekg(0);                                // ���ڿ� ��Ʈ�� ��ġ�� ó������

                                                     // find()�� ����� instr���� word ã��
      if(std::find(std::istream_iterator<string>(instr), end_iter, word) != end_iter)
        words.push_back(word);                       // �߰��� �ܾ ����

      std::next_permutation(std::begin(word), std::end(word));
    } while(word != word_copy);

    std::copy(std::begin(words), std::end(words), std::ostream_iterator<string>{std::cout, " "});
    std::cout << std::endl;
    words.clear();                                   // ���� �ֳʱ׷� ����
  }
}
