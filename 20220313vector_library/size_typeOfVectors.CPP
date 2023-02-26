#include<iostream>
#include<string>
#include<vector>
/* 
   The 'empty()' and 'size()' members behave as do the corresponding string members, 'empty()' returns a bool indicating whether the vector has any elements;'size()' returns "the number of elements in the vector" -- a value of the type 'size_type' defined by the corresponding vector type.
 */
int main()
{
   std::vector<int> ivec {2,4};
   std::vector<int>::size_type s = ivec.size();   
 /* declare 's' as a variable of the type 'size_type' which is suitable for holding the size
  * of a vector. The vector defines its own type for its length, and it's always cleanest to 
  * use 'size_type' variables if possible, rather than "guessing" and using int, unsigned int,
  * long, unsigned long or size_t etc.
  *
  * NOTE: a vector type always includes its element type.
  * such as: " vector<int/string/...>::size_type ... "
  */  
    
    std::cout <<  s <<"\n"
         <<  0 <<"\n"
         <<std::endl;
    return 0;
}