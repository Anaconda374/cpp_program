#include<iostream>
#include<string>

/*
    Every class defines a unique type, Two different classes define two different types even if they define exactly the same members.
    Following demo Classes 'one' and 'two' are different types.
 */
class one{
public:
    int a = 0;
};
class two{
public:
    int a = 0;
};


class Screen;
/* 
Incomplete class(class is declared but not defined): 
    When a class is declared before its definition, this kind of declaration is called "forward declaration" which usually used to introduce the name of the class into the program. For example, the above declaration indicates that the name 'Screen' refers to a class type. 
    "The duration" after a declaration and before a definition is seen, the Class'Screen' is an "incomplete type"-- it's known that 'Screen' is a class type but not known what members that it contains. In this section, there are something we can do and something we cannot do to the class:
        Can do:
        1. define pointers or reference to this class type.
        2. declare(not define) functions that use this class type as 'parameter' or 'return'.
        
        Cannot do:
        1. create objects of this incomplete class type.
        2. define pointers or reference to the member of this class.
        3. define another class which has a member of this incomplete class type.
        
 */
Screen * ps;//OK.

 
 
 class Screen{
public:
    typedef std::string::size_type pos;
private:
    pos cursor = 0;
    pos height = 0, width = 0;
    std::string contents;
    mutable size_t access_counter;
    void do_display(std::ostream &os) const {
        os << contents;
    }
};


 
int main()
{
    one obj1;
    two obj2;
    obj1.a = 5;
    // obj2 = obj1; //ERROR, 'obj1' and 'obj2' are different class types.
    std::cout <<  obj2.a <<"\n"
         <<  0 <<"\n"
         <<std::endl;
    return 0;
}