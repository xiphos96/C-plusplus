// Hash_Function_Objects.h
// Ex4_07�� ���� �ؽ� �Լ� ��ü Ÿ��
#ifndef HASH_FUNCTION_OBJECTS_H
#define HASH_FUNCTION_OBJECTS_H

#include <string>                                // string Ŭ����
#include <utility>                               // pair Ÿ��
#include <tuple>                                 // tuple Ÿ��

using Name = std::pair < std::string, std::string >;
using Phone = std::tuple < std::string, std::string, std::string >;

// ��ȭ ��ȣ�� �ؽ��Ѵ�
class PhoneHash
{
public:
  size_t operator()(const Phone& phone) const
  {
    return std::hash<std::string>()(std::get<0>(phone)+std::get<1>(phone)+std::get<2>(phone));
  }
};

// �̸��� �ؽ��Ѵ�
class NameHash
{
public:
  size_t operator()(const Name& name) const
  {
    return std::hash<std::string>()(name.first + name.second);
  }
};
#endif