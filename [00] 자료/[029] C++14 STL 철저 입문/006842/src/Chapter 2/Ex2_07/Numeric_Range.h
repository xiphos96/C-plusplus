// Numeric_Range.h for Ex2_07
// ������ ���� Ŭ���� ���ø��� ���� ������ ���� �ݺ��� Ŭ���� ���ø��� ����
#ifndef NUMERIC_RANGE_H
#define NUMERIC_RANGE_H

#include <exception>                             // ǥ�� �ͼ��� Ÿ��
#include <iterator>                              // �ݺ��� Ÿ��
#include <type_traits>                           // ������ Ÿ�� Ÿ�� üŷ

template <typename T> class Numeric_Iterator;    // ���ø� Ÿ�� ����

// ���� ������ ����
template<typename T>
class Numeric_Range
{
  static_assert(std::is_integral<T>::value || std::is_floating_point<T>::value,
                                 "Numeric_Range type argument must be numeric.");

  friend class Numeric_Iterator <T>;

private:
  T start;                                       // �������� ù ��° ��
  T step;                                        // ���� ���� ������
  size_t count;                                  // ������ �ִ� ���� ����

public:
  explicit Numeric_Range(T first=0, T incr=1, size_t n=2) : start {first}, step {incr}, count {n}{}

  // ������ ���� ���� �ݺ��ڸ� ��ȯ
  Numeric_Iterator<T> begin(){ return Numeric_Iterator<T>(*this); }

  // ������ ���� �� �ݺ��ڸ� ��ȯ
  Numeric_Iterator<T> end()
  {
    Numeric_Iterator<T> end_iter(*this);
    end_iter.value = start + count*step;          // �� �ݺ��� ���� ���������� �ϳ� �� ������ ��
    return end_iter;
  }
};

// �ݺ��� Ŭ���� ���ø� - ������ �ݺ���
template<typename T>
class Numeric_Iterator : public std::iterator <std::forward_iterator_tag, T>
{
  friend class Numeric_Range <T>;

private:
  Numeric_Range<T>& range;                       // �� �ݺ��� ������ ���� ����
  T value;                                       // ������ ����Ű�� ��

public:
  explicit Numeric_Iterator(Numeric_Range<T>& a_range) : range {a_range}, value {a_range.start} {};

  // �Ҵ� ������
  Numeric_Iterator& operator=(const Numeric_Iterator& src)
  {
    range = src.range;
    value = src.value;
  }

  // �ݺ��ڸ� �������Ѵ�
  T& operator*() 
  {
    // ���� ���������� �ϳ� �� �ڶ�� �� ���� �� �ݺ��ڴ�
    if (value == static_cast<T>(range.start + range.count*range.step))
    {
      throw std::logic_error("Cannot dereference an end iterator.");
    }
    return value;
  }

  // ��ġ ���� ������
  Numeric_Iterator& operator++()
  {
    // ���� ���������� �ϳ� �� �ڶ�� �� ���� �� �ݺ��ڴ�
    if (value == static_cast<T>(range.start + range.count*range.step))
    {
      throw std::logic_error("Cannot increment an end iterator.");
    }
    value += range.step;                         // ���� ���ܸ�ŭ ���� ����
    return *this;
  }

  // ��ġ ���� ������
  Numeric_Iterator operator++(int)
  {
    // ���� ���������� �ϳ� �� �ڶ�� �� ���� �� �ݺ��ڴ�
    if (value == static_cast<T>(range.start + range.count*range.step))
    {
      throw std::logic_error("Cannot increment an end iterator.");
    }
    auto temp = *this;
    value += range.step;                         // ���� ���ܸ�ŭ ���� ����
    return temp;                                 // �����Ǳ� ���� �ݺ���
  }

  // ��
  bool operator<(const Numeric_Iterator& iter) const { return value < iter.value; }
  bool operator==(const Numeric_Iterator& iter) const { return value == iter.value; }
  bool operator!=(const Numeric_Iterator& iter) const { return value != iter.value; }
  bool operator>(const Numeric_Iterator& iter) const { return value > iter.value; }
  bool operator<=(const Numeric_Iterator& iter) const { *this < iter || *this == iter;}
  bool operator>=(const Numeric_Iterator& iter) const { *this > iter || *this == iter;}
};
#endif
