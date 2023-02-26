#include<iostream>

int main ()
{
    int i = 42,*p1 = &i , &r = i;
    /* ' * ' or ' & ' is called "modifiers" ,each them only modifies the object follows it ,it does 
     * nothing to any other object that might be declared in the same statement.
     */
     
    *p1 = *p1 * r;
    std::cout << *p1 << std::endl;
    //double *p2 = &i; //<- this is invalid ,cannot assign the int value to a double type pointer.
    
    int z = 0;
    /* int *p3 = z; // <- Although z =0 , but we cannot assgin 'z' to a pointer directly,
     * a pointer can only be initialized to 0 in its definition.
     */
    return 0;
}