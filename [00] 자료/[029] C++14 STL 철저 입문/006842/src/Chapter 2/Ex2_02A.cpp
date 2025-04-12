// Ex2_02A.cpp
// vector �����̳ʿ� ����� ���ڿ� �����ϱ�
#include <iostream>                         // ǥ�� ��Ʈ��
#include <string>                           // string Ÿ��
#include <algorithm>                        // swap()�� copy() �Լ�
#include <vector>                           // ����
#include <iterator>                         // �ݺ���
using std::string;
using std::vector;

// ���� ������ �˰���: �ݺ��ڷ� ������ ������ �����Ѵ�
template<typename RandomIter>
void bubble_sort(RandomIter start, RandomIter last)
{
  std::cout << "������ �����մϴ�." << std::endl;
  bool out_of_order {false};                // ������ ���ĵ��� �ʾ����� true
  while (true)
  {
    for (auto first = start + 1; first != last; ++first)
    {
      if (*(first - 1) > *first)
      { // ���ĵ��� �ʾ����� ���� ��ȯ�Ѵ�
        std::swap(*first, *(first - 1));
        out_of_order = true;
      }
    }
    if (!out_of_order)                      // ���ĵ� �����̸�(��ȯ�� �ʿ� ����)...
      break;                                // ...�Ϸ�...
    out_of_order = false;                   // ...�׷��� ������, �ٽ� �ݺ�.
  }
}

int main()
{
  vector<string> words;                     // ������ �ܾ ����
  words.reserve(10);                        // ��ҵ��� ���� ���� �Ҵ�
  std::cout << "�ܾ�� �������� �����ؼ� �Է��ϼ���. �����Ϸ��� ���� �ٿ��� Ctrl+Z�� �Է��ϼ���:" << std::endl;
  std::copy(std::istream_iterator < string > {std::cin}, std::istream_iterator < string > {},
    std::back_inserter(words));

  bubble_sort(std::begin(words), std::end(words));  // Sort the words array

  // ���ĵ� ���͸� ���
  std::cout << "������������ ���ĵ� �ܾ�:" << std::endl;
  std::copy(std::begin(words), std::end(words), std::ostream_iterator < string > {std::cout, " "});
  std::cout << std::endl;

  // words ���Ϳ��� ��ҵ��� �̵��ؼ� �� ���͸� ����
  vector<string> words_copy {std::make_move_iterator(std::begin(words)),
    std::make_move_iterator(std::end(words))};
  std::cout << "\nwords���� ��ҵ��� �̵��� �Ŀ� words_copy�� ����:" << std::endl;
  std::copy(std::begin(words_copy), std::end(words_copy),  std::ostream_iterator < string > {std::cout, " "});
  std::cout << std::endl;

  // words ������ ��ҵ鿡 ���� ���� �Ͼ���� �˾ƺ���...
  std::cout << "\nwords ���ʹ� ��� " << words.size() << "���� ���� �ֽ��ϴ�\n";
  if (!words.front().length())
    std::cout << "ù ��° ��Ҵ� �� ���ڿ� ��ü�Դϴ�." << std::endl;

  std::cout << "ù ��° ��Ҵ� \"" << words.front() <<  "\"�Դϴ�." << std::endl;
}
