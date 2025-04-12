#ifndef RECORD_IO_H
#define RECORD_IO_H
#include <string>                                // string Ŭ����
#include <istream>                               // istream Ŭ����
#include <ostream>                               // ostream Ŭ����
#include <utility>                               // pair Ÿ��
#include <tuple>                                 // tuple Ÿ��

using Name = std::pair <std::string, std::string>;
using Phone = std::tuple <std::string, std::string, std::string>;

// ��ȭ��ȣ ���
inline std::ostream& operator<<(std::ostream& out, const Phone& phone)
{
  std::string area_code {}, exchange {}, number {};
  std::tie(area_code, exchange, number) = phone;
  out << area_code << " " << exchange << " " << number;
  return out;
}

// �̸� ���
inline std::ostream& operator<<(std::ostream& out, const Name& name)
{
  out << name.first << " " << name.second;
  return out;
}

// ��ȭ��ȣ �Է�
inline std::istream& operator>>(std::istream& in, Phone& phone)
{
  std::string area_code {}, exchange {}, number {};
  in >> std::ws >> area_code >> exchange >> number;
  phone = std::make_tuple(area_code, exchange, number);
  return in;
}

// �̸� �Է�
inline std::istream& operator>>(std::istream& in, Name& name)
{
  in >> std::ws >> name.first >> name.second;
  return in;
}
#endif