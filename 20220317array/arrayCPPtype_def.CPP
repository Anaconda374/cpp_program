#include<iostream>
#include<string>
#include<array> //c++ array type is defined in header<array>.

/* 
   Type "array" is a data structure in c++, an array is a collection of a similar kind of elements or data items that are stored together in continuous memory spaces.
 * 
   An array declarator has the form ' typeName arrName[dimension] ', the dimension specifies the number of elements and must be greater than zero.
   As with "vector type", array holds objects. Thus ,there are no arrays of references.
 */

int main()
{
    
/* List initialization:
    We can omit the dimension in an array definition statement by using list initialization. If we specify a dimension, the number of initializers must not exceed the specified size.
 */
    int arr1[ ] = {1,2,4,5};
    std::cout <<  arr1[2] <<"\n"
            <<std::endl;

/* Dimension of arrays:
 * the dimension/number of elements in an array is part of the array's type, as a result, the dimension must be known at compile time, which means that the dimension must be a constant expression.
 */       
    unsigned cnt = 2; 
    int arr2[cnt];
    //OK,although this statement is valid, the compiler actually treat it as " int arr2[] "
   
    constexpr unsigned sz = 3; 
    int arr3[sz];//appropriate declaration.

// Character arrays: String Initialization & List Initialization. 
    char a1[4] = "abc";
    
/* 
   when using a string literal to initialize a character string, a null character'\0' is added automatically to the end of the string, s.t.,in this case, the dimension of Array'a1' must  greater than 3 in order to store the string "abc".
 */
    char a2[3] = {'a', 'b', 'c'};//using list initialization, no 'null' added automatically.
    
//c++ 'array' type: c++ defined an associative container type 'array'. It's similar to the built-in array(we defined above), but has more functions to manipulate the object.
    std::array<char, 3> digits = {'d','e','f'}; 
    std::array<char, 3> copy = digits;//ok, we can initialize/copy an array(c++ type) from another array(c++ type).
    
    std::array<char, 3> copy = a2;//Error, conversion are not allowed.
    return 0;
}