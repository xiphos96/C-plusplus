
#include <iostream>
#include <forward_list>

struct ITEM
{
	ITEM(int nItemID) { this->nItemID = nItemID; }
	int nItemID;
};

void print(std::forward_list< ITEM >& flist)
{
	for( auto& item : flist )
    {
		std::cout << item.nItemID << std::endl;;
    }

	std::cout << std::endl;
}

int main()
{
	std::forward_list< ITEM > flist;
 
	for( int i = 1; i <= 2; ++i )
    {
		flist.push_front( i );
    }
 
	print(flist);


    std::cout << "insert_after�� ����Ͽ� �߰�" << std::endl;
    
	flist.insert_after( flist.begin(), ITEM(3) );
                    
    print(flist); 
 

	std::cout << "emplace_after�� ����Ͽ� �߰�" << std::endl; 
	flist.emplace_after( flist.begin(), 4 );
	
	print(flist);

	
	std::cout << "emplace_front�� ����Ͽ� �߰�" << std::endl;
	flist.emplace_front( 5 );

	print(flist);

    return 0;
}

