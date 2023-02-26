#include<iostream>
#include<string>
#include<array>
/* 
   When we use a variable as "a subscript" of an array,we normally should define that variable as type 'size_t' which is a machine_specific unsigned(int) type that is guaranteed to be large enough to hold the size of any object in memory.
   'size_t' type is defined in the <cstddef> header. 
 */

#include<cstddef>

int main()
{ 
    std::array<char,7> carray{ "Zen 47"};
/* As with 'string' or 'vector' objects, The best way to traverse an array is still to use "for range" loop:
*/
    for(auto &i : carray){
        i = toupper(i);
    }
 //Using 'size_t' to define a variable for subscript of an array.
    for(size_t j = 0; j != carray.size(); j++){
        std::cout << carray[j];
    }
    std::cout<<std::endl;
   

 
    return 0;
}