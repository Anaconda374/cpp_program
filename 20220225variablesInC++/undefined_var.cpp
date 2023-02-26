#include<iostream>
std::string global_str;
int global_int = 22;

int main()
{
   int local_int ;
   std::string local_str;
   // the undefined/uninitialized build-in type variables cannot to be accessed,
   // but in new standard,it's also automatically initialized. 
   
    std::cout << global_str << global_int << local_int << local_str << "\n"<< std::endl;
    
    int * p ;
    std::cout << *p <<  std:: endl;
    // *p is actually undefined.
    return 0;
}
