#pragma warning(disable: 4786) 

#include "BuildingInterface.h"

int main(int argc, char* argv[])
{
	try
	{
		building_interface building("building.dat", std::cin, std::cout );
		
		building_interface::command_t command( building_interface::Invalid );
		
		while(command != building_interface::Exit)
		{
			command = building.menu();
			
			switch(command) 
			{
			case building_interface::Next:
				building.next(); break;
				
			case building_interface::Parking:
				building.parking(); break;
				
			case building_interface::Out:
				building.unparking(); break;
				
			case building_interface::Car_State:
				building.car_state(); break;
				
			case building_interface::Room_State:
				building.room_state(); break;
				
			case building_interface::Floor_State:
				building.floor_state(); break;
				
			case building_interface::Building_State:
				building.building_state(); break;
				
			case building_interface::Long_Term_Stay:
				building.long_term_stay(); break;
				break;

			default: break;
			}
		}
	}
	catch(...)
	{
		std::cout << "Fatal error arised" << std::endl;
	}
}
