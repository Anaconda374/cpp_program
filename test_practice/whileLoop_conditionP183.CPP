#include<iostream>
#include<string>



int main()
{
    while(int i = getchar()){ //Even 'i' assigned with '0', this condition are still true.
        std::cout<< "true" << std::endl;
    }
    
    
    std::cout <<  0 <<"\n"
         <<  0 <<"\n"
         <<std::endl;
    return 0;
}