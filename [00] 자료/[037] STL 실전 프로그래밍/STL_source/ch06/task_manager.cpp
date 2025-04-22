//////////////////////////////////////////////////////////////
/// 
/// \file task_manager.cpp
///
/// \brief
///  list를 이용해 작업 관리자 구현
///
/// list를 이용하여 프로세스를 추가하고 죽이고, 보여주는 작업
/// 관리자 구현
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
#include<list>
#include<algorithm>

class task_manager
{	
private:	
	
	typedef size_t id_t;
	std::list<id_t> processes;
	
public:
	
	void activate_process(id_t id)
	{
		processes.push_back(id);
		processes.sort();
	}
	
	void kill_proicess(id_t id)
	{
		processes.erase(
			std::find(processes.begin(), processes.end(), id));
	}
	
	void show_process(std::ostream &out)
	{
		for(std::list<id_t>::const_iterator 
			it=processes.begin(); it!= processes.end(); it++){
			out << *it << " ";
		}
		out<< std::endl;
	}
};

int main()
{
	task_manager tm;
	
	tm.activate_process( 10 );
	tm.activate_process( 9 );
	tm.show_process( std::cout );
	
	tm.kill_proicess( 9 );
	tm.show_process( std::cout );
}