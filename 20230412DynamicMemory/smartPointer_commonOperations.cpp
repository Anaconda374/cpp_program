#include<iostream>
#include<vector>
#include<memory> //smart pointer types are defined in header<memory> under Namespace'std'.

/*
  To make using dynamic memory easier and safer, the standard C++ 11 provides 3 smart pointer types that manage dynamic objects:
    1. 'shared_ptr': allows multiple pointers to refer to the same object.
    2. 'unique_ptr': a pointer which "owns" the object to which it points.
    3. 'weak_ptr': a weak reference to "an object managed by a shared_ptr". 
*
    A smart pointer acts like a regular pointer with the important exception that is automatically deletes the object to which it points. 
*/ 
int main(){
    std::shared_ptr<std::vector<int>> vecPtr;
    //A default initialized smart pointer'vecPtr' holds a null pointer that can point at a vector of ints.
    
    vecPtr = std::make_shared<std::vector<int>>(10, 6);
    //'vecPtr' points to a vector of 10 integers with value of '6'.

//Common Operations: all types of smart pointers have some common operations similarly like the normal pointers have:
    //1. dereference using '*' operator:
    std::vector<int> receive = *vecPtr; // '*vecPtr' is a vector.
    
    //2. call the type's members(or functions) using '->' operator:
    std::cout<< vecPtr->size() <<std::endl; //equivalent to '(*vecPtr).size()'.

    //3.  Swap the smart pointers in p and q using 'swap(p, q)' or 'p.swap(q)'. NOTE: 'p' and 'q' should be pointers that pointer to the same type.
    std::shared_ptr<std::vector<int>> vecPtr2 = std::make_shared<std::vector<int>>(5, 8);
    swap(vecPtr, vecPtr2);
    std::cout<< (*vecPtr2)[0] <<std::endl;

    //4. convert a smart pointer to a regular pointer using 'p.get()':
    std::vector<int>* regPtr = vecPtr.get(); 
    //Caution! "the object which the regular point points" will disappear when the smart pointer deletes it. 
    std::cout<< (*regPtr)[4] <<std::endl;
    
    return 0;
}