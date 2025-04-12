// Ex10_03.cpp
// ���콺 �ҰŹ��� ����� ���� �������� �ظ� ���ϴ� ����
#include <valarray>                              // valarray, slice, abs()
#include <vector>                                // vector �����̳�
#include <iterator>                              // ostream �ݺ���
#include <algorithm>                             // For generate_n() 
#include <utility>                               // For swap() 
#include <iostream>                              // ǥ�� ��Ʈ��
#include <iomanip>                               // ��Ʈ�� ������
#include <string>                                // string Ÿ��
using std::string;
using std::valarray;
using std::slice;

// �Լ� ������Ÿ��
valarray<double> get_data(size_t n);
void reduce_matrix(valarray<double>& equations, std::vector<slice>& row_slices);
valarray<double> back_substitution(valarray<double>& equations, const std::vector<slice>& row_slices);

int main()
{
  size_t n_rows {};
  std::cout << "Enter the number of variables: ";
  std::cin >> n_rows;
  auto equations = get_data(n_rows);

  // �� ������ �࿡ ���� slice ��ü�� ����
  std::vector<slice> row_slices;                   // ���� �����̳ʿ� ���� slice ��ü�� ����
  size_t row_len {n_rows + 1};
  std::generate_n(std::back_inserter(row_slices), n_rows,
                                           [row_len]()
                                           { static size_t index {};
                                             return slice {row_len*index++, row_len, 1};
                                           });

  reduce_matrix(equations, row_slices);            // �� ��ٸ��� ���·� ���
  auto solution = back_substitution(equations, row_slices);

  // �ظ� ���
  size_t count {}, perline {8};
  std::cout << "\nSolution:\n";
  string x{"x"};
  for(const auto& v : solution)
  {
    std::cout << std::setw(3) << x + std::to_string(count+1) << " = "
              << std::fixed << std::setprecision(2) << std::setw(10)
              << v;
    if(++count % perline) std::cout << '\n';
  }
  std::cout << std::endl;
}
