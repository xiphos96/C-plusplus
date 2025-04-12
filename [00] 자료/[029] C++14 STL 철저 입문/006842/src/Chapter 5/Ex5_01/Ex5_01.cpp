// Ex5_01.cpp
// ���� �л����� ����ϱ�
#include <iostream>                              // ǥ�� ��Ʈ��
#include <string>                                // string Ŭ����
#include <map>                                   // map �����̳�
#include <set>                                   // set �����̳�
#include <vector>                                // vector �����̳�
#include <random>                                // ���� ���� ����
#include <algorithm>                             // for_each(), count_if()
#include "Student.h"
#include "List_Course.h"

using std::string;
using Distribution = std::uniform_int_distribution<size_t>;
using Subject = string;                          // �ڽ� ����
using Subjects = std::vector<Subject>;           // ���� ����
using Group = std::set<Student>;                 // ������ ������ �л� �׷�
using Students = std::vector<Student>;           // ��� �л� ����
using Course = std::pair<Subject, Group>;        // �ڽ��� ǥ���� pair
using Courses = std::map<Subject, Group>;        // �ڽ� ������ ���� �����̳�

static std::default_random_engine gen_value;

// �л� ������ ���� students ���͸� �����Ѵ�
Students create_students()
{
  Students students;
  string first_names[] {"Ann", "Jim", "Eve", "Dan", "Ted"};
  string second_names[] {"Smith", "Jones", "Howe", "Watt", "Beck"};

  for(const auto& first : first_names)
  {
    for(const auto& second : second_names)
    {
      students.emplace_back(first, second);
    }
  }
  return students;
}

Group make_group(const Students& students, size_t group_size, 
                 const Distribution& choose_student)
{
  Group group;                   // ������ �����ϴ� �л� �׷�

  // ���� �׷쿡 ����� �л����� �����Ѵ�
  // group_size�� ������ �л����� ������ ������ �׷쿡 ������ �л��� �����Ѵ�
  while(group.size() < group_size)
  {  
    group.insert(students[choose_student(gen_value)]);
  }
  return group;
}


int main()
{
  Students students = create_students();
  Subjects subjects {"Biology", "Physics", "Chemistry", "Mathematics", "Astronomy",
                     "Drama", "Politics", "Philosophy", "Economics"};
  Courses courses;                                         // ���� Ű�� ���� ��ü �ڽ�

  size_t min_subjects {4};                                 // �л��� �ּ� ���� ��
  size_t min_group {min_subjects};                         // �ڽ��� �ּ� �л� ��

  // �ڽ��� �ִ� �л� ��
  size_t max_group {(students.size()*min_subjects)/subjects.size()}; 

  // �� ������ ������ �л����� �׷��� �����Ѵ�
  Distribution group_size {min_group, max_group};          // �ڽ��� �л����� ���� ����
  Distribution choose_student {0, students.size() - 1};    // ���� �л� ���ñ�

  for(const auto& subject : subjects)
    courses.emplace(subject, make_group(students, group_size(gen_value), choose_student));

  Distribution choose_course {0, subjects.size() - 1};     // ���� �ڽ� ���ñ�

  // ��� �л��� �ּ� ���� ���� �⼮�ؾ� �Ѵ�...
  // ... �ּ� ���� ������ �⼮�ϴ��� Ȯ���ؾ� �ϴ� �л���...
  for(const auto& student : students)
  { // �ּ� ���� ������ �����ϴ��� �����Ѵ�

    // �л��� ����� ���� ���� ī��Ʈ
    size_t course_count = std::count_if(std::begin(courses), std::end(courses),
           [&student](const Course& course) { return course.second.count(student); });
    if(course_count >= min_subjects) continue;             // �ּ� ������ �����ϸ� ���� �л�����

    // �ּ� ������ �̴��� ���� ��
    size_t additional {min_subjects - course_count};       // ����� �ʿ��� ���� ��
    if(!course_count)                                      // ������ ������ ���ٸ�...
      std::cout << student << " is work-shy, having signed up for NO Subjects!\n";
    else                                                   // �Ϻ� ���� ����ߴٸ�...
      std::cout << student << " is only signed up for " << course_count << " Subjects!\n";

    std::cout << "Registering " << student << " for " << additional 
              << " more course" << (additional > 1 ? "s" : "") << ".\n\n";

    // �ּ� ���� ����� ���߱� ���� ������ �߰��� ���
    while(course_count < min_subjects)
      if((courses.find(subjects[choose_course(gen_value)])->second.insert(student)).second) ++course_count;
  }

  // �� �ڽ��� �����ϴ� �л����� ���
  std::for_each(std::begin(courses), std::end(courses), List_Course());
  std::cout << std::endl;
}