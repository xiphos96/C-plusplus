#ifndef OWNER_EXCEPTIONS_H_INCLUDED
#define OWNER_EXCEPTIONS_H_INCLUDED

#include <iostream>
#include <exception>

using namespace std;

class OwnerException : public exception
{
private:
    std::string errorMsg;


public:
    // 생성자 
    OwnerException(std::string pErrorMsg) { errorMsg = pErrorMsg; }
    
    // 소멸자
    ~OwnerException(void) throw(){}
    
    // 에러 메세지 
    const char* what() const throw() { return errorMsg.c_str(); }
};


#endif