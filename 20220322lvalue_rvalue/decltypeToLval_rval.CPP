#include<iostream>
#include<string>
/* 
   When we apply 'decltype()' to an expression(NOTE: not a variable!), if the expression yields an lvalue(e.g. decltype(*p)), then it will deduce a reference type.  
 *
   Otherwise, if the expression yields an rvalue(e.g. decltype(&p)), then it may regard the expression as "an address" or "an int" and deduces "a pointer type" or "int type".
 */
 
int ret_rval(){//the return type is 'int', this function returns a rvalue(temporary).
    return 666; 
}


int main()
{
    int a = 10;
    int b = 47;
    decltype(&a) p = &b;//expression '&a' yields an address, so 'p' has the deduced type 'int*'.
    decltype(*p) r = a;//'*p' yields an lvalue, so 'r' has the deduced type 'int&'.
    
    std::cout <<  *p <<"\n"
         <<   r    <<"\n"
         <<std::endl;
    return 0;
}