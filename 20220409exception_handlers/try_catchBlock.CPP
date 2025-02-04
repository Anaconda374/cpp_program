#include<iostream>
#include<string>
#include<stdexcept>
#include"D:\cpp_program\cpp_headers\Sales_item.h"
/* "try block" constitute the normal logic of the program.
 * 'catch' means to catch if there is a (such type of) exception has been thrown in try block,
 * if so, then the "catch block" will be executed.
 *
 * except the "throw expression" in 'try', other variables declared inside a try block are 
 * inaccessible outside the block -- in particular, they are not accessible to the catch block. 
 */


int main()
{
    Sales_item item1, item2;
    
    while (std::cin >> item1 >> item2){
        try {
            if(item1.isbn() != item2. isbn()){
            throw std::invalid_argument("Data must refer to same ISBN");
            /* The throw expression has type 'std::runtime_error' which allows us to output
             * "an error alert".
             */
            }
            if(item1.avg_price() > 100 || item2.avg_price()>100){
                throw std::out_of_range("The price can not greater than 100");
            }
            std::cout << item1 + item2 << std::endl;
            
        }catch (std::exception& errMessage){
        /* 
        Exception declaration 'catch(decl)' specifies the type of exceptions the catch can handle, 'std::exception' can catch any type of exception defined in STL and use it to define a  object'errMessage' if it is thrown nin 'try'.
         */
          std::cout << errMessage.what()
            /* '.what()' is a member function of Class'runtime_error', each of the library 
             * exception classes defines a member function named '.what()', this function
             * takes no argument and return a c_style character string.
             */
                      << "\nTry again? Enter y/n" <<std::endl;
            char c;
            std::cin >> c;
            if (!std::cin || c == 'n'){
                break;
            }
                
        }
    }
    
    

    return 0;
}