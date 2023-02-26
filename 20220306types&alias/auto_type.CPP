#include<iostream>

#include "d:\cpp_program\cpp_headers\Sales_item.h"

/* 
    Unlike other type_specifiers,such as 'double' or 'int' that name a specific type, 'auto' tells the compiler to deduce the type from the initializer, and thanks to this mechanism ,a variable that uses 'auto' as its type specifier must have initialier.
 */


int main()
{
    int v1 = 2 ,v2 = 3;
    auto dif = v1 - v2; //variable 'dif' has 'int type'.
    
    Sales_item item1,item2;
    std::cin >>item1>>item2;
    auto record = item1 + item2; // variable 'record' has 'class Sales_item' type.
    
/* 
    NOTE: the reference'&' or pointer'*' is just a modifier/part of a particular declarator,but not the base types. Base Types in c++ are: 'int', 'const int', 'float', 'const float', 'char', 'const char',  'boolean', 'double',etc. 
    As usual, when we define several variables in the same statement,we need to make sure that the initializers must provide 'consistent base types'. 
 * 
 */
    auto &r = v1, *p = &v2 ;//OK
 // auto &r = v1, &item = item1;
    /* ERROR, 'r' is 'int& type',but 'item' is 'class Sales_item& type',they cannot be defined in the same statement.
     */     

    std::cout <<  dif <<"\n"
              <<  record <<"\n"
              <<std::endl;
    return 0;
}