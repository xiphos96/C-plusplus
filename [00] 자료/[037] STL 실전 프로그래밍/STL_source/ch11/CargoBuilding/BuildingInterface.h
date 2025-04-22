#if !defined(BUILDINGINTERFACE_H)
#define BUILDINGINTERFACE_H

#include"BuildingCore.h"
#include<vector>
#include<iostream>


class building_interface
{
public:
	enum command_t { Invalid = 0, Exit, Next, Parking, Out, Car_State, 
		Room_State, Floor_State, Building_State, Long_Term_Stay  };

private:

	building_core building;
	size_t underground;
	size_t ground;
	std::vector<size_t> number_of_rooms;
	
	// 입출력이 일어나는 
	std::istream &in;
	std::ostream &out;
		
	// 기본 요금
	time_t base_time;
	size_t base_fee;
	// 추가 요금
	time_t additional_time;
	size_t additional_fee;

public:

	building_interface( const std::string &filename, std::istream &i, std::ostream &o );

	command_t menu() const;
	bool next() const;
	void parking();
	void unparking();
	void car_state() const;
	void room_state() const;
	void floor_state() const;
	void building_state() const;
	void long_term_stay() const;

private:

	size_t print_floor(std::vector<floor_info_t>::const_iterator it, time_t curr_time) const;
	size_t fee( size_t term ) const;
};


#endif // BUILDINGINTERFACE_H