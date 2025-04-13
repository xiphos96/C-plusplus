//////////////////////////////////////////////////////////////
/// 
/// \file check_exp.cpp
///
/// \brief
///  괄호쌍 검사
///
/// stack을 이용해 괄호쌍 검사를 수행하는 예.
///
/// \테스트환경
///  Gcc3.2.2, Comeau4.3.3, VC++6.0, VC++.NET 2003
///
/// \author 
///  Kim, Seungtai( stkim@yujinrobot.com )
/// 
/// \date
///  - 2004-08-10, Kim, Seungtai, Create
/// 
/// \see
///
//////////////////////////////////////////////////////////////

#include<iostream>
#include<stack>
#include<string>

struct syntax_error{};

int main()
{
	std::string exp;
	std::cout<< "Input the expression: ";
	std::cin >> exp;
	
	try
	{
		std::stack<char> stack;
		size_t cnt(0);
		for(std::string::iterator it=exp.begin(); it != exp.end(); it++){
			
			switch(*it)
			{
			case '(':
				stack.push(*it);
				break;
			case ')':
				if(stack.size() > 0)
				{
					stack.pop();
					cnt++;
				}
				else
					throw syntax_error();
				break;
			default:
				break;
			}
		}
		if(stack.size() >0)
			throw syntax_error();
		else
			std::cout << cnt << std::endl;
	}
	catch(syntax_error)
	{
		std::cout << "Syntax error" << std::endl;
	}
}
