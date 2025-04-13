//////////////////////////////////////////////////////////////
/// 
/// \file exist.cpp
///
/// \brief
///  string���� �ܾ� �˻�
///
/// string�� ����Լ� find�� �̿��Ͽ� �־��� �ܾ �˻��ϴ� ��
///
/// \�׽�Ʈȯ��
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

#include<string>
#include<iostream>

class contents_t 
{
private:
	std::string contents;
	
public:
	contents_t(std::string c): contents(c) {}
	
	bool find(const std::string &x) const
	{
		if(contents.find(x) == std::string::npos) return false;
		return true;
	}
};

int main()
{
	contents_t contents("Early worm can catch the bug");
	
	if(contents.find("worm"))
		std::cout<<"Exist"<<std::endl;
	else
		std::cout<<"Not exist"<<std::endl;
}