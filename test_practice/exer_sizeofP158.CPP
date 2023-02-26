#include<iostream>
#include<string>


int main()
{
    int x[10] , *p = x;
    
    
    
    std::cout <<  sizeof(x) <<"\n"
    <<  sizeof(*x) <<"\n"
    <<  sizeof x <<"\n"
    <<  sizeof(x)/sizeof(*x) <<"\n"
         <<  sizeof(p) <<"\n"
         <<  sizeof(*p) <<"\n"
         <<  sizeof(p)/sizeof(*p) <<"\n"
         <<std::endl;
    return 0;
}