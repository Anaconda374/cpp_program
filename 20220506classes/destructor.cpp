#include<iostream>

/*
Destructor is a member function which is invoked automatically whenever an object is going to be destroyed. Meaning, a destructor is the last function that is going to be called before an object is destroyed.
    1. Destructor is also a special member function like constructor. Destructor destroys the class objects created by constructor. 
    2. Destructor has the same name as their class name preceded by a tilde (~) symbol '~ClassName(){}'.
    3. It is not possible to define more than one destructor. The destructor is only one way to destroy the object create by constructor. Hence destructor can-not be overloaded.
    4. Destructor "neither requires any argument nor returns any value".
    5. It is automatically called when object goes out of scope. 
    6. Destructor 'releases' memory space occupied by the objects created by constructor.
    7. In destructor, objects are destroyed in the reverse of an object creation.
    8. Destructor applies to both stack(created in local block) and heap(using 'new') allocated objects.
*
NOTE: if the object is created manually by using Operator 'new' or the constructor uses 'new' to allocate memory which resides in the heap memory or the free store, the destructor also should use Operator 'delete' to free the memory.   
*/

class Test{
public:
    int id;
    //define a constructor:
    Test()
    {
            std::cout<<"\n Constructor executed";
    }   
    //define a destructor:
    ~Test()
        {
            std::cout<<"\n Destructor executed";
        }
};

void func(){
    Test t;
    t.id = 18; 
    std::cout<<"\n local func exits. " <<std::endl;
}

int main(){
    func();
    std::cout<<std::endl;//when object goes out of scope, the destructor is called automatically.
    std::cout<< "\n main function exits." <<std::endl;      
    return 0;
}