
#include <iostream>
#include <forward_list>

void print(std::forward_list< int >& flist)
{
	for( auto value : flist )
    {
		std::cout << value << std::endl;
    }

	std::cout << std::endl;
}

int main()
{
    std::forward_list< int > flist;
  
    // �߰��ϱ�
    for( int i = 0; i < 6; ++i )
    {
		flist.push_front( i );
    }          
	print(flist);


    std::cout << "pop_front�� ����" << std::endl;

	flist.pop_front();
	print(flist); 
    

	std::cout << "erase_after�� ����" << std::endl;

	flist.erase_after( flist.begin() );
	print(flist); 

	flist.erase_after( flist.begin(), flist.end() );
	print(flist);

	return 0;
}


