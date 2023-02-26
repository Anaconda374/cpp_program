#include<iostream>
#include<string>
/* 
   the compiler may perform implicit lvalue-to-rvalue conversions in many places in a c++ program. And we can only assign a rvalue to an lvalue, but (the compiler) cannot convert it into an lvalue implicitly. 
 */

int main()
{
    int x = 6;
    int y = 41;
    
    int z = x + y ; 
    /* The addition operator wants rvalues: how come? 
     * The answer is quite simple: 'x' and 'y' have undergone an implicit lvalue-to-rvalue conversion.
     * Many other operators perform such conversion, suach as "Arithmetic Operations","relational operations", "logical operations", etc.
     */
    
    
    std::cout <<  z <<"\n"
         <<std::endl;
    return 0;
}