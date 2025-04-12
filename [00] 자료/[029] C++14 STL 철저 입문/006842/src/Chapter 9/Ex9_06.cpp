// Ex9_06.cpp
// ��Ʈ�� �ݺ��ڿ� count_if()�� ����� �ܾ� �󵵸� ���� ����
#include <iostream>                                        // ǥ�� ��Ʈ��
#include <iterator>                                        // �ݺ���, begin(), end()
#include <iomanip>                                         // ��Ʈ�� ������
#include <fstream>                                         // ifstream
#include <algorithm>                                       // count_if()
#include <string>
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
  string letters {"abcdefghijklmnopqrstuvwxyz"};
  const size_t perline {9};
  for(auto ch : letters)
  {
    std::cout << ch << ": "
      << std::setw(5)
      << std::count_if(std::istream_iterator<string>{in}, std::istream_iterator<string>{},
                                                          [&ch](const string& s)
                                                          { return s[0] == ch; })
      << (((ch - 'a' + 1) % perline) ? " " : "\n");
    in.clear();                                            // EOF�� �����ϰ�...
    in.seekg(0);                                           // ... ó������ ���ư���
  }
  std::cout << std::endl;
}
