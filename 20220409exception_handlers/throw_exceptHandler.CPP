#include<iostream>
#include<string>
#include"D:\cpp_program\cpp_headers\Sales_item.h"
#include<stdexcept>

/*  
   "A throw" expression consists of the keyword 'throw' followed by an expression. We say that "a throw" raises an exception means if the detecting part(usually a if_statement) encountered something anomalous, then the program throws a exception expression. 
   The type of "the throw expression" determines what kind of exceptions is thrown.
 */


int main()
{
    Sales_item item1, item2;
    input: std::cin>> item1 >> item2;
    // if(item1.isbn() == item2.isbn()){
        // std::cout << item1 + item2 << std::endl;
        // return 0;
    // } else{
        // std::cerr << "Data must refer to same ISBN" << std::endl;
        // return -1;
    // }
    
//The following block of code is equivalent to the block commented above.
    if(item1.isbn() != item2. isbn())
        throw std::runtime_error("Data must refer to same ISBN");
        /* In this throw expression, we use Function 'runtime_error()' which is defined in 
         * <stdexcept> header and must be initialized by giving it "a string" or "a C-style 
         * character string". 
         */
    std::cout << item1 + item2 << std::endl;
    /* When the exception has been thrown, if no appropriate 'catch' is found, excution is
     * transferred to a library function named 'terminate' by default, the behavior of that 
     * function is system dependent but is guaranteed to stop further execution of program.
     */
    
 
    return 0;
}