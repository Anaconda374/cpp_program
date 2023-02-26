#include<iostream>
#include<string>
#include<cstdarg>
/* 
    Ellipsis parameters'...' in C++ allows the function to accept an indeterminate number of arguments. It is also known as the variable argument list('varargs') which is inherited from C language and contained in header <cstdarg> under spacename 'std'.
 * 
    In order to access and manipulate "the values in an ellipsis", the library define 1 type and 3 functions to achieve it:
       'va_list' :a type which is used to access the values in the ellipsis. It will be conceptually easy for you if you think of ellipsis as an array. In that case, va_list will act as the iterator type. The va_list is not a special type. It is a macro definition.
 *
    'va_start(va_list ap, parmN)': let the va_list object point to the starting element of the ellipsis. It takes two arguments: va_list itself and the last normal parameter (non-ellipsis).
 *
    'va_arg(va_list ap, type)': returns the value which va_list is currently referring to and also moves va_list to the next element in ellipsis. It also takes two arguments: va_list itself and the type of the parameter(element) we are trying to access.
 *
    'va_end': takes only one argument: va_list itself. It is used to clean up the va_list macro.
 */
 


void printEllipsis(int count, ...){
    va_list ptr;//'ptr' is object(like 'pointer') can point to a element in an ellipsis.
    
    va_start(ptr, count);//Let 'ptr' point to the first element in ellipsis.
    
    int num = va_arg(ptr,int);
    /* Return the value that 'ptr' currently points to, and let 'ptr' point to the next
     * element. This function can be used to iterate the whole ellipsis.
     */
    std::cout<< num << std::endl;
    
    va_end(ptr); 
    /* 
       Ends the use of va_list, After the call va_end(ptr) the variable 'ptr' is undefined. Each invocation of va_start() must be matched by a corresponding invocation of va_end() in the same function. 
     */
}

int main()
{
    printEllipsis(1,2,3);
    
    
    
    return 0;
}
/* 
    Since 'Ellipsis' tells the compiler to not check the type and number of parameters the function should accept which allows the user to pass the variable argument list, So it is quite dangerous to use them. 
    When using ellipsis, the compiler does not check the type of arguments passed to the function. So the compiler does not throw any error if arguments are of different types.
    Even if pass 'string', 'double', or 'bool' type values are passed to the function it will return unexpected values, and the compiler does not throw any error.
 */