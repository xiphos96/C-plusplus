// Student.h
// Ex5_02�� ���� Student Ŭ���� ���� - Ex5_01�� ����
#ifndef STUDENT_H
#define STUDENT_H
#include <string>                                // string Ŭ����
#include <ostream>                               // ��� ��Ʈ��

class Student
{
private:
  std::string first {};
  std::string second {};

public:
  Student(const std::string& name1, const std::string& name2) : first (name1), second (name2){}
  Student(Student&& student) : first(std::move(student.first)), second(std::move(student.second)){} // �̵� ������
  Student(const Student& student) : first(student.first), second(student.second){}                  // ���� ������
  Student() {}                                                                                      // �⺻ ������

  // ����-����(<) ������
  bool operator<(const Student& student) const
  {
    return second < student.second || (second == student.second && first < student.first);
  }

  friend std::ostream& operator<<(std::ostream& out, const Student& student);
};

// ���� ������ �����ε�
inline std::ostream& operator<<(std::ostream& out, const Student& student)
{
  out << student.first + " " + student.second;
  return out;
}
#endif