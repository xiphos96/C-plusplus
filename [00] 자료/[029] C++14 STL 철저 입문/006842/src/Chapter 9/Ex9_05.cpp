// Ex9_05.cpp
// ��Ʈ�� �ݺ��ڸ� ����� ���� ������ �����ϱ�
#include <iostream>                                      // ǥ�� ��Ʈ��
#include <fstream>                                       // ���� ��Ʈ��
#include <iterator>                                      // �ݺ���, begin(), end()
#include <string>                                        // string Ŭ����
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
  string file_out {"dictionary_copy.txt"};
  std::ofstream out {file_out, std::ios_base::out | std::ios_base::trunc };
  std::copy(std::istream_iterator<string> {in}, std::istream_iterator<string> {},
                                                std::ostream_iterator<string> {out, " "});
  in.clear();                                              // EOF�� ����
  std::cout << "Original file length: " << in.tellg() << std::endl;
  std::cout << "File copy length: " << out.tellp() << std::endl;
  in.close();
  out.close();
}
