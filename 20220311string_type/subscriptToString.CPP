#include<iostream>
#include<string>
/* 
   we can treat a string as an array in c++, so that we can use the subscript/index to access each character in the string.
 */

int main()
{
    std::string s1 = "I love you";
    s1[0] = 'U'; 
// the subscript operator returns a reference to the character at the given position, start with [0]
    s1[9] = 'O'; // the last character is in s1[s1.size() - 1 ].
    
    decltype(s1.size()) index = 9;
/* since subscripts cannot less than 0, so we can use "a variable of Type string::size_type",
 * as the subscript, and the library is not required the check the value of a subscript,the
 * result of using an out_of_range subscript is undefined. 
 */
    std::cout <<  s1 <<"\n"
         <<  s1[index] <<"\n"
         <<std::endl;
    return 0;
}