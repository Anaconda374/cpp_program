#include<iostream>
#include<vector>
#include<memory> // Class'allocator' is defined in Header<memory> under Namespace'std'.

/*
An aspect of 'new' that limits its flexibility is that it combines "allocating memory" with "constructing object(s)" in that memory. Similarly, 'delete' combines "destruction" with "deallocation".
Coupling allocation and construction can be wasteful:
    Sometimes we want allocate a block of memory for 'n' strings, but we might not need 'n' strings immediately, a smaller numbers of string objects might suffice. Such that we need to decouple construction from allocation, which means that we can allocate memory in large chunks independently, and pay the overhead of constructing the objects only when we actually need to create them.
*
    The Library Class 'allocator' is a template or a manager, it lets us seperate allocation from construction,and provides type_aware allocation of raw,unconstructed, memory. and also can used to construct object of specified type.
*/
int main(){

    std::allocator<std::string> alloc; //'alloc' is an object that can allocate dynamic memory for 'strings', and construct 'string' objects for a given pointer.

//'.allocate' used to allocate a dynamic memory:
    std::string* p = alloc.allocate(5); // allocate 5 unconstructed string memory and return a normal pointer.
    

//'.constuct()' used to construct specified number of object for a given pointer:
    std::vector<std::string> strVec = {"suelo", "luz", "hoja"};
    //construct 3 strings in the dynamic memory: 
    for(std::size_t i = 0; i < 3 ; ++i, p++){
        alloc.construct(p, strVec[i]); 
        std::cout<<"NO. "<< i+1 << " element in dynamic memory is: "<< *p <<std::endl;
    }
   
    
//'.destroy()' runs the destructor on the pointed_to object which used to destroy an object(but not deallocate the memory):
    //after 'for' loop "above", 'p' is pointing to the one past the last constructed element. 
    for(std::size_t j = 3; j > 0; --j){
        alloc.destroy(--p);
        // std::cout<<*p <<std::endl; //Disaster: dereference a pointer which points to unconstructed memory.
    } 
    
/*
'.deallocate' to free the memory:
    Once the elements have been destroyed, we can either reuse the memory to hold other objects or return the memory to the system by using '.deallocate(p, sz)'.
        'p'(pointer_argu): must be a NOT_NULL pointer which points to memory allocated by 'allocate'.
        'sz'(size_argu): must be the same size as used in the call to 'allocate'.
*/
    alloc.deallocate(p, 5);


/*
'copy' and 'fill' algorithms for uninitialized memory:
    As a companion to the Class'allocator', the library also defines 2 algorithms(including 4 functions) that can construct objects in uninitialized memory.
*/
    std::vector<std::string> copyVec = {"cortina", "coche", "motocicleta"};
    std::string* p2 = alloc.allocate(3);


    //'uninitialized_copy(b1, e1 , b2)'copies elements from the input range denoted by Iterators 'b1' and 'e1' into unconstructed, raw memory denoted by the Iterator 'b2', and it returns a pointer positioned one element past the last contructed element:
    uninitialized_copy(copyVec.begin(), copyVec.end(), p2);
    std::cout<<"Now, the first object pointed by 'p2' is: " << *p2 <<std::endl;

    //'uninitialized_copy_n(b1, n, b2)' copies 'n' elements starting from the one denoted by the Iterator 'b1' into raw memory starting at 'b2':
    std::string* p3 = alloc.allocate(5);
    uninitialized_copy_n(copyVec.begin(), 3, p3);
    std::cout<<"Now, the 3rd object pointed by 'p3' is: " << *(p3+2) <<std::endl;

    //'uninitialized_fill(b, e, t)' constructs objects in the range of raw memory denoted by Iterators 'b' and 'e' as copies of 't'.
    std::string* p4 = alloc.allocate(5);
    uninitialized_fill(p4, p4+5, "llenado");
    std::cout<<"Now, the 5th object pointed by 'p4' is: " << *(p4+4) <<std::endl;

    //'uninitialized_fill_n(b, n, t)' constructs 'n' objects starting at 'b', 'b' must denote unconstructed, raw memory large enough to hold the given number of objects:
    std::string* p5 = alloc.allocate(10);
    uninitialized_fill_n(p5, 5, "medio_llenado");
    std::cout<<"Now, the 5rd object pointed by 'p5' is: " << *(p5+4) <<std::endl;

    return 0;
}