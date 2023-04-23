#include<iostream>

/*
Objects allocated in 'static memory' or 'stack memory' are automatically created and destoryed by the compiler, and the lifetime of objects in 'dynamic memory' are controled by the program.
    1. 'stack objects' exist only while the block in which they are defined is executing.
    2. 'static object' are allocated before they are used, and they are destroyed when the program ends.
    3. 'dynamic object' are allocated at run time, and destroyed explicityly by our code when they are no longer needed.
*
    Manually freeing dynamic objects turns out to be a surprisingly rich source of bugs. 
    To make using dynamic objects safer, the library defined 2 smart pointer types that manage dynamically allocated objects. Smart pointers ensure that the objects to which they point are automatically freed when it is appropriate to do so.
*/

int main(){
/*
In C++, dynamic memory is managed through a pair of operators:
    1. 'new' : which allocates, and optionally initializes, an object in dynamic memory and returns a pointer to that object.
    2. 'delete' : which takes a pointer to a dynamic object, destorys that object, and frees the associated memory.
*/
    int* pt = new int(10); //create a int object with value of '10', and returns a pointer to 'pt'.
    std::cout<< *pt <<std::endl;
    
    delete pt; //The delete operator has void return type does not return a value.

    std::cout<< *pt <<std::endl;//Caution! Undefined behavior, Pointer to object'pt' is not destroyed, value or memory block pointed by pointer is destroyed.

    return 0;

}