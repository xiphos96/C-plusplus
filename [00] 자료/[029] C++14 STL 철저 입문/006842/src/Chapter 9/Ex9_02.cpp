// Ex9_02.cpp
// Using output stream iterator function members
#include <iostream>                                      // ǥ�� ��Ʈ��
#include <iterator>                                      // �ݺ���, begin(), end()
#include <vector>                                        // vector �����̳�
#include <algorithm>                                     // copy() �˰���
#include <string>
using std::string;

int main()
{
  std::vector<string> words {"The", "quick", "brown", "fox", "jumped", "over", "the", "lazy", "dog"};

  // �Ϲ����� �ݺ��� ǥ����� ����� words �����̳ʿ� ����
  std::ostream_iterator<string> out_iter1 {std::cout};   // ��� ������ ���� �ݺ���
  for(const auto& word : words)
  {
    *out_iter1++ = word;                                 // �ܾ ����
    *out_iter1++ = " ";                                  // �����ڸ� ����
  }
  *out_iter1++ = "\n";                                   // �� ���� ����

  // �ٽ� �ݺ��ڸ� ����ؼ� words �����̳ʿ� ����
  for(const auto& word : words)
  {
    (out_iter1 = word) = " ";                            // �ܾ�� �����ڸ� ���� 
  }
  out_iter1 = "\n";                                      // �� ���� ����

  // copy()�� ����� words �����̳ʿ� ����
  std::ostream_iterator<string> out_iter2 {std::cout, " "};
  std::copy(std::begin(words), std::end(words), out_iter2);
  out_iter2 = "\n";
}
