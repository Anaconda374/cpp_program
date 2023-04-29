#include<iostream>
#include<vector>
#include<new>

/*
Objects allocated in 'static memory' or 'stack memory' are automatically created and destoryed by the compiler, and the lifetime of objects in 'dynamic memory' are controled by the program.
    1. 'stack objects' exist only while the block in which they are defined is executing.
    2. 'static object' are allocated before they are used, and they are destroyed when the program ends.
    3. 'dynamic object' are allocated at run time, and destroyed explicityly by our code when they are no longer needed.
*
Manually freeing dynamic objects turns out to be a surprisingly rich source of bugs. There are 3 common problems with using 'new' and 'delete to manage' dynamic memory:
    1. Forgetting to 'delete' memory: causes "Memory Leak", As a result, the memory is unavailable for other programs or processes to use, leading to a degradation in system performance.
    2. Using an object it has been deleted.
    3. Deleting the same memory twice. After we deleting and reset a pointer, other pointers(which sharing the same memory with it before) still point to the already freed memory, if we try 'delete' such these pointers, the free store may be corrupted.
*
  To make using dynamic objects safer, the library defined 2 smart pointer types(shared and unique) that manage dynamically allocated objects. Smart pointers ensure that the objects to which they point are automatically freed when it is appropriate to do so.
*/

int main(){
/*
In C++, dynamic memory is managed through a pair of operators:
    1. 'new' : which allocates, and optionally initializes an object in dynamic memory, either default_initialized(built-in types may have undefined value) or value_initialized, and returns a pointer to that object.
    2. 'delete' : which takes a pointer to a dynamic object, destorys that object, and frees the associated memory.
*/

//'new' operator-- allocate a block of memory and returns a built-in pointer.
    int* pt = new int(10); //create a int object with value of '10', and returns a pointer to 'pt'.
    std::cout<< *pt <<std::endl;

    //Use 'auto' to deduce the type of the object we want to allocate from the initializer(in parentheses).
    std::vector<int> iVec(10, 6);
    auto pt1 = new auto(iVec); //'pt1' points to an object of type of 'iVec' and that object constructed by 'new' is initialized from 'iVec'.
    std::cout<< (*pt1)[1] <<std::endl; 
    
    //'const' dynamic object:
    const int* pci = new const int(1024);/*allocate and initialize a const int. 
    Like any other 'const', a dynamically allocated 'const' object must be initialized. 
    Because the allocated object is 'const', the pointer returned by 'new' is a pointer to 'const'.
    */

    /*
    Memory Exhaustion: 
        Although modern machines tend to have huge memory capacity, it is always posible that the free store will be exhausted. By default, if 'new' is unable to allocate the requested storage, it throws an exception of type 'bad_alloc'.
    */
    int* p1 = new int; // if allocation fails, 'new' throws 'std::bad_alloc'.
    int* p2 = new(std::nothrow) int;//use 'std::nothrow' to tell 'new' that it must not throw an exception. If allocation fails, 'new' returns a null pointer.

/*'delete' operator:
    The delete operator performs 2 actions, it destroys the object to which its given pointer points, and has 'void' return type does not return a value.
*/
    delete pt; //'pt' must point to a dynamically allocated object or 'NULL'

    std::cout<< *pt <<std::endl;//Caution! Undefined behavior, Pointer to object'pt' is not destroyed, value or memory block pointed by pointer is destroyed.

    /*
    Destroy a 'const' dynamic object:
        although the value of a 'const' object cannot be modified, the object itself can be destroyed. As with any other dynamic object, a 'const' dynamic object is freed using 'delete'.
    */
    const int* pci2 = new const int(1024);
    delete pci2;

    //NOTE: A dynamic object managed through a built-in pointer(rather than smart pointers) exists until it is "explicitly deleted".
    return 0;

}