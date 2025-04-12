// Ex3_04.cpp
// ���� �켱���� ť�� ����ϴ� ����
#include <iostream>                              // ǥ�� ��Ʈ��
#include <iomanip>                               // ��Ʈ�� ������
#include <algorithm>                             // �� �Լ�
#include <string>                                // string Ŭ����
#include <deque>                                 // deque �����̳�
using std::string;

// deque�� ����� �ܾ� ����� ���
void show(const std::deque<string>& words, size_t count = 5)
{
  if(words.empty()) return;                      // deque�� ���Ұ� �ִ��� Ȯ��
  // ���� �� ���ڿ��� ã��
  auto max_len = std::max_element(std::begin(words), std::end(words),
                                  [](const string& s1, const string& s2)
                                  { return s1.size() < s2.size(); })->size();

  // �ܾ���� ����Ѵ�
  size_t n {count};
  for(const auto& word : words)
  {
    std::cout << std::setw(max_len + 1) << word << " ";
    if(--n) continue;
    std::cout << std::endl;
    n = count;
  }
  std::cout << std::endl;
}

int main()
{
  std::deque<string> words;
  std::string word;
  std::cout << "Enter words separated by spaces, enter Ctrl+Z on a separate line to end:\n";
  while (true)
  {
    if ((std::cin >> word).eof())
    {
      std::cin.clear();
      break;
    }
    words.push_back(word);
  }
  std::cout << "The words in the list are:" << std::endl;
  show(words);

  std::make_heap(std::begin(words), std::end(words));
  std::cout << "\nAfter making a heap, the words in the list are:" << std::endl;
  show(words);
  std::cout << "\nYou entered " << words.size() << " words. Enter some more:" << std::endl;
  while (true)
  {
    if ((std::cin >> word).eof())
    {
      std::cin.clear();
      break;
    }
    words.push_back(word);
    std::push_heap(std::begin(words), std::end(words));
  }
  std::cout << "\nThe words in the list are now:" << std::endl;
  show(words);
}
