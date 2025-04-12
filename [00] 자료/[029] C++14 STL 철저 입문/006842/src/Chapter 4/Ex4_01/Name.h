// Name.h for Ex4_01
// ����� �̸��� �����Ѵ�
#ifndef NAME_H
#define NAME_H
#include <string>                                // string Ŭ����
#include <ostream>                               // ��� ��Ʈ��
#include <istream>                               // �Է� ��Ʈ��

class Name
{
private:
  std::string first {};
  std::string second {};

public:
  Name(const std::string& name1, const std::string& name2) : first (name1), second (name2) {}
  Name() = default;

  //  ����-����(<) ������
  bool operator<(const Name& name) const
  {
    return second < name.second || (second == name.second && first < name.first);
  }

  friend std::istream& operator>>(std::istream& in, Name& name);
  friend std::ostream& operator<<(std::ostream& out, const Name& box);
};

// ���� ������ �����ε�
inline std::istream& operator>>(std::istream& in, Name& name)
{
  in >> name.first >> name.second;
  return in; 
}

// ���� ������ �����ε�
inline std::ostream& operator<<(std::ostream& out, const Name& name)
{
  out << name.first + " " + name.second;
  return out;
}

#endif
