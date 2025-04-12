#ifndef DIE_H
#define DIE_H
#include <random>                                        // discrete_distribution, ���� �ѹ� ������
#include <vector>                                        // vector �����̳�
#include <algorithm>                                     // remove()
#include <iterator>                                      // �ݺ���, begin(), end()

// �̻������ param_type�� ���� ��Ī
using Params = std::discrete_distribution<size_t>::param_type;

std::default_random_engine& rng(); 

// ������ ���� ���� 6�� �ֻ����� ǥ���� Ŭ����
// ���� ���� ������ �ʿ�� ����
class Die
{
public:
  Die() { values.push_back(0); };

  // ������
  Die(std::initializer_list<size_t> init)
  {
    std::vector<size_t> faces {init};                      // �ֻ��� ���� ���� ����
    auto iter = std::begin(faces);
    auto end_iter = std::end(faces);
    std::vector<size_t> wts;                               // ���� ���� ���� ����ġ�� ����
    while(iter != end_iter)
    {
      values.push_back(*iter);
      wts.push_back(std::count(iter, end_iter, *iter));
      end_iter = std::remove(iter, end_iter, *iter++);
    }
    dist.param(Params {std::begin(wts), std::end(wts)});
  }

  size_t throw_it() { return values[dist(rng())]; }

private:
  std::discrete_distribution<size_t> dist;                // ���� Ȯ�� ����
  std::vector<size_t> values;                             // ���� ��
};
#endif
