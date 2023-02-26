#include<iostream>
#include<string>

/* 
    If a function defined in C++ program, after compiling this program and running it, the C++ compiler will tell the system to allocate a block of memory to for the operations of that function.
 * 
    When we initialize a pointer from a function, we are actullay specifing a certain type of memory(by "size", "element types",etc.) and assgining "the start address of the memory which storing the function" to this pointer.   
 */

int sum_test(int v1, int v2){
    return v1 + v2;
}




int main()
{
    // 'Pointer_to_function' defining:
    int (*pf) (int v1, int v2);
   /* 
       using this kind of declaration, we can specify that 'pf' points to a function that has two 'int' parameters and return a 'int' type. Like pointer to an array, the parentheses'()' around *pf are necessary.
    */
    pf = sum_test;//equivlent to "pf = &sum_test"
    /* 'pf' now points to the function named 'sum_test'.
     */
    int sum = pf(5,6);
    /* We can use this pointer to call the function directly without dereference, this is equivalent to "(*pf)(5,6);" and "sum_test(5,6);"
     */
    int sum2 = (*pf)(5,6);
    std::cout<< sum <<"\n"<< sum2 << std::endl;
    
    
/* 
   No conversion between "pointers to one function type" and "pointers to another function type". But we assgin a pointer_to_function with 'nullptr' or '0' to indicate that the pointer does not point to any function.
 */
    pf = nullptr;
    // int sum2 = pf(4,5);
    //ERROR, since 'pf' is no longer pointing to a function, this behavior is undefined.  
    
    
    return 0;
}