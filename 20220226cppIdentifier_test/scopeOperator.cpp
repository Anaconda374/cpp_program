#include<iostream>

int reuse = 8;

int main()
{
    int reuse = 5 ;
    
    std::cout << reuse << std::endl;
    
    std::cout << :: reuse << std::endl;
    /* use " the scope operator :: " can fetch the variable from the global scope,
     * but defining a local variable with the same name as a global variable is a bad idea.
     */
    
    int sum = 0; 
    for (reuse = 0; reuse != 10; ++reuse) // "the variable defined in for loop" can also cover the block scope. 
        sum += reuse;
    std::cout<< reuse << " "<< sum <<std :: endl;
    
    return 0;
}