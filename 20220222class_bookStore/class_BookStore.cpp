#include<iostream>

#include "d:\cpp_program\cpp_headers\Sales_item.h"

int main()
{
    Sales_item total;
    if(std::cin >> total){
        Sales_item trans;
        while(std::cin >> trans){
            if (total.isbn() == trans.isbn()){
                total = total + trans;
            }else{
                std::cout << total << std::endl;
                total = trans;
          
            }
   
        }
        std::cout << total << std::endl;
    }else{
        std::cerr << " No data ?! " << std::endl;
        return -1;
    }
    
    return 0;
    /* ctrl+z is recognized as eof only at the beginning of a line in Windows.
     * A line should end with a newline character, not a ctrl+z character.
     */
}