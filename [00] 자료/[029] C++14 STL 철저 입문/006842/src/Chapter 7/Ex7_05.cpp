// Ex7_05.cpp
// �� ���� �˰����� ������ ��� �׸��� ����
// �ùٸ� ���� ���� ��� ����ϱ� ����
// ǥ�� ��� ��Ʈ�� ��� ����� ���ڸ� 8x8 �ȼ� ���� �׸�Ʋ ��Ʈ�� �����Ѵ�.
#include <iostream>                                      // ǥ�� ��Ʈ��
#include <iterator>                                      // �ݺ���, begin(), end()
#include <string>                                        // string Ŭ����
#include <vector>                                        // vector �����̳�
#include <algorithm>                                     // �˰���
#include <cmath>                                         // sin(), cos()
using std::string;
using Point = std::pair<double, double>;

static const double pi {3.1415926};

// Function template to plot a range of x,y values on cout
template<typename Iterator>
void plot(Iterator begin_iter, Iterator end_iter, string name = "Curve", size_t n_x = 100)
{ // n_x�� ���ڷ� ǥ���� ����� ��, ��, x �࿡ ����� ������ ����

  // x�� y�� ���� �� �Լ�
  auto x_comp = [](const Point& p1, const Point& p2) { return p1.first < p2.first; };
  auto y_comp = [](const Point& p1, const Point& p2) { return p1.second < p2.second; };

  // x ���� �ּڰ��� �ִ�
  auto min_x = std::min_element(begin_iter, end_iter, x_comp)->first;
  auto max_x = std::max_element(begin_iter, end_iter, x_comp)->first;

  // ����� ���� ���� ���� - x�� y�� ���� ������ �����ؾ� �Ѵ�
  double step {(max_x - min_x) / (n_x + 1)};

  // y ���� �ּڰ��� �ִ�
  auto min_y = std::min_element(begin_iter, end_iter, y_comp)->second;
  auto max_y = std::max_element(begin_iter, end_iter, y_comp)->second;

  size_t nrows {1 + static_cast<size_t>(1 + (max_y - min_y)/step)};
  std::vector<string> rows(nrows, string(n_x + 1, ' '));

  // ������ ���� �ȿ� ������ y = 0�� x���� �����Ѵ�
  if(max_y > 0.0 && min_y <= 0.0)
    rows[static_cast<size_t>(max_y/step)] = string(n_x + 1, '-');

  // ������ ���� �ȿ� ������ x = 0�� y���� �����Ѵ�
  if(max_x > 0.0 && min_x <= 0.0)
  {
   size_t x_axis {static_cast<size_t>(-min_x/step)}; 
   std::for_each(std::begin(rows), std::end(rows),
     [x_axis](string& row) { row[x_axis] = row[x_axis] == '-' ? '+' : '|'; });
  }

  std::cout << "\n\n     " << name << ":\n\n";
  // ����� ���� ���� �����Ѵ�
  auto y {max_y};                             // ���� ��� ���� ���� y�� ���Ѱ�
  for(auto& row : rows)
  {
    // Find points to be included in an output row
    std::vector<Point> row_pts;               // �� ���� ������ �����Ѵ�
    std::copy_if(begin_iter, end_iter, std::back_inserter(row_pts),
    [&y, &step](const Point& p) { return p.second < y + step && p.second >= y; });

    std::for_each(std::begin(row_pts), std::end(row_pts),  // �࿡ ������ ���� *�� ����
    [&row, min_x, step](const Point& p)
                       {row[static_cast<size_t>((p.first - min_x) / step)] = '*'; });
    y -= step;
  }
  // ����� ����Ѵ� - ��, ��� ���� ����Ѵ�
  std::copy(std::begin(rows), std::end(rows), std::ostream_iterator<string>{std::cout, "\n"});
  std::cout << std::endl;
}

// y = sin(x)���� x �� 0���� 4�� ���� x, y ������ �����Ѵ� 
std::vector<Point> sine_curve(size_t n_pts = 100)
{ // n_pts�� ��� ����� ������ ������ ����
  std::vector<double> x_values(n_pts);      
  double value {};
  double step {4 * pi / (n_pts - 1)};
  std::generate(std::begin(x_values), std::end(x_values),
    [&value, &step]() { double v {value};
                        value += step;
                        return v; });
  std::vector<Point> curve_pts;
  std::transform(std::begin(x_values), std::end(x_values), std::back_inserter(curve_pts),
    [](double x) { return Point {x, sin(x)}; });
  return curve_pts;
}

// Generate x,y points on a cardioid defined by parametric equations:
// x = a(2cos(t) - cos(2t))  y = a(sin(t) - sin(2t) 
// A cardioid is the path of a point on one circle
// that is rolling around another with the same radius
std::vector<Point> cardioid_curve(double r = 1.0, size_t n_pts = 100)
{ // n_pts�� ������ ������ ����
  double step = 2 * pi / (n_pts - 1);                 // x�� y�� ���� ����
  double t_value {};                                  // � �Ű�����

  // ��� ������ �Ű����� ������ ����
  std::vector<double> t_values(n_pts);                
  std::generate(std::begin(t_values), std::end(t_values), 
                                      [&t_value, step]() { auto value = t_value;
                                                           t_value += step;
                                                           return value; });

  // t�� ���� ������ ��� x, y ���� �����ϴ� �Լ�
  auto cardioid = [r](double t)
                  { return Point {r*(2*cos(t) + cos(2*t)), r*(2*sin(t) + sin(2*t))}; };

  // ������ ��� ������ �����Ѵ�
  std::vector<Point> curve_pts;
  std::transform(std::begin(t_values), std::end(t_values), std::back_inserter(curve_pts),
                                                           cardioid);
  return curve_pts;
}

int main()
{
  auto curve1 = sine_curve(50);
  plot(std::begin(curve1), std::end(curve1), "Sine curve", 90);
  auto curve2 = cardioid_curve(1.5, 120);
  plot(std::begin(curve2), std::end(curve2), "Cardioid", 60);
}