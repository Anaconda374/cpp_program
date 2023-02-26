#include<iostream>
/* 
   NOTE: The easiest way to understand 'declarations' is to read them from right to left. " int *const " :means a const pointer which points to an integer, and since it's a const pointer ,so this pointer cannot point to other object in its scope. the const_pointers and the pointer_to_const are totally different!
*/
int main()
{
    int v1 = 8,v2 =16;
    int *const p = &v1; // A const pointer must be initialized in its definition.
    
     std::cout << v1  <<"\n"
               << *p  <<"\n"
               <<std :: endl;
   // p = &v2; ERROR, cannot change the pointing object.
     
    *p = 10;
   /* 
    Unlike " pointer_to_const " ,we can manipulate the pointer(*p) to change the value that it points,as long as this const-pointer doesnot point to a const.
    */
    std::cout << v1  <<"\n"
              << *p  <<"\n"
              <<std::endl;
    
    
    return 0;
}