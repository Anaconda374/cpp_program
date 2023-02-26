#include<iostream>
#include<string>
#include<bitset>
/* By adding a binary number by itself(same as *2) will left shift all bits by one position,
 * since doing so is actually scaling all positional values by '2' for this binary number. 
 * It is the same idea to multiple "a decimal number by 10" to left shift it by one position.  
 */

int main()
{
    int a = 59 ;
    std::cout << std::bitset<8>(a) <<std::endl;
    std::cout << std::bitset<8>(a*2) <<std::endl;
    std::cout << std::bitset<8>(a*4) <<std::endl;
    
    
    std::cout <<  0 <<"\n"
         <<  0 <<"\n"
         <<std::endl;
    return 0;
}