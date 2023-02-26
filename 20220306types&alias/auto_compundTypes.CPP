#include<iostream>
#include<typeinfo>

/* 
    'auto' is just a "type placeholder", the compiler will deduce "the type from the 
    first initializer" right after 'auto', and use it to specify the variable.
    'auto' cannot be used to define 'parameters' or 'arrays', since 'auto' isn't a real type, otherwise the C++ compiler cannot generate such functions in assembly language. 
    
    The type that the compiler infers for 'auto' is not always exactly the same as the initializer's type. 
    Instead, the compiler adjusts the type to conform to normal initialization rules. For example, when we use a reference as a initializer,we are actually using the object to which the reference refers.
 */

int main()
{
    int i = 8, &r = i;
    auto a = r; // 'r' is reference type, 'a' is int type.
    
/* Const levels in 'auto' declaration:
   'auto' ordinarily ignores 'the top_level const of the initializer',but 'the low_level const'  such as when an initializer is 'a pointer to const' are kept.
 */
    const int ci = i; //'ci' is a const int.
    auto b = ci; // 'b' is an plain int (top_level const in 'ci' is dropped).
    auto pi = &i;// 'pi' is 'a pointer to int', ' int* ' type.
    auto pc = &ci; 
    //'pc' is 'a pointer to const int', 'const int*' type, the low_level const in '&ci' kept.
    
    
/* 'const auto'compound specifier:
 * If we want the deduced auto type to have a 'top_level const',we can add 'const' infront:
 */
    const auto ca = ci; //now 'ca' is 'const int' type.
    
/* 'auto' reference:
 */
    auto &ar = ci; 
    /* NOTE: for 'a reference to an auto_deduced type', the top_level const in initializer is not ignored. here 'ci' is top_level const int, 'ar' is a 'const int&' that is bound to 'ci'.
     */ 
 
    std::cout <<  a <<"\n"
              <<  0 <<"\n"
              <<std::endl;
              
//'auto' can deduce "the type of a pointer to a int --'int*' " if the initialier is an array: 
    int arr[3] = {1,2,3};
    auto p = arr;//OK, 'auto' cannot deduce "the type of a pointer to an array 'int (*)[]' ", 'p' has type of 'int*'.
    
    auto ref = arr;//OK,'auto' cannot deduce "the type of a reference to an array 'int (&)[]' ", 'ref' has type of 'int&'. 
    
    std::cout << *(p + 3) << std::endl;
    std::cout << ref[0] << std::endl;
    return 0;
}