#include<iostream>
#include<string>


int main()
{
/* In new standard of c++, (-m)%n == -(m%n);  m%(-n) == (m%n); such that, if m%n is nonzero, it has the same sign as 'm'.
 */    
    
    std::cout <<  (-1) % 256 <<"\n" //== -(1%256)
         <<  1 % (-256) <<"\n" // == 1%256
         <<  -1 % (-256) <<"\n"
         <<std::endl;
    return 0;
}