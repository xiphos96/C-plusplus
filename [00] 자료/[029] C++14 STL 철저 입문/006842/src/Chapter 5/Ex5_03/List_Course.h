// List_Courses.h
// Ex5_03���� �׷쿡 �ִ� �л����� ����ϱ� ���� �Լ� ��ü
#ifndef LIST_COURSE_H
#define LIST_COURSE_H
#include <iostream>                              // ǥ�� ��Ʈ��
#include <string>                                // string Ŭ����
#include <set>                                   // set �����̳�
#include <algorithm>                             // copy()
#include <iterator>                              // ostream_iterator
#include "Student.h"

using Subject = std::shared_ptr<std::string>;    // �ڽ� ����
using Group = std::set<std::weak_ptr<Student>, std::owner_less<std::weak_ptr<Student>>>;  // ���� ����� �л� �׷�
using Course = std::pair<Subject, Group>;        // �ڽ��� ǥ���� pair

class List_Course
{
public:
  void operator()(const Course& course)
  {
    std::cout << "\n\n" << *course.first << "  " << course.second.size() << " students:\n  ";
    std::copy(std::begin(course.second), std::end(course.second), std::ostream_iterator<std::weak_ptr<Student>>(std::cout, "  "));
  }
};

inline std::ostream& operator<<(std::ostream& out, const std::weak_ptr<Student>& wss)
{
  out << *wss.lock();
  return out;
}

#endif