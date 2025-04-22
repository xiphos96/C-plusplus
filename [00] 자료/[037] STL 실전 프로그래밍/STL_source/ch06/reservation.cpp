//////////////////////////////////////////////////////////////
/// 
/// \file aligning.cpp
///
/// \brief
///  list, map 등을 이용해 예약 시스템 구현
///
/// list, map 등을 이용하여 호텔 방을 예약하는 시스템 구현
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

#include<map>
#include<list>
#include<iostream>
#include<algorithm>
#include<functional>
#include<utility>
#include<string>

template<typename str_t, typename date_t=str_t>
struct book_t
{
	str_t name;
	str_t contact_point;
	date_t start_date;
	date_t end_date;
};

template<typename schedule_t>
struct overlapped_schedule: public std::binary_function< schedule_t, schedule_t, bool>
{
 	bool operator()(schedule_t b1, schedule_t b2) const
  	{
  		if( (b1.start_date <= b2.start_date && b1.end_date >= b2.start_date) )
  			return true;
		if( (b1.start_date <= b2.end_date && b1.end_date >= b2.end_date) )
			return true;
		return false;
	}
};

template<typename str_t, typename date_t>
class reservation_system_t
{
public:

	typedef size_t room_num_t;
	typedef book_t< str_t > my_book_t;
	typedef std::list< my_book_t > agenda_t;
	typedef std::map< room_num_t, agenda_t > rooms_t;
	
private:

	rooms_t rooms;

public:

	void add_room(room_num_t num)
	{
		rooms.insert(std::make_pair(num, agenda_t()));
	}

	bool booking(room_num_t number, const my_book_t book)
	{
		if(book.start_date > book.end_date) return false;
		
		typename rooms_t::iterator iroom = rooms.find( number );
		
		if(iroom == rooms.end()) return false;
		else
		{
			if(can_reservation(iroom, book))
			{
				reserve(iroom, book);
				return true;
			}
		}
		return false;
	}
	
	bool can_reservation(typename rooms_t::iterator iroom, const my_book_t &book)
	{
		if( std::find_if( iroom->second.begin(), iroom->second.end(), 
			std::bind2nd( overlapped_schedule<my_book_t>(), book) )
			== iroom->second.end())
			return true;
		return false;
	}
	
	void reserve(typename rooms_t::iterator iroom, const my_book_t &book)
	{
		iroom->second.push_back(book);
	}
};

int main()
{
	using std::string;
	using std::cout;
	using std::endl;
	
	reservation_system_t<string, string> counter;
	
	for(size_t i=0;i<10; i++)
	{
		counter.add_room(i);
	}
	
	book_t<string> book1;
	book1.name = "stkim";
	book1.start_date = "2004/03/01";
	book1.end_date = "2004/03/05";
	book1.contact_point = "stkim@yujinrobot.com";
	
	if(counter.booking(1, book1))
		cout<<"Success"<<endl;
	else
		cout<<"Fail"<<endl;
	
	book_t<string> book2;
	book2.name = "skok";
	book2.start_date = "2004/03/06";
	book2.end_date = "2004/03/07";
	book2.contact_point = "None";
	
	if(counter.booking(1, book2))
		cout<<"Success"<<endl;
	else
		cout<<"Fail"<<endl;
}