// Box.cpp
// Box Ŭ������ �Լ� ��� ����
#include <iostream>
#include "Box.h"

// ��Ʈ������ Box ��ü�� �б�
std::istream& Box::read(std::istream& in)
{
  size_t value {};
  if ((in >> value).eof())
    return in;
  length = value;
  in >> width >> height;
  return in;
}

// ��Ʈ���� Box ��ü�� ����
std::ostream& Box::write(std::ostream& out) const
{
  out << typeid(*this).name() << "(" << length << "," << width << "," << height << ")";
  return out;
}
