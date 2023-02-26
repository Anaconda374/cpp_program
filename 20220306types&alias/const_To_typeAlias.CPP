#include<iostream>
/* Theorem: A type alias is a type name and can appear wherever a type name can appear. Under this theorem, there are still some rules we need to know, such as const to aliases.
 */

int main()
{
    // NOTE:the qualifier 'const' only modifies the single specifier/keyword right after it.
    typedef int integer;
    const integer v1 = 17; // 'v1' is a constant int type ,equal to ' const int v1 = 17'; 
    
    typedef int *pint;  
    
    //const pint p1 = &v1;//ERROR,this declaration is equal to 'int *const p1 = &v1'
    
    /* 
    'pint' is a alias to 'int*' ,qualifier 'const' modifies 'pint',means the defined pointer 'p1' after 'pint' is a const object which points to plain int type. we can't interpret it as 'const int * p1 = &v1',because in this case, 'const int'
     becomes the base type.
     */
     
     integer v2 = 28;
     const pint p2 = &v2 ;//OK.
    
    std::cout <<  v1 <<"\n"
              <<  *p2 <<"\n"
              <<std::endl;
    return 0;
}