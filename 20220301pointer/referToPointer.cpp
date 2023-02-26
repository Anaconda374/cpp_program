#include<iostream>

int main()
{
    int val = 3 , *p = &val , *&r = p;
    /* 
    use ' *&r 'multiple modifiers to define a reference to a pointer ,to understand it need us to read it from right to left '&' means 'r' is a reference ,and '*' complement 'r' is a reference bound to a pointer object.
     */
    
    std::cout << *r << std::endl;
    
    
    
    
    return 0;
}