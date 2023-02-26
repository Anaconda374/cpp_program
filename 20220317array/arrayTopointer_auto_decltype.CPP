#include<iostream>
#include<string>
/* 
   In c++, pointers and arrays are closely intertwined. In particular, when we use an array, the compiler ordinary converts the array to a pointer.
 */

int main()
{
/* 
NOTE: 
   a string array is actually a two_dimensional array of character array, means each element in the string array is also a character array.
 */
    std::string sarray1[] = {"zen"};
    for (auto &i : sarray1[0]){
        i = toupper(i);
    }
/* 
   Arrays have a special property -- when we use an array name(without index), the compiler automatically substitutes it by "a pointer which points to the first element of that array".
 */
    std::string *ps1 = &sarray1[0]; 
    std::string *ps2 = sarray1; 
//these two initializers are equal, string* variables 'ps1' and 'ps2' will have the same value.
    std::cout <<  ps1 <<"\n"
         <<  ps2 <<"\n"
         <<std::endl;
         
//'auto' specifier treats "an array initializer" as a pointer:
    auto p = sarray1;// 'p' has the deduced type -- ' string* '.
    std::string s1 = "zen47";
    p = &s1; //'p' can be changed to point other string objects.
    std::cout<< *p <<std::endl;

//'decltype' specifier treats "an array(name) argument" still as an array type:
    decltype(sarray1) sarray2= {"AAA47"};
/* the type returned by 'decltype(sarray1)' is "array of 1 string element",s.t., such that 'sarray2' must have the same array type and the same dimension as 'sarray1'.
 */
    return 0;
    
}