#ifndef _PERSONAL_INFO_H_
#define _PERSONAL_INFO_H_
#include <iostream>
#include <string>

using namespace std;
class PersonalInfo  {
protected:
    string name;    // 이름
public:

    // 이름값 반환
    string getName(){
        return name;
    }
};

#endif