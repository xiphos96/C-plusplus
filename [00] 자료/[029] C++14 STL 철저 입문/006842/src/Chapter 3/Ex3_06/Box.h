// Box.h
// Carton Ŭ������ ����� �� Box Ŭ���� ����
#ifndef BOX_H
#define BOX_H
#include <iostream>                              // ǥ�� ��Ʈ��
#include <istream>                               // ��Ʈ�� Ŭ����
#include <utility>                               // �� ������ ���ø�
using namespace std::rel_ops;                    // �� ������ ���ø� ���ӽ����̽�

class Box
{
protected:
  size_t length {};
  size_t width {};
  size_t height {};

public:
  explicit Box(size_t l = 1, size_t w = 1, size_t h = 1) : length {l}, width {w}, height {h} {}
  virtual ~Box() = default;

  virtual double volume() const;                 // ������ ����

  // Box ��ü�� �� ������
  bool operator<(const Box& box) const;
  bool operator==(const Box& box) const;

  // �Է� ��Ʈ���� ��� ��Ʈ��
  virtual std::istream& read(std::istream& in);
  virtual std::ostream& write(std::ostream& out) const;
};


inline double Box::volume() const { return length*width*height; }

// < ������
inline bool Box::operator<(const Box& box) const 
{ return volume() < box.volume(); }

// ���(equality) �� ������
inline bool Box::operator==(const Box& box) const
{
  return length == box.length && width == box.width && height == box.height;
}

// operator>> ������(��Ʈ�� ����)
inline std::istream& operator>>(std::istream& in, Box& box)
{
  return box.read(in);
}

// operator<< ������(��Ʈ�� ����)
inline std::ostream& operator<<(std::ostream& out, Box& box)
{
  return box.write(out);
}
#endif