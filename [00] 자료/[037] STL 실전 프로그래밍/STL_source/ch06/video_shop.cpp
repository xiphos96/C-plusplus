//////////////////////////////////////////////////////////////
/// 
/// \file video_shop.cpp
///
/// \brief
///  vector를 이용해 비디오 가게의 대출 시스템 일부 구현
///
/// vector를 이용하여 비디오 가게에 새로운 손님을 등록하고,,
/// 삭제하는 기능 구현
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
#include<vector>
#include<iomanip>
#include<string>

struct member_t
{	
	std::string name;
	std::string e_mail;
	std::string phone_num;
};

class video_shop
{
private:
	
	std::vector<member_t> members;
	
public:
	
	void add(std::istream &in, std::ostream &out)
	{
		member_t m;
		if(out << "Name: " && in >> m.name && 
			out << "E-mail: " && in >> m.e_mail &&
			out << "Phone Number: " && in >> m.phone_num)
			members.push_back(m);
	}
	
	void print_all(std::ostream &out)
	{
		for(size_t i(0); i<members.size(); i++)
		{
			out << std::setw(5) << i <<": "
				<< members[i].name << ", " 
				<< members[i].e_mail << ", " 
				<< members[i].phone_num << std::endl;
		}
	}
	
	void del(size_t i)
	{
		if(i < members.size())
			members.erase(members.begin() +i);
	}
};

int main()
{
	using namespace std;
	
	video_shop stshop;	
	unsigned short command(0);
	
	while(command != 4)
	{
		cout << "-Video Shop-" << endl;
		cout << "1. New member" << endl;
		cout << "2. Print All" << endl;
		cout << "3. Delete" << endl;
		cout << "4. Exit" << endl;
		
		if(std::cin >> command  && command != 4)
		{
			switch(command)
			{
			case 1:
				stshop.add(std::cin, std::cout);
				break;
			case 2:
				stshop.print_all(std::cout);
				break;
			case 3:
				{
					size_t num;
					
					if(std::cout << "Number: " && std::cin >> num)
						stshop.del(num);
				}
				break;
			}
		}
	} // while
}
