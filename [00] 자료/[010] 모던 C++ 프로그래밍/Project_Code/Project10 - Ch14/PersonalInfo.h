#ifndef _PERSONAL_INFO_H_
#define _PERSONAL_INFO_H_
#include <iostream>
#include <string>

using namespace std;
class PersonalInfo  {
protected:
    string name;               // �̸�
public:
    string getName(){
        return name;
    }
};

#endif