#include<iostream>
#include<memory>

//declaration of 'deleter' function:
void freeMemory(int* pi); 

int main(){

//define 'unique_ptrs':
    std::unique_ptr<int> p1;
    std::unique_ptr<int> p2(new int(2023));
    // std::unique_ptr<int> p3(p2);//ERROR, no copy operation for 'unique_ptr'.
    // p1 = p2; //ERROR, no assign opeation for 'unique_ptr'.
    
/*
Transfer owenrship between 'unique_ptrs':
    Although we cannot copy or assign a 'unique_ptr', we can transfer ownership from one(non_const) 'unique_ptr' to another by calling '.release()' or '.reset(...)':
*/
    std::unique_ptr<int> p3(p2.release());
    std::cout<< "Now, p3 points to: "<< *p3 <<std::endl;
    // std::cout<< "Now, p2 points to: "<< *p2 <<std::endl;//caution, undefined behavior.
    /*
    'u.release()' relinquishes the control of Unique_ptr'u' had held; returns the bulit_in pointer(points to a dynamic memory) that 'u' had held and makes 'u' NULL.
    * 
    After calling 'release()', the unique_ptr'u' no longer owns the object, and the caller becomes responsible for managing the memory of the object. Additionally, calling 'release()' does not automatically deallocate the memory used by the object. The responsibility of deallocating the memory is now on the caller.
    */

    //delete the object to which 'p1' points, and transfer the ownership from 'p3' to 'p1'.
    p1.reset(p3.release());
    std::cout<< "After p3-> p1 transference, p1 points to: "<< *p1 <<std::endl;


/*
Deleter to 'unique_ptr':
    By default, 'unique_ptr' uses 'delete' to free the object to which a 'unique_ptr' points. But as with 'shared_ptr', we can also override the default 'deleter' in a unique_ptr.
*
    Different from passing a deleter to a 'shared_ptr', overriding the 'deleter' in a 'unique_ptr' affects the 'unique_ptr'typs as well as how we create(or reset) the 'unique_ptr' of that type.
*/
    int* pi = new int(2023);
    //when we pass a deleter to the initializer, we have to specify "the type of the deleter" by supplying a pointer to that function type inside the angle brackests along with the type to which the 'unique_ptr' can point.
    std::unique_ptr<int, decltype(freeMemory)*> p4(pi, freeMemory);
    //similar to the deleter of 'shared_ptr', when Unique_ptr'p4' goes out of scope, even if by an exception, deleter 'freeMemory' will be called.
    return 0;
}

//Exception: The only exception that we can copy or assgin a 'unique_ptr' that is about to be destroyed is when we return a 'unique_ptr' from a function.

//define a function returns a 'unique_ptr':
std::unique_ptr<int> clone(int p){
    return std::unique_ptr<int>(new int(p));
}

//define a deleter function which frees the dynamic memory used by an int:
void freeMemory(int* pi){
        delete pi;
}