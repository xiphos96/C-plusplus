// Ex10_05.cpp
// ���� �������� Ǫ�� �ð��� �����ϴ� ����
#include <valarray>                              // valarray, slice, abs()
#include <vector>                                // vector �����̳�
#include <iterator>                              // ostream �ݺ���
#include <algorithm>                             // generate_n() 
#include <utility>                               // swap() 
#include <iostream>                              // ǥ�� ��Ʈ��
#include <iomanip>                               // ��Ʈ�� ������
#include <string>                                // string Ÿ��
#include <chrono>                                // Ŭ��, duration, time_point
using std::string;
using std::valarray;
using std::slice;
using namespace std::chrono;

// �Լ� ������Ÿ��
valarray<double> get_data(size_t n);
void reduce_matrix(valarray<double>& equations, std::vector<slice>& row_slices);
valarray<double> back_substitution(valarray<double>& equations, const std::vector<slice>& row_slices);

// time_point<>�� ���� ��Ȯ�� �ð� ������ �� ������ ����Ѵ�
template<typename TimePoint>
void print_timepoint(const TimePoint& tp, size_t places = 0)
{
  auto elapsed = tp.time_since_epoch();          // �ð� ������ ���� duration ��ü

  auto seconds = std::chrono::duration_cast<std::chrono::duration<double>>(elapsed).count();
  std::cout << std::fixed << std::setprecision(places) << seconds << " seconds\n";
}

int main()
{
  size_t n_rows {};
  std::cout << "Enter the number of variables: ";
  std::cin >> n_rows;
  auto equations = get_data(n_rows);

  auto start_time = steady_clock::now();                   // time_point ��ü

  // �� ������ �࿡ ���� slice ��ü�� ����
  std::vector<slice> row_slices;                           // ���� �����̳ʿ� ���� slice ��ü�� ����
  size_t row_len {n_rows + 1};
  std::generate_n(std::back_inserter(row_slices), n_rows,
    [row_len]()
  { static size_t index {};
  return slice {row_len*index++, row_len, 1};
  });

  reduce_matrix(equations, row_slices);                    // �� ��ٸ��� ���·� ���
  auto solution = back_substitution(equations, row_slices);

  auto end_time = steady_clock::now();                     // time_point ��ü
  auto elapsed = end_time - start_time.time_since_epoch();
  std::cout << "Time to solve " << n_rows << " equations is ";
  print_timepoint(elapsed, 9);

  // �ظ� ���
  size_t count {}, perline {8};
  std::cout << "\nSolution:\n";
  string x {"x"};
  for(const auto& v : solution)
  {
    std::cout << std::setw(3) << x + std::to_string(count + 1) << " = "
      << std::fixed << std::setprecision(2) << std::setw(10)
      << v;
    if(++count % perline) std::cout << '\n';
  }
  std::cout << std::endl;
}