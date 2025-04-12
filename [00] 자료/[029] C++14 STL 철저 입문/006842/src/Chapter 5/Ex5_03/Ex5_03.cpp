// Ex5_03.cpp
// ���� �л����� ����Ű�� ����Ʈ �����͸� ����ϱ�
#include <iostream>                              // ǥ�� ��Ʈ��
#include <string>                                // string Ŭ����
#include <map>                                   // map �����̳�
#include <set>                                   // set �����̳�
#include <vector>                                // vector �����̳�
#include <random>                                // ���� ���� ����
#include <algorithm>                             // for_each(), count_if()
#include <memory>                                // shared_ptr, weak_ptr
#include <cctype>                                // toupper()
#include "Student.h"
#include "List_Course.h"

using std::string;
using std::make_shared;
using Distribution = std::uniform_int_distribution<size_t>;
using Subject = std::shared_ptr<string>;                                                  // �ڽ� ����
using Subjects = std::vector<Subject>;                                                    // ���� ����
using Group = std::set<std::weak_ptr<Student>, std::owner_less<std::weak_ptr<Student>>>;  // ������ ������ �л� �׷�
using Students = std::vector<std::shared_ptr<Student>>;                                   // ��� �л� ����
using Course = std::pair<Subject, Group>;                                                 // �ڽ��� ǥ���� pair
using Courses = std::map<Subject, Group, std::owner_less<Subject>>;                       // �ڽ� ������ ���� �����̳�

static std::default_random_engine gen_value;

// �л����� �����ϴ� ����Ʈ �������� ���͸� �����Ѵ�
Students create_students()
{
  Students students;
  string first_names[] {"Ann", "Jim", "Eve", "Dan", "Ted"};
  string second_names[] {"Smith", "Jones", "Howe", "Watt", "Beck"};

  for(const auto& first : first_names)
    for(const auto& second : second_names)
    {
      students.emplace_back(std::make_shared<Student>(first, second));
    }

  return students;
}

// ������ �����ϴ� �л����� �׷��� �����Ѵ�
Group make_group(const Students& students, size_t group_size, const Distribution& choose_student)
{
  Group group;                                             // ������ �����ϴ� �л� �׷�

  // ���� �׷쿡 ����� �л����� �����Ѵ�
  size_t count {};                                         // �׷쿡 ��ϵ� �л� ��
  std::pair<Group::iterator, bool> pr;                     // �л� ���Կ��� ��ȯ�� ���� �����Ѵ�

  // group_size�� ������ �л����� ������ ������ �׷쿡 ������ �л��� �����Ѵ�
  while(count < group_size)
  {  // ������ �����ϸ� ī��Ʈ�� ������Ų��...
    if(group.insert(students[choose_student(gen_value)]).second) ++count;
  }
  return group;
}

int main()
{
  Students students = create_students();
  Subjects subjects {make_shared<string>("Biology"), make_shared<string>("Physics"), make_shared<string>("Chemistry"),
                     make_shared<string>("Mathematics"), make_shared<string>("Astronomy"), make_shared<string>("Drama"), 
                     make_shared<string>("Politics"), make_shared<string>("Philosophy"), make_shared<string>("Economics")};
  Courses courses;                                         // ���� Ű�� ���� ��ü �ڽ�

  size_t min_subjects {4};                                 // �л��� �ּ� ���� ��
  size_t min_group {min_subjects};                         // �ڽ��� �ּ� �л� ��
  
  // �ڽ��� �ִ� �л� ��
  size_t max_group {(students.size()*min_subjects) / subjects.size()};  
  
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
    size_t course_count = std::count_if(std::begin(courses), std::end(courses), [&student](const Course& course)
    {  return course.second.count(student); });
    if(course_count >= min_subjects) continue;             // �ּ� ������ �����ϸ� ���� �л�����

    // �ּ� ������ �̴��� ���� ��
    size_t additional {min_subjects - course_count};       // �߰� ����� �ʿ��� ���� ��
    if(!course_count)                                      // ������ ������ ���ٸ�...
      std::cout << *student << " is work-shy, having signed up for NO Subjects!\n";
    else                                                   // �Ϻ� ���� ����ߴٸ�...
      std::cout << *student << " is only signed up for " << course_count << " Subjects!\n";

    std::cout << "Registering " << *student << " for " << additional
      << " more course" << (additional > 1 ? "s" : "") << ".\n\n";

    // �ּ� ���� ����� ���߱� ���� ������ �߰��� ���
    while(course_count < min_subjects)
      if((courses.find(subjects[choose_course(gen_value)])->second.insert(student)).second) ++course_count;
  }

  // �� �ڽ��� �����ϴ� �л����� ���
  //std::for_each(std::begin(courses), std::end(courses), List_Course());
  //std::cout << std::endl;

  // �ڽ� ������ ����ϱ�
  std::cout << "Course subjects are:\n  ";
  for(const auto& p : subjects)
    std::cout  << *p << "  ";
  std::cout << "\n\n";

  // �л����� ����� �ڽ��� �����ϱ�
  char answer {'Y'};
  string subject {};
  while(std::toupper(answer) == 'Y')
  {
    std::cout << "Enter a course subject to get the list of students: ";
    std::cin >> subject;
    auto iter = std::find_if(std::begin(subjects), std::end(subjects), [&subject](const Subject& psubj){ return subject == *psubj; });
    if(iter == std::end(subjects))
      std::cout << subject << " not found!\n";
    else
    {
      List_Course()(*courses.find(*iter));
      std::cout << std::endl;
    }
    std::cout << "Do you want to see another subject(Y or N)? ";
    std::cin >> answer;
  }
}
