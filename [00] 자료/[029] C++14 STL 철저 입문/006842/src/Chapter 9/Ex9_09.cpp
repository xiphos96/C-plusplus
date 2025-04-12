// Ex9_09.cpp
// ��Ʈ�� ���� �ݺ��ڸ� ����� ������ �����ϴ� ����
#include <iostream>                                        // ǥ�� ��Ʈ��
#include <iterator>                                        // �ݺ���, begin(), end()
#include <fstream>                                         // ���� ��Ʈ��
#include <string>                                          // string Ŭ����
using std::string;

int main()
{
  string file_name {"dictionary.txt"};
  std::ifstream file_in {file_name};
  if(!file_in)
  {
    std::cerr << file_name << " not open." << std::endl;
    exit(1);
  }
  string file_copy {"dictionary_copy.txt"};
  std::ofstream file_out {file_copy, std::ios_base::out | std::ios_base::trunc};

  std::istreambuf_iterator<char> in {file_in};             // �Է� ��Ʈ�� ���� �ݺ���
  std::istreambuf_iterator<char> end_in;                   // �� ��Ʈ�� ���� �ݺ���
  std::ostreambuf_iterator<char> out {file_out};           // ��� ��Ʈ�� ���� �ݺ���
  while(in != end_in)
    out = *in++;                                           // in���� out���� ���ڸ� ����

  std::cout << "File copy completed." << std::endl;

  file_in.close();                                         // ���� �ݱ�
  file_out.close();                                        // ���� �ݱ�
}
