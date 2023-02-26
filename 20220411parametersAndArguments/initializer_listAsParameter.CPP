#include<iostream>
#include<string>
#include<initializer_list>
#include"D:\cpp_program\cpp_headers\Sales_item.h"

/* If we do not know in advance how many arguments we need to pass to a function, if all the arguments have the same type, we can pass a library type 'initializer_list', such as to write a routine to print "the error_message generated from the program".
 *
 * why use 'initializer_list' as a parameter?
 * 1. an initializer_list object can be initialized by a list of vary number of const values.
 * 2. it can be iterated by using member functions '.begin' and '.end'.
 * 3. it cannot be used to change the const values in function. 
 */

void error_mes(std::initializer_list<std::string> il){
    for(auto elem : il){
        std::cout << elem <<" ";
    }
}
int main()
{
//Using initializer_list type to deal with the previous except_handler example.
    Sales_item item1, item2;
    while (std::cin >> item1 >> item2){
            if(item1.isbn() != item2. isbn()){
                error_mes({"Data must refer to the same ISBN: ",item1.isbn(), item2.isbn()});
                /* an initializer_list object can be initialized by string variables in curly brackets.
                 */
                std::cout<<std::endl;
            }
            else {
                error_mes({"ISBNs","are","the","same ",item1.isbn()});
                //
                std::cout<<std::endl;
            }
            std::cout << item1 + item2 << std::endl;
           
    }
    return 0;
}