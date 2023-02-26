#include<iostream>

/* 
    A void pointer is a pointer that has no associated data type with it.  A void pointer can hold address of any type and can be typecasted to any type. But the behaviors of trying to access or operate the object through a void pointer is undefined.
 */
int main()
{
    int a = 2;
    void *p ;
    p = &a;
    std::cout << *p << std::endl;//ERROR.

    return 0;
    
    
}