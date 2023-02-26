#include<iostream>
#include<string>
#include<iterator>
/* 
   <iterator> header defined two function 'begin(arrName)' and 'end(arrName)' to arrays, which act like the vector member functions '.begin()' and '.end()'.
   However, arrays are not class types, so these functions are not member functions, instead, they take an argument that is an array.
 */

int main()
{
// "Pointers of arrays" are "Iterators": 
    int ia[] = {1,2,3};
    int *beg = std::begin(ia);
//this statement returns the address of the first element in 'ar' ,it equals to "int *beg = &arr[0]".
    
    int *last = std::end(ia);
/* 
   this statement returns "the address of nonexistent element one past the end element in 'ar'" .
   It equals to "int *last = &arr[size]", but using 'end(arrName)' function is much safier.
 */ 
    std::cout<< *last << std::endl;
    //Caution! To deference a pointer returned by 'end()' is undefined.
    return 0;
}