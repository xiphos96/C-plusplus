// Hash_Name.h 
// Ex5_06�� Name ��ü�� �ؽ��ϴ� �Լ� ��ü Ÿ��
#ifndef HASH_NAME_H
#define HASH_NAME_H
#include "Name.h"

class Hash_Name
{
public:
  size_t operator()(const Name& name) const {  return name.hash();  }
};
#endif