#include<iostream>
#include<string>
/* 
   In C++ "an lvalue" is something that points to(allocated in) a specific memory location. On the other hand, a rvalue is something that doesn't point anywhere. 
 * 
   In general, rvalues are temporary and short lived, while lvalues live a longer life since they exist as variables.
 */
int main()
{
    int x = 666;
    /* 
       'x' is an lvalue, 
       '666' is a rvalue, a number(technically a literal constant) has no specific location in the memory, except for "some temporary register in CPU" while the program is running. 
     */

    // int *p = &666;
    //ERROR, because the reason listed above, the address_of operator'&' cannot apply to '666'.
    std::cout <<  0 <<"\n"
         <<  0 <<"\n"
         <<std::endl;
    return 0;
}







