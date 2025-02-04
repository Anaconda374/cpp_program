#include<iostream>
#include<string>

/*
Implicit construction:
    Implicit conversion(or construction) in C++ is the process by which the compiler automatically converts a value of one data type to another data type, without the need for explicit type casting or conversion functions. 
*/

class Person{
public:
    std::string name;
    int age;
    /*Define a constructor to demostrate the "implicit construction":
        this constructor takes a parameter of Type'string', such that any objects of Type'string' can be implicitly converted into a 'Person' object. In other words, we can implicitly construct a Person object with a 'string'.    
    */
    Person(std::string s): name(s),age(-1){}

    /*Define a 'explicit' constructor:
        Put Keyword'explicit' in front of a contructor to disable the implicit conversion, means this constructor must be "explicitly called".
        Explicit constructor is used for security of the code by preventing unintentional conversions among objects.
    */
    explicit Person(int i): name("unknown"), age(i){}
};


int main(){
    
    //Person p1 = "kuan"; //ERROR, "kuan" is of Type 'char[]', not 'string'.

    std::string name = "Kuan";
    Person p1 = name;//Implicit construction.

    // Person p2 = 20; //ERROR, implicit construction is not allow for an 'int' object.

    Person p2(20);//Explicit construction.

    std::cout<< "p1 is "<< p1.name << " "<<p1.age <<std::endl;
    std::cout<< "p2 is "<< p2.name << " "<<p2.age <<std::endl;

    return 0;
}




