#pragma warning(disable:4786)
#pragma warning(disable:4503)

#include "DictionaryInterface.h"
#include <iostream>
#include <string>

int main(int argc, char* argv[])
{
	try
	{
		dictionary_interface_t<char> my_dic("dic.dat", std::cin, std::cout, "[", "]" );
		
		dictionary_interface_t<char>::command_t command(
			dictionary_interface_t<char>::Invalid);
		
		while(command != dictionary_interface_t<char>::Exit)
		{
			command = my_dic.menu();
			
			switch(command) 
			{
			case dictionary_interface_t<char>::Query:
				my_dic.query(); break;
				
			case dictionary_interface_t<char>::Load:
				my_dic.load(); break;
				
			case dictionary_interface_t<char>::Merge:
				my_dic.merge(); break;
				
			case dictionary_interface_t<char>::Save:
				my_dic.save(); break;
				
			case dictionary_interface_t<char>::New_Word:
				my_dic.new_word(); break;
				
			default: break;
			}
		}
	}
	catch(...)
	{
		std::cout << "Fatal error arised" << std::endl;
	}
	
	return 0;
}
