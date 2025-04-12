#include <iostream>
 
// unscoped enumeration
enum ITEMTYPE : short
{
    WEAPON,
    EQUIPMENT,
    GEM                          = 10,
    DEFENSE,
};
 
// scoped enumeration
enum class CHARACTER_CLASS : short
{
    WARRIOR                    = 1,     
    MONK,
    FIGHTER,
};
 
enum struct BATTLE_TYPE : short
{
    DEATH_MATCH              = 1,     
    TEAM,
};
 

int main()
{
    // unscoped enumeration
    std::cout << "ITEM WEAPON�� Type ��ȣ : " << ITEMTYPE::WEAPON << std::endl;
 
    short ItemType = EQUIPMENT;
    std::cout << "ITEM EQUIPMENT�� Type ��ȣ : " << ItemType << std::endl;
 
 
 
    /// scoped enumerations
    short CharClassType3 = (short)CHARACTER_CLASS::FIGHTER;
 
    CHARACTER_CLASS CharClass = CHARACTER_CLASS::WARRIOR;
          
    //short   CharClassType    = FIGHTER;                                  // ����                                            
 
    //short   CharClassType2   = CHARACTER_CLASS::FIGHTER; // ����
          
    //CHARACTER_CLASS       CharClass2    = WARRIOR;            // ����
                            
    return 0;
}
