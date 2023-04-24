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

//Definitions and initializtions of smart pointers:

    //default initialized smart pointers hold a null pointer that can point at a vector of ints:
    std::shared_ptr<std::vector<int>> sVecPtr;
    std::unique_ptr<std::vector<int>> uVecPtr;

    //assign a pointer to the smart pointer, make it points to a vector of 10 integers with value of '6':
    sVecPtr = std::make_shared<std::vector<int>>(10, 6);
    uVecPtr = std::make_unique<std::vector<int>>(10, 6);


    //Initialize smart pointers using constructor explicitly:
    std::shared_ptr<int> iPtr1(new int(4));
    std::unique_ptr<int> iPtr2(new int(7));

    std::cout<< "iPtr1: "<< *iPtr1<< "\n" << "iPtr2: "<<*iPtr2<<std::endl;

//Common Operations: all types of smart pointers have some common operations similarly like the normal pointers have:
    //1. dereference using '*' operator:
    std::vector<int> receive = *sVecPtr; // '*vecPtr' is a vector.
    
    //2. call the type's members(or functions) using '->' operator:
    std::cout<< sVecPtr->size() <<std::endl; //equivalent to '(*vecPtr).size()'.

    //3.  Swap the smart pointers in p and q using 'swap(p, q)' or 'p.swap(q)'. NOTE: 'p' and 'q' should be pointers that pointer to the same type.
    std::shared_ptr<std::vector<int>> vecPtr2 = std::make_shared<std::vector<int>>(5, 8);
    swap(sVecPtr, vecPtr2);
    std::cout<< (*vecPtr2)[0] <<std::endl;

    //4. convert a smart pointer to a regular pointer using 'p.get()':
    std::vector<int>* regPtr = sVecPtr.get(); 
    //Caution! "the object which the regular point points" will disappear when the smart pointer deletes it. 
    std::cout<< (*regPtr)[4] <<std::endl;
    
    return 0;
}