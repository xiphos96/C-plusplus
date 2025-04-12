// Ex9_04.cpp
// ���� ������ �ٽ� �����鼭 �ܾ��� �ֳʱ׷��� ã��

#include <iostream>                                      // ǥ�� ��Ʈ��
#include <fstream>                                       // ���� ��Ʈ��
#include <iterator>                                      // �ݺ���, begin(), end()
#include <string>                                        // string Ŭ����
#include <set>                                           // set �����̳�
#include <vector>                                        // vector �����̳�
#include <algorithm>                                     // next_permutation()
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
  auto end_iter = std::istream_iterator<string> {};

  std::vector<string> words;
  string word;
  while(true)
  {
    std::cout << "\nEnter a word, or Ctrl+z to end: ";
    if((std::cin >> word).eof()) break;
    string word_copy {word};
    do
    {
      in.seekg(0);                                              // ������ ���� ��ġ��

      // find() �˰����� ����� �ֳʱ׷� �˻翡 �ʿ��� ������ �д´�
      if(std::find(std::istream_iterator<string>(in), end_iter, word) != end_iter)
        words.push_back(word);
      else
        in.clear();                                             // EOF �ʱ�ȭ

      std::next_permutation(std::begin(word), std::end(word));
    } while(word != word_copy);

    std::copy(std::begin(words), std::end(words), std::ostream_iterator<string>{std::cout, " "});
    std::cout << std::endl;
    words.clear();                                              // ���� ������ ����
  }
  in.close();                                                   // ���� �ݱ�
}
