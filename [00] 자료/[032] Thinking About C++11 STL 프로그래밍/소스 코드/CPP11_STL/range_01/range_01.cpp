#include <iostream>
  
int main()
{
    int NumberList[5] = { 1, 2, 3, 4, 5 };
 
          
    std::cout << "�Ϲ����� for ��" << std::endl;
          
    for( int i = 0; i < 5; ++i )
    {
                std::cout << i << std::endl;
    }
 
 
    std::cout << "VC++ Ưȭ�� for each��" << std::endl;
 
    for each( int i in NumberList )
    {
                std::cout << i << std::endl;
    }
 
 
    std::cout << "range base for ��" << std::endl;
 
    for( auto i : NumberList )
    {
                std::cout << i << std::endl;
    }
 
    return 0;
}

