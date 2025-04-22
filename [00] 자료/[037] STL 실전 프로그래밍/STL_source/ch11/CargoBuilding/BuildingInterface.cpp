#pragma warning(disable: 4786) 

#include"BuildingInterface.h"
#include<iostream>
#include<fstream>
#include<iterator>
#include<algorithm>
#include<exception>
#include<string>
#include<utility>

// filename�� ����Ű�� ���Ͽ� ����Ǿ� �ִ� ������ �ǹ��� �ʱ�ȭ�Ѵ�.
// : ������ ������ 
//  [�������� ��] [�������� ��] 
//  [�⺻ �ð�] [�⺻ ��� ] 
//  [�߰� ���� �ð�] [�߰� ���] [���Ϻ��� ������� ���� ���� ��]*
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

// ����ڿ��� �޴��� �����ְ�, ���� ����� ��ȯ�Ѵ�.
building_interface::command_t building_interface::menu() const
{
	out << std::endl;
	out << "-- ���� ���� ���� v1.0--" << std::endl;
	out << "1. ��õ ���� ����" << std::endl;
	out << "2. ����" << std::endl;
	out << "3. ����" << std::endl;
	out << "4. ���� �˻�" << std::endl;
	out << "5. �溰 ��Ȳ" << std::endl;
	out << "6. ���� ��Ȳ" << std::endl;
	out << "7. �ǹ� ��Ȳ" << std::endl;
	out << "8. ��� �������� �˻�" << std::endl;
	out << "9. �׸��ϱ�" << std::endl;
	out << "�Է�> ";
	
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
	out << "��õ ���� ����: ";
	
	std::pair< std::string, bool > next = building.get_next_room();
	
	if(next.second)
	{
		out << next.first << std::endl;
		return true;
	}
	else
	{
		out << "������ �� �ִ� ������ �����ϴ�." << std::endl;
		return false;
	}
}


void building_interface::parking()
{
	if(next())
	{
		out << "����ȣ: ";
		
		std::string car_id;
		
		in >> car_id;

		out << "���ȣ: ";
		
		std::string room_id;
		
		in >> room_id;

		time_t curr_time;
		time(&curr_time);
		
		if( building.set_room(room_id, car_id, curr_time) )
		{
			out << "�����Ͽ����ϴ�." << std::endl;
		}
		else
		{
			out << "�����Ͽ����ϴ�." << std::endl;
		}
	}
}

void building_interface::unparking()
{
	out << "���ȣ: ";

	std::string room_id;

	in >> room_id;

	std::pair<time_t, bool> rst = building.reset_room( room_id );
	
	time_t curr_time;
	time(&curr_time);

	if( rst.second )
	{
		time_t term = curr_time - rst.first;

		out << "���� �ð�: " << rst.first << std::endl;
		out << "�� ���� �ð�: " << term << std::endl;
		out << "���: " << fee(term) << std::endl;
	}
	else
		out << "�����Ͽ����ϴ�." << std::endl;
}

void building_interface::car_state() const
{
	out << "����ȣ: ";

	std::string car_id;

	in >> car_id;

	std::pair<room_info_t, bool> room_info = building.get_car( car_id );
	
	time_t curr_time;
	time(&curr_time);

	if( room_info.second )
	{
		out << "�� ��ȣ: " << room_info.first.id << std::endl;
		if(room_info.first.in_car)
		{
			time_t term = curr_time - room_info.first.start_time;
			
			out << "���� �ð�: " << room_info.first.start_time << std::endl;
			out << "�� ���� �ð�: " << term << std::endl;
			out << "���: " << fee(term) << std::endl;
		}
		else
			out << "��� �ֽ��ϴ�." << std::endl;
	}
	else
		out << "�����Ͽ����ϴ�." << std::endl;
}

void building_interface::room_state() const
{
	out << "���ȣ: ";
	
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
			
			out << "����ȣ: " << room_info.first.car_id << std::endl;
			out << "���� �ð�: " << room_info.first.start_time << std::endl;
			out << "�� ���� �ð�: " << term << std::endl;
			out << "���: " << fee(term) << std::endl;
		}
		else
			out << "��� �ֽ��ϴ�." << std::endl;
	}
	else
	{
		out << "�����Ͽ����ϴ�." << std::endl;
	}
}

size_t building_interface::print_floor(std::vector<floor_info_t>::const_iterator it, 
									 time_t curr_time) const
{		
	out << it->id << "��: " << std::endl;

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
				<< term << "��, \\" << curr_fee
				<< ")";
		}
		else 
			out << "(X)";
		out << " ";
	}
	out << "�� \\" << total_fee << std::endl;
	return total_fee;
}

void building_interface::floor_state() const
{
	out << "����ȣ: ";
	
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
		out << "�����Ͽ����ϴ�." << std::endl;
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

	out << "�� \\" << total_fee << std::endl;
}

void building_interface::long_term_stay() const
{
	out << "�Ⱓ(�ʴ���): ";

	time_t term;
	in >> term;
	
	time_t curr_time;
	time(&curr_time);
	
	std::vector<room_info_t> list = building.stay(curr_time, term);
	for( size_t i(0); i<list.size(); ++i)
	{
		time_t term = curr_time - list[i].start_time;
		
		out << "�� ��ȣ: " << list[i].id << std::endl;
		if(list[i].in_car)
			out << list[i].car_id << "������ "
				<< list[i].start_time << "(" << "\\" << fee(term) << ")���� "
				<< term << "���� ���� ���Դϴ�."
				<< std::endl;
		else 
			out << "��� �ֽ��ϴ�." << std::endl;		
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