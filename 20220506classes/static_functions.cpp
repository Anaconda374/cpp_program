#include<iostream>

/*
There are 2 different situations of defining a function as 'static':
    1. Member function defined as 'static' in a class: 
        In C++, a static member function of a class that is associated with the class rather than with an instance of the class. This means that a static function can be called without an object of the class being instantiated. 
    2. Normal function defined as 'static':
        When a normal function is declared as static, it means that the function has internal linkage. This means that the function can only be accessed from the same translation unit (source file) in which it is defined, and its name will not be visible outside of that translation unit. 
        This is in contrast to normal non-static functions, which have external linkage by default and can be accessed from other translation units.
*/


//Define a class which has static member function:
class TestClass{
public:
    int val;
    static int internalVal;
    //define a static member function which can be called without any instance:
    static void outPut();
};

void TestClass::outPut(){
        //val = i; //ERROR,  static functions cannot access non-static data members of the class, because they do not have a this pointer. They can only access static data members or other static functions.
       // internalVal = i; //OK. 
        std::cout<<"static member internalVal now  is: "<<std::endl;
    } 

//Define a static normal function which can only be visible within this source file:
static void staticFuncTest(){
    std::cout<< "Use a static function." <<std::endl;
} 

int main(){
    staticFuncTest();
    // TestClass a;
    TestClass::outPut();

    return 0;
}



