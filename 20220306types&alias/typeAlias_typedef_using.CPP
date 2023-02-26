#include<iostream>
#include "d:\cpp_program\cpp_headers\Sales_item.h"

/* 
   As program get more complicated, types also get more complicated,A complicated type is hard to write and its compound form may obscure its purpose or meaning.
 * 
   To make the complicated types more succinct, we can use the keywords "typedef" and "using" to make "a pithy alias" to this type.
 * 
   Generally, the 'typedef' declaration is easier to use for defining an alias to a new type. 
 */ 

int main()
{
//Keyword "typedef":
    typedef double wages; // 'wages' is replacement/alias for keyword 'double' 
    typedef wages base, *p ;
    /* we can even define a alias to 'wages' again ,
     *'base' is new alias for 'double', 
     * 'p' for ' double * '. 
     */
    base dv = 3.14;// OK, 'dv' is a double type object.
    p dp = &dv; //OK , 'dp' is a double* type object.
    std::cout <<  dv <<"\n"
              <<  *dp <<"\n"
              <<std::endl;

// Keyword "using":
    using SI = Sales_item; 
    //define an alias to class type Sales_item ,equal to "typedef Sales_item SI" ,
    
  
  
//Use 'typedef' and 'using' to define aliases to "an array":
    typedef int int_arr[4];
    /* this statement is equal to "using int_arr = int[4]",
     * 'int_arr' is a new type of an array of 4 ints.
     */
    int_arr a4 = {1,2,3,4};
    std::cout<< a4[1] <<std::endl;
    
// Use 'typedef' and 'using' to define an alias to a new type of "a pointer to an array":
    int a23[2][3] = {0,2,4,6,8,10}; 
    using pa = int(*)[3];
    /* this statement is equal to " typedef int (*pa)[3] ", 
     * 'pa' is defined as a new type of a pointer which points to an int array.
     */
    pa p1 = a23; //'p1' points to the first row of array.
    std::cout << (*p1)[2]<<std::endl;


    return 0;
}











