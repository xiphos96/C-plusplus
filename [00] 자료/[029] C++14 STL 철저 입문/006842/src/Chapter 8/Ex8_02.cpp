// Ex8_02
// seed_seq ��ü�� ������ ��
#include <random>                                        // seed_seq, random_device
#include <iostream>                                      // ǥ�� ��Ʈ��
#include <iterator>                                      // �ݺ���
#include <string>                                        // string Ŭ����
using std::string;

// seed_seq ��ü���� ������ �����ϰ� ����Ѵ�
void gen_and_list(std::seed_seq& ss, const string title = "Values:", size_t count = 8)
{
  std::vector<unsigned int> values(count);
  ss.generate(std::begin(values), std::end(values));
  std::cout << title << std::endl;
  std::copy(std::begin(values), std::end(values), 
                                       std::ostream_iterator<unsigned int>{std::cout, " "});
  std::cout << std::endl;
}

int main()
{
  std::random_device rd {};                                // ��������� �ҽ� - ��� ����!
  std::seed_seq seeds1;                                    // �⺻ ������
  std::seed_seq seeds2 {3, 4, 5};                          // ���� ��������
  std::seed_seq seeds3 {rd(), rd()};

  std::vector<unsigned int> data {25, 36, 47, 58};             
  std::seed_seq seeds4(std::begin(data), std::end(data));  // ��������
  gen_and_list(seeds1, "seeds1");
  gen_and_list(seeds1, "seeds1 again");
  gen_and_list(seeds1, "seeds1 again", 12);
  gen_and_list(seeds2, "seeds2");
  gen_and_list(seeds3, "seeds3");
  gen_and_list(seeds3, "seeds3 again");
  gen_and_list(seeds4, "seeds4");
  gen_and_list(seeds4, "seeds4 again");
  gen_and_list(seeds4, "seeds4 yet again", 12);
  gen_and_list(seeds4, "seeds4 for the last time", 6);
}
