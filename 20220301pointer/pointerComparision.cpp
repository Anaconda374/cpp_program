#include<iostream>

int main()
{
    int a = 8;
    int *p1 , *p2;
    p1 = &a;
    p2 = &a;
    if (p1 == p2)
        std::cout << "true"<< std::endl;
    else 
        std::cout << "false"<< std::endl;
    /*pointers can be compared and result in bool type,
     * when the pointers that point to the same address ,it's equal.
     */
    if(p1)
        std::cout << "true"<< std::endl;
    else
        std::cout << "false"<< std::endl;
    /* A single pointer can also be used as a argument in a condition,
     * if the pointer is initialized to 0, then the condition result in 'false'.
     */
   
    return 0;
}