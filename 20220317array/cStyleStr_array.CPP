#include<iostream>
#include<string>
/* C++ supports two different types of strings: 
 * 1. std::string (as part of the standard library),
 * 2. C-style strings (natively, as inherited from the C language).
 * A C-style string is simply an array of characters that uses a null terminator, char ca[] ="str"
 * More generically, A C-style string is called a null-terminated string.
 *
 * NOTE: For most applications, it is more efficient and safer to use "library strings" rather
 *       than "C-style strings".
 */


#include<cstring>
int main()
{
/* C-style string functions:(defined in <cstring> header)
    The standard library provides a set of functions operate on C-style strings, these functions manipulate strings through 'pointers', in order to let these functions dectect the end of a string, we must ensure that string is null_terminated.
 */
    
//Function 'strlen()':
    char ca1[] = {'c', '+', '+'};
    //in such this list intialization form, the C-style string 'ca1' is not null-terminated.   
    std::cout <<  std::strlen(ca1) <<std::endl;
    /* Diaster: Func'strlen(ca1)' will keep looking through the memory that follows Address'ca1' until it encounters a null character.
     */
    char ca2[] = "c++";// null_terminated.
    std::cout <<  std::strlen(ca2) <<std::endl;//get the correct length of string 'ca2'.
    
// Function 'strcmp()':
    char ca3[] = "A c style string";
    char ca4[] = "A d style string";
    /* Unlike "library strings" that can be compared by using equal sign'==' or relational operators "<, >, <=, >="; we need to use the 'strcmp(arr1, arr2)' the compare two C-style strings.
     */
    std::cout<< std::strcmp(ca3, ca4) <<std::endl;
    
   
 // Function 'strcat(largeStr, ca1)'
    char ca5[4] = "I ";
    char ca6[] = "love you";
    std::strcat(ca5, ca6);
    std::cout<< ca5 << std::endl;
    return 0;
}