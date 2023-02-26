#include<iostream>

int main()
{
    const int cval = 20;
    const int *pc ;
    pc = &cval;
    // 'pc' is "a pointer to const" which points to a const object'ival',. 
    
    int ival = 80;
    const int *pi = &ival;
    // "A pointer to const" can also point to "a plain int type",  
    int * p = &ival;
    ival = 79; 
    //'ival' can be changed even though it's pointed by a 'point_to_const'.
    std::cout << ival <<"\n"
              << *pi  <<"\n"
              << *p   <<"\n"
              <<std::endl;
    /* Like a reference to const ,"the main idea of a pointer to const" is that it cannot be deferenced to change the object it points,but it's important to remember that there is no guarantee that an object pointed by "a pointer to const" won't change, this knowledge is related to "the Top_and_low_level const theory".     
     */
    
    return 0;
}