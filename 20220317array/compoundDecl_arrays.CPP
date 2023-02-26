#include<iostream>
#include<string>
/* To understand complicated array declaration needs remembering following axioms:
 * 
   1.By default ,type modifiers bind right to left, so the declaration should be read from right to left.
 *
   2.'Dimension[n]' is a also part of declaration, so it should be included when we read a declaration of an array.
 * 
   3."The modifiers in parentheses(*varName)" have the highest combining priority.
 */

int main()
{
    int* ptrs[10];//an array with 10 elements,and all them are ' int* ' type.
    
    // int &ref[3] = [1,2,3];//ERROR, no arrays of references.
    
    int (*parray)[10];
    /* 
    Let us read ' (*parray) ' at first since it has highest priority, this means 'parray' is a pointer; then '(*parray)[10]' means 'parray' points to an array of 10 elements ; 
    lastly, ' int (*parray)[10] 'means 'parray' points to an array of 10 int type element.  
     */
    
    int (&refarray)[10];
    //The same reading procedure as right above one, 'refarray' refers to an array of ten ints. 
    
    
    std::cout <<  0 <<"\n"
         <<  0 <<"\n"
         <<std::endl;
    return 0;
}