#pragma warning(disable: 4786) 

#include"BuildingInterface.h"
#include<iostream>
#include<fstream>
#include<iterator>
#include<algorithm>
#include<exception>
#include<string>
#include<utility>

// filename이 가리키는 파일에 저장되어 있는 정보로 건물을 초기화한다.
// : 파일의 형식은 
//  [지하층의 수] [지상층의 수] 
//  [기본 시간] [기본 요금 ] 
//  [추가 단위 시간] [추가 요금] [지하부터 지상까지 층별 방의 수]*
building_interface::building_interface( const std::string &filename, 
									   std::istream &i, std::ostream &o )
: in(i), out(o)
{
	std::ifstream infile(filename.c_str());
	
	infile >> underground;
	infile >> ground;

	infile >> base_time >> base_fee;
	infile >> additional_time >> additional_fee;

	std::copy( 
		std::istream_iterator<size_t>(infile), std::istream_iterator<size_t>(),
		std::back_inserter(number_of_rooms) );

	if( underground + ground != number_of_rooms.size() ) 
	{
		number_of_rooms.clear();
		throw std::logic_error( "Invalid File" );
	}

	infile.close();

	building.create( ground, underground, number_of_rooms );
}

// 사용자에게 메뉴를 보여주고, 선택 결과를 반환한다.
building_interface::command_t building_interface::menu() const
{
	out << std::endl;
	out << "-- 주차 빌딩 관리 v1.0--" << std::endl;
	out << "1. 추천 주차 공간" << std::endl;
	out << "2. 주차" << std::endl;
	out << "3. 출차" << std::endl;
	out << "4. 차량 검색" << std::endl;
	out << "5. 방별 상황" << std::endl;
	out << "6. 층별 상황" << std::endl;
	out << "7. 건물 상황" << std::endl;
	out << "8. 장기 주차차량 검색" << std::endl;
	out << "9. 그만하기" << std::endl;
	out << "입력> ";
	
	char user_input;
	in >> user_input ;
	
	switch(user_input) 
	{
	case ('1'): return Next;
	case ('2'): return Parking;
	case ('3'): return Out;
	case ('4'): return Car_State;
	case ('5'): return Room_State;
	case ('6'): return Floor_State;
	case ('7'): return Building_State;
	case ('8'): return Long_Term_Stay;
	case ('9'): return Exit;
	default: break;
	}
	
	return Invalid;
}


bool building_interface::next() const
{
	out << "추천 주차 공간: ";
	
	std::pair< std::string, bool > next = building.get_next_room();
	
	if(next.second)
	{
		out << next.first << std::endl;
		return true;
	}
	else
	{
		out << "주차할 수 있는 공간이 없습니다." << std::endl;
		return false;
	}
}


void building_interface::parking()
{
	if(next())
	{
		out << "차번호: ";
		
		std::string car_id;
		
		in >> car_id;

		out << "방번호: ";
		
		std::string room_id;
		
		in >> room_id;

		time_t curr_time;
		time(&curr_time);
		
		if( building.set_room(room_id, car_id, curr_time) )
		{
			out << "주차하였습니다." << std::endl;
		}
		else
		{
			out << "실패하였습니다." << std::endl;
		}
	}
}

void building_interface::unparking()
{
	out << "방번호: ";

	std::string room_id;

	in >> room_id;

	std::pair<time_t, bool> rst = building.reset_room( room_id );
	
	time_t curr_time;
	time(&curr_time);

	if( rst.second )
	{
		time_t term = curr_time - rst.first;

		out << "시작 시각: " << rst.first << std::endl;
		out << "총 주차 시간: " << term << std::endl;
		out << "요금: " << fee(term) << std::endl;
	}
	else
		out << "실패하였습니다." << std::endl;
}

void building_interface::car_state() const
{
	out << "차번호: ";

	std::string car_id;

	in >> car_id;

	std::pair<room_info_t, bool> room_info = building.get_car( car_id );
	
	time_t curr_time;
	time(&curr_time);

	if( room_info.second )
	{
		out << "방 번호: " << room_info.first.id << std::endl;
		if(room_info.first.in_car)
		{
			time_t term = curr_time - room_info.first.start_time;
			
			out << "시작 시각: " << room_info.first.start_time << std::endl;
			out << "총 주차 시간: " << term << std::endl;
			out << "요금: " << fee(term) << std::endl;
		}
		else
			out << "비어 있습니다." << std::endl;
	}
	else
		out << "실패하였습니다." << std::endl;
}

void building_interface::room_state() const
{
	out << "방번호: ";
	
	std::string room_id;
	
	in >> room_id;
	
	std::pair<room_info_t, bool> room_info = building.get_room( room_id );
	
	time_t curr_time;
	time(&curr_time);
	
	if( room_info.second )
	{
		if(room_info.first.in_car)
		{
			time_t term = curr_time - room_info.first.start_time;
			
			out << "차번호: " << room_info.first.car_id << std::endl;
			out << "시작 시각: " << room_info.first.start_time << std::endl;
			out << "총 주차 시간: " << term << std::endl;
			out << "요금: " << fee(term) << std::endl;
		}
		else
			out << "비어 있습니다." << std::endl;
	}
	else
	{
		out << "실패하였습니다." << std::endl;
	}
}

size_t building_interface::print_floor(std::vector<floor_info_t>::const_iterator it, 
									 time_t curr_time) const
{		
	out << it->id << "층: " << std::endl;

	size_t total_fee(0);

	for(rooms_t::const_iterator 
		it_room = it->rooms.begin(); it_room!=it->rooms.end(); ++it_room)
	{
		out << it_room->second.id;
		if(it_room->second.in_car)
		{
			time_t term = curr_time - it_room->second.start_time;
			size_t curr_fee = fee(term);

			total_fee += curr_fee;

			out << "(" 
				<< it_room->second.car_id << ": "
				<< term << "초, \\" << curr_fee
				<< ")";
		}
		else 
			out << "(X)";
		out << " ";
	}
	out << "총 \\" << total_fee << std::endl;
	return total_fee;
}

void building_interface::floor_state() const
{
	out << "층번호: ";
	
	std::string floor_id;
	
	in >> floor_id;
	
	std::pair<std::vector<floor_info_t>::const_iterator, bool> 
		floor_info = building.get_floor( floor_id );
	
	time_t curr_time;
	time(&curr_time);
	
	if( floor_info.second )
	{
		print_floor(floor_info.first, curr_time);
	}
	else
	{
		out << "실패하였습니다." << std::endl;
	}
}

void building_interface::building_state() const
{		
	std::pair< 
		std::vector<floor_info_t>::const_iterator,
		std::vector<floor_info_t>::const_iterator
		> rst = building.get_building();
	
	time_t curr_time;
	time(&curr_time);
	
	size_t total_fee(0);
	for( std::vector<floor_info_t>::const_iterator it = rst.first; it != rst.second; ++it )
	{
		total_fee += print_floor(it, curr_time);
	}

	out << "총 \\" << total_fee << std::endl;
}

void building_interface::long_term_stay() const
{
	out << "기간(초단위): ";

	time_t term;
	in >> term;
	
	time_t curr_time;
	time(&curr_time);
	
	std::vector<room_info_t> list = building.stay(curr_time, term);
	for( size_t i(0); i<list.size(); ++i)
	{
		time_t term = curr_time - list[i].start_time;
		
		out << "방 번호: " << list[i].id << std::endl;
		if(list[i].in_car)
			out << list[i].car_id << "차량이 "
				<< list[i].start_time << "(" << "\\" << fee(term) << ")부터 "
				<< term << "동안 주차 중입니다."
				<< std::endl;
		else 
			out << "비어 있습니다." << std::endl;		
	}
}

size_t building_interface::fee( size_t term ) const
{
	size_t fee(0);
	if( term > base_time )
	{
		term -= base_time;
		fee += base_fee;
	}
	fee += (term/additional_time)*additional_fee;
	
	return fee;
}