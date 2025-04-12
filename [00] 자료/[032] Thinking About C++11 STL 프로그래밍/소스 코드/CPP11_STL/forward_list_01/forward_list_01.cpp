
#include <iostream>
#include <forward_list>

int main()
{
    std::forward_list< int > flist;
  
    // �߰��ϱ�
    for( int i = 0; i < 5; ++i )
    {
		flist.push_front( i );
    }

	std::cout << "flist�� ù�� ° ��ġ ��: " << flist.front() << std::endl;
                    
    // ��ȸ
    for( auto value : flist )
    {
        std::cout << value;
    }
    std::cout << std::endl; 
    

	std::forward_list< int > flist2;
	flist2.assign(3, 11);

	for( auto value : flist2 )
    {
        std::cout << value;
    }
    std::cout << std::endl;


	std::forward_list< int > flist3;
	flist3.assign(flist.begin(), flist.end());

	for( auto value : flist3 )
    {
        std::cout << value;
    }
    std::cout << std::endl;

	return 0;
}




