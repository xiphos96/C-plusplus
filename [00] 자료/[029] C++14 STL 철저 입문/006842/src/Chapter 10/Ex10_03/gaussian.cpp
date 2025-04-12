// Gaussian.cpp
// ���콺 �ҰŹ��� ������ �Լ�
#include <valarray>                              // valarray, slice, abs()
#include <vector>                                // vector �����̳�
#include <iterator>                              // ostream �ݺ���
#include <algorithm>                             // copy_n() 
#include <utility>                               // swap() 
#include <iostream>                              // ǥ�� ��Ʈ��
#include <iomanip>                               // ��Ʈ�� ������
using std::valarray;
using std::slice;

// ������ n���� �� n���� �����Ŀ� ���� �����͸� �о���δ�
valarray<double> get_data(size_t n)
{
  valarray<double> equations(n*(n + 1));    // n+1���� ���ҷ� �� n���� ��
  std::cout << "Enter " << n + 1
    << " values for each of "<< n << " equations.\n"
    << "(i.e. including coefficients that are zero and the rhs:\n";
  for(auto& coeff: equations) std::cin >> coeff;
  return equations;
}

// �� n���� ���� �ǹ��� �����ϱ�(���� �ε����� 0���� �����Ѵ�)
void set_pivot(const valarray<double>& equations, std::vector<slice>& row_slices, size_t n)
{
  size_t n_rows {row_slices.size()};             // ���� ����
  size_t row_len {n_rows + 1};                   // �� ���� = ���� ����

  // �� n���� �����ϰ�, �� n�� ���Ҹ� ������ ��ü�� ����
  valarray<double> column {equations[slice {n*row_len + n, n_rows - n, row_len}]};
  column = std::abs(column);                     // ����

  size_t max_index {};                           // ������ ���� �ǹ��� ���� �ε���
  for(size_t i {1}; i < column.size(); ++i)      // �ִ��� �ε����� ã��
  {
    if(column[max_index] < column[i]) max_index = i;
  }

  if(max_index > 0)
  { // �ǹ��� ������ ù ��°�� �ƴ� ��� - ù ��°�� ����� ���� ���� ��ȯ�Ѵ�
    std::swap(row_slices[n], row_slices[n + max_index]);
  }
  else if(!column[0])                            // ����(0) �ǹ����� �˻�
  { // �ǹ��� 0�̸� ����� Ư�� ���
    std::cerr << "No solution. Ending program." << std::endl;
    std::exit(1);
  }
} 

// ������ ����� �� ��ٸ��� ���·� ����(reduce)
// equations ��ü�� �������� n���� ������ n���� ��ķ� �����ϰ� �ִ�
// row_slices �����̳��� ���ҵ��� �������� ���� ������ ���̴�
void reduce_matrix(valarray<double>& equations, std::vector<slice>& row_slices)
{
  size_t n_rows {row_slices.size()};             // ���� ����
  size_t row_len {n_rows + 1};                   // �� ����
  for(size_t row {}; row < n_rows - 1; ++row)    // ù ��° ����� ������ �� ��° �����
  {
    set_pivot(equations, row_slices, row);       // ���� �ǹ� ã��

    // �ǹ� �࿡ ���� ���� ���� ��� �ִ� ��ü �����ϱ�
    valarray<double> pivot_row {equations[row_slices[row]]};
    auto pivot = pivot_row[row];                 // �ǹ� ����
    pivot_row /= pivot;                          // �ǹ� ���� �ǹ����� ������

    // ���� �� ���� �� �࿡ ����
    // �ǹ� ���� �� ���ҷ� ���� �ǹ� ���� ����
    for(size_t next_row {row + 1}; next_row < n_rows; ++next_row)
    {
      equations[row_slices[next_row]] -= equations[row_slices[next_row].start() + row] * pivot_row;
    }
  }
} 

// ��ġ ������ �����ϰ� ��(solution)�� ��ȯ�Ѵ�
valarray<double> back_substitution(valarray<double>& equations, 
                                                      const std::vector<slice>& row_slices)
{
  size_t n_rows{row_slices.size()};
  size_t row_len {n_rows + 1};

  // ������ ���� ������ �� ��° ���ҷ� ������
  // ������ ���� �� ���� ������ �� ��° ���ҷ� ���ϰ�, �ش� �࿡�� ����.
  // ������ �࿡ ���ؼ��� �� ������ �ݺ��Ѵ�
  valarray<double> results(n_rows);         // �ظ� �����Ѵ�
  for(int row {static_cast<int>(n_rows - 1)}; row >= 0; --row)
  {
    equations[row_slices[row]] /= 
                       valarray<double>(equations[row_slices[row].start() + row], row_len);
    valarray<double> last_row {equations[row_slices[row]]};
    results[row] = last_row[n_rows];               // x[row]�� ���� �����Ѵ�
    for(int i {}; i < row; ++i)
    {
      equations[row_slices[i]] -= equations[row_slices[i].start() + row] * last_row;
    }
  }
  return results; 
}