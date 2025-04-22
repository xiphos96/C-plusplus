//////////////////////////////////////////////////////////////
/// 
/// \file windows.cpp
///
/// \brief
///  vector를 이용해 윈도우 관리
///
/// vector의 멤버로써 윈도우에 대한 포인터를 관리하며
/// 현재 실행 중인 윈도우들을 정렬된 순서로 가져오는 윈도우 
/// 관리 시스템 구현
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
#include<string>
#include<vector>
#include<algorithm>
#include<ctime>

struct window_t
{
	// ... DATAs for windows
	std::string name;
	size_t z_order;
	size_t time;
};


bool z_order_comp( const window_t * p, const window_t * q )
{
	if( p->z_order < q->z_order ) return true;
	return false;
}

bool time_comp( const window_t * p, const window_t * q )
{
	if( p->time < q->time ) return true;
	return false;
}

bool name_comp( const window_t * p, const window_t * q )
{
	if( p->name < q->name ) return true;
	return false;
}

void print(const window_t &window)
{
	std::cout << window.name << ": " << window.z_order << ", " << window.time << std::endl;
}

class windows_sort
{
private:
	std::vector<const window_t *> windows;

public:

	void add(const window_t *pwindow)
	{
		windows.push_back(pwindow);
	}

	std::vector< const window_t * > z_order() const 
	{
		std::vector< const window_t * > twindows( windows );
		
		std::sort( twindows.begin(), twindows.end(), z_order_comp );

		return twindows;
	}
	
	std::vector< const window_t * > time() const
	{
		std::vector< const window_t * > twindows( windows );
		
		std::sort( twindows.begin(), twindows.end(), time_comp );
		
		return twindows;
	}
	
	std::vector< const window_t *> name() const
	{
		std::vector< const window_t * > twindows( windows );

		std::cout << twindows[0]->name;

		std::sort( twindows.begin(), twindows.end(), name_comp );
		
		std::cout << twindows[0]->name;

		return twindows;
	}
};

int main()
{
	window_t window1, window2, window3;
	
	window2.name = "window2";
	window2.time = 1;
	window2.z_order = 2;
	window1.name = "window1";
	window1.time = 2;
	window1.z_order = 3;
	window3.name = "window3";
	window3.time = 3;
	window3.z_order = 1;

	windows_sort wsort;
	
	wsort.add( &window2 );
	wsort.add( &window1 );
	wsort.add( &window3 );
	
	std::vector< const window_t * > name_sorted = wsort.name();
	std::vector< const window_t * > time_sorted = wsort.time();
	std::vector< const window_t * > z_order_sorted = wsort.z_order();

	std::cout << "Name Sorted" << std::endl;
	for(size_t i(0); i<name_sorted.size(); ++i) print(*name_sorted[i]);
	
	std::cout << std::endl;
	std::cout << "Time Sorted" << std::endl;
	for(size_t j(0); j<time_sorted.size(); ++j) print(*time_sorted[j]);
	
	std::cout << std::endl;
	std::cout << "Z-order Sorted" << std::endl;
	for(size_t k(0); k<z_order_sorted.size(); ++k) print(*z_order_sorted[k]);
}