#include<iostream>
#include<memory>

int main(){
    
/*
Initialize a shared_ptr using 'new':
    Since 'new' returns a built_in pointer, and we cannot implicitly convert a built_in pointer to a smart pointer; such that we must use the direct form of initialization.
*/
    // std::shared_ptr<int> p = new int(1024);//ERROR!

    std::shared_ptr<int> p1(new int(1024)); //OK. 'p1' manages the object which created by 'new'.


//Initialize a 'shared_ptr' with a built_in pointer:
    int* ip = new int (2023);
    std::shared_ptr<int> p2(ip); //'p2' manages the object to which the built_in pointer 'ip' points; 'ip' must point to dynamic memory allocated by 'new' and convertible to 'int*'
/*
  NOTE: In this way, may cause inadvertently binding the same memory to more than one independently created 'shared_ptr', but a 'shared_ptr' can coordinate the destruction only with other 'shared_ptrs' that are the copies of itself using "reference count". 
  So that we are recommended using 'make_shared' to initialize a 'shared_ptr' rather than 'new' or "a built-in pointer".
    */
    
//Assign a 'unique_ptr' to a 'shared_ptr':
    std::unique_ptr<int> u(new int(10));
    std::cout<<"int u is: "<<*u << std::endl; 
    //shared_ptr'p3' assumes ownership from the unique_ptr'u' and makes 'u' NUll.
    std::shared_ptr<int> p3= std::move(u);
    std::cout<<"int u is: "<<*u << std::endl; 


/*
Reset a 'shared_ptr':
    'reset(...)' updates the reference counts and, if appropriate, deletes the object to which the shard_ptr points. 
*/
    std::shared_ptr<int> p4(new int(42));
    p4.reset();  // 'ptr1' no longer points to the original object, and it is deleted

    std::shared_ptr<int> p5(new int(123));
    p5.reset(new int(456));  // 'ptr2' now points to a new object, and it takes ownership.

    /*
    'reset(...)' is often used together with 'unique' to control changes to the object shared among several 'shared_ptrs'. Before changing the underlying object, we check whether we're the only user. if not, we make a new copy before making the change, so that the other 'shared_ptrs' won't be effected.
    */
    if(!p5.unique()){
        p5.reset(new int(*p5)); //if p4 is not unique, allocate a new copy and reset to it.
    }
    *p5 += 5; //change the new allocated object.

    return 0;
}