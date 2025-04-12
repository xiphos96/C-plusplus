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
    // ������ 
    OwnerException(std::string pErrorMsg) { errorMsg = pErrorMsg; }
    
    // �Ҹ���
    ~OwnerException(void) throw(){}
    
    // ���� �޼��� 
    const char* what() const throw() { return errorMsg.c_str(); }
};


#endif