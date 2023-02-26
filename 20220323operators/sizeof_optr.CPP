#include<iostream>
#include<string>
#include"D:\cpp_program\cpp_headers\Sales_data.h"

/* "sizeof" operator returns the size(in bytes) of an expression or a type. 
 * Form: 1. sizeof(type);
 *       2. sizeof expr ;
 
 */

int main()
{
// "sizeof" to types or exprs:
    std::cout <<  sizeof(int) <<std::endl;
    
    int *pi;
    Sales_data data, *p;
    std::cout <<  sizeof(Sales_data) <<"\n"
         <<  sizeof data <<"\n" 
         <<  sizeof *p <<"\n"
 
    /* 
       These three statements are equivalent, because "sizeof" does not evaluate its operand, so apply 'sizeof' to a uninitialized pointer is safe ,since 'sizeof' does not need dereference the pointer.
     */
        <<  sizeof p << "\n" //A pointer composed of 8 bytes memory. 
        <<  sizeof pi << "\n"
        <<std::endl;
        
// "sizeof" to arrays:
     int x[10] , *parr = x;
    std::cout <<  sizeof(x) <<"\n"//equivalent to " sizeof x ", returns the size of entire array in bytes.
        <<  sizeof(*x) <<"\n"//treat 'x' as an address, returns the size of element which address points.

         <<  sizeof(parr) <<"\n" // 'parr' is a pointer,this statement returns 8 of type 'size_type'
         <<  sizeof(*parr) <<"\n"// returns the size of element which 'parr' points.
         <<  sizeof(parr)/sizeof(*parr) <<"\n"
         <<std::endl;
    return 0;
}