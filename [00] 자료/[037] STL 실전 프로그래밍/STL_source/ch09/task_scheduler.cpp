//////////////////////////////////////////////////////////////
/// 
/// \file task_scheduler.cpp
///
/// \brief
///  �׽�ũ �Ŵ���
///
/// CPU�� ���� ó���ؾ� �� ���� ��ȯ�ϴ� �����ڸ� priority_queue��
/// �̿��� ����
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

#include<queue>
#include<iostream>
#include<limits>

template<typename priority_t>
struct task 
{ 
	priority_t	priority;
	
	task(priority_t p) : priority(p){}
	task()
		:priority(std::numeric_limits<priority_t>::min()) {}
};

template<typename priority_t>
bool operator < (
				 const task<priority_t>& t1, 
				 const task<priority_t>& t2) 
{	
	return t1.priority < t2.priority; 
}

int main() 
{ 	
	std::priority_queue< task<unsigned short> > scheduler; 
	task<unsigned short> a(3),b(4),c(4),d,e;
	
	scheduler.push(a); 
	scheduler.push(b); 
	scheduler.push(c); 
	scheduler.push(d); 
	scheduler.push(e); 
	
	while(!scheduler.empty()) 
	{ 
		std::cout << scheduler.top().priority << " ";
		scheduler.pop(); 
		// Execute it
	} 
}
