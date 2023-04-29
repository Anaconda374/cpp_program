#include<iostream>
#include<memory>


int main(){
/*
'shared_ptr' smart pointers are implemented using "reference counting", which is a technique used to manage the lifetime of an object:
    Each 'shared_ptr' keeps track of how many other 'shared_ptr's point to the same object.
    when a 'shared_ptr' is created, a related 'reference_count' structure is created too, which records how many references bound to the same object. We can check the reference count by calling '.use_count()'.
    Once a shared_ptr's counter goes to 0, the shared_ptr automatically frees the object that it manages:
*
    "count increments" -- whenever we copy a shared_ptr to another, For example:
        1. when we use it to initialize another shared_ptr; 
        2. when we use it as the right_hand operand of an assignment;
        3. when we pass it to or return it from a function by value.
*
    "count decrements" :
        1. when we assgin a new value to this 'shared_ptr';
        2. when a shared_ptr which points to the same object is destroyed, such as when a local shared_ptr goes out of scope.
*/
    auto r = std::make_shared<std::string>("ganar");
    std::shared_ptr<std::string> p = std::make_shared<std::string>("nueva");
    
    //assign to 'r', making 'r' point to a different address:
    r = p; //increase the use count for the object to which q points.
    std::cout << " r points to: " << *r <<std::endl;

    //'/.use_count' checks the reference count:
    std::cout<<"The number of objects sharing with 'r': " <<r.use_count() <<std::endl;

/*
'weak_ptr' is a sub_type of shared_ptr, but assgin a 'shared_ptr' to a 'weak_ptr' the reference_count does not increment. Once all shared_ptrs is destroyed, the bounded memory will be freed automatically no matter whether the weak_ptrs is destroyed.
*
    The primary purpose of 'weak_ptr' is to prevent cyclic dependencies between objects managed by std::shared_ptr, which can lead to memory leaks. By using 'weak_ptr', you can break the cycle of references and allow the objects to be deleted when they are no longer needed.
*
    NOTE: You cannot dereference a 'weak_ptr' directly, because it does not guarantee that the managed object still exists. To access the managed object, you need to create a std::shared_ptr from the 'weak_ptr'. This is done using the lock member function, which returns an empty std::shared_ptr if the managed object has been deleted, or a valid std::shared_ptr otherwise. 
*/
    std::weak_ptr<std::string> wPtr = r;
    std::shared_ptr<std::string> sPtr = wPtr.lock();
    std::cout<< "sPtr points to: " << *sPtr <<std::endl;
    


/*
'unique_ptr' uses a different approach to manage the lifetime of an object:
     Unlike 'shared_ptr', 'unique_ptr' cannot be copied, only moved. This means that there is no need to keep track of the number of 'unique_ptr' instances pointing to the same object. Instead, when a 'unique_ptr' is moved, the ownership of the object is transferred to the new 'unique_ptr', and the original 'unique_ptr' is left pointing to a null object.
*/
    std::string str = "cierto";
    std::unique_ptr<std::string> uPtr1 = std::make_unique<std::string>(str);
    std::cout << " uPtr1 points to: " << *uPtr1 <<std::endl;

    //transfer the memory ownership from unique_ptr 'uPtr1' to 'uPtr2':
    std::unique_ptr<std::string> uPtr2 = std::move(uPtr1);
    std::cout << " uPtr2 points to: " << *uPtr2 <<std::endl;
    //After ownership transfering, the original unique_ptr 'uPtr1' points to 'NULL' now :
    std::cout << " uPtr1 points to: " << *uPtr1 <<std::endl;

    return 0;
}