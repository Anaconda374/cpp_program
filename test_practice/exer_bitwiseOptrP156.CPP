#include<iostream>
#include<string>
#include<bitset>

int main()
{
    char q = 'q';
    char _8bits = ~q << 6;
    std::cout << std::bitset<8>(_8bits) <<std::endl;
    
    unsigned long _32bits = ~q << 6;
    std::cout << std::bitset<32>(_32bits) <<std::endl;
    
    std::cout <<  0 <<"\n"
         <<  0 <<"\n"
         <<std::endl;
    return 0;
}