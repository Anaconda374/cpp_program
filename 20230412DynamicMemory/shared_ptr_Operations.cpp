#include<iostream>
#include<memory>
#include<new>

/*
Caution: Smart Pointer Pitfalls:
    1. Don't use the same built-in pointer Value to initialize(or reset) more than one independent smart pointer.-- Since a 'shared_ptr' can coordinate the destruction only with other 'shared_ptrs' that are the copies of itself using "reference count". 

    2. Don't 'delete' the pointer returnd from 'get()'. -- It will makes the original shared_ptr(s) invalid. 

    3. Don't use 'get()' to initialize or reset another smart pointer.(same reason with Pitfall 1)

    4. If we are using a pointer returned by 'get()', remember that the pointer will become invalid when the last corresponding smart pointer goes away.

    5. If you use a smart pointer to manage a resource other than memory allocated by 'new', remember to pass a 'deleter'.
*/



void freeMemory(int* pi);

int main(){
//'shared_ptr' initializations:    
    /*
    Initialize a shared_ptr using 'new':
    Since 'new' returns a built_in pointer, and we cannot implicitly convert a built_in pointer to a smart pointer; such that we must use the direct form of initialization.
    */
    // std::shared_ptr<int> p = new int(1024);//ERROR!

    std::shared_ptr<int> sp1(new int(1024)); //OK. 'sp1' manages the object which created by 'new'.

    //Initialize a 'shared_ptr' with a built_in pointer:
    int* ip = new int (2023);
    std::shared_ptr<int> sp2(ip); //'sp2' manages the object to which the built_in pointer 'ip' points; 'ip' must point to dynamic memory allocated by 'new' and convertible to 'int*'
/*
  NOTE: In this way, may cause inadvertently binding the same memory to more than one independently created 'shared_ptr', but a 'shared_ptr' can coordinate the destruction only with other 'shared_ptrs' that are the copies of itself using "reference count". 
  So that we are recommended using 'make_shared' to initialize a 'shared_ptr' rather than 'new' or "a built-in pointer".
    */
    
//Assign a 'unique_ptr' to a 'shared_ptr':
    std::unique_ptr<int> u(new int(10));
    std::cout<<"int u is: "<<*u << std::endl; 
    //shared_ptr'sp3' assumes ownership from the unique_ptr'u' and makes 'u' NUll.
    std::shared_ptr<int> sp3= std::move(u);
    std::cout<<"int u is: "<<*u << std::endl; 


/*
Reset a 'shared_ptr':
    'reset(...)' updates the reference counts and, if appropriate, deletes the object to which the shard_ptr points. 
*/
    std::shared_ptr<int> sp4(new int(42));
    sp4.reset();  // 'sp4' no longer points to the original object, and it is deleted

    std::shared_ptr<int> sp5(new int(123));
    sp5.reset(new int(456));  // 'sp5' now points to a new object, and it takes ownership.

    /*
    'reset(...)' is often used together with 'unique' to control changes to the object shared among several 'shared_ptrs'. Before changing the underlying object, we check whether we're the only user. if not, we make a new copy before making the change, so that the other 'shared_ptrs' won't be effected.
    */
    if(!sp5.unique()){
        sp5.reset(new int(*sp5)); //if 'sp5' is not unique, allocate a new copy and reset to it.
    }
    *sp5 += 5; //change the new allocated object.


/*
The Deleter_function of 'shared_ptr':
    Some dumb classes(such as designed to be used by both C and C++) do not have destructor, and generally require the user to specifically free any resources that are used.
    It is easy to forget to release the resource, and if an exception happens between when the resource is allocated and when it is freed, the program will leak that resource. We can solve this potential problem by passing an optional argument that points to a 'deleter' function when we initialize a 'shared_ptr'.
*/
    int* pi = new int(2023);
    std::shared_ptr<int> sp6(pi, freeMemory);
    //'sp6' assumes the owenership from 'pi', when 'sp6' is destoryed, it won't execute 'delete' on its stored pointer'pi'. Instead, 'sp6' will use the callable object 'freeMemory' on that pointer. Thus, the memory to which 'pi' points will freed.   
 
    return 0;
}


//define a deleter function which frees the dynamic memory used by an int:
void freeMemory(int* pi){
        delete pi;
}