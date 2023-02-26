#include<iostream>
#include<string>

/*
   The constructor has 2 ways to "give the values" to the data members: 
   1. Initialize the members by "constructor initializer list", it follows the colon' : '.
   2. Assign the members with values in the constructor body, inside the curly braces {...}. 
   These 2 methods can result in the same outcome, but they are processed in different phases. All in all, like ordinary 'initialization' and 'assignment', using "constructor initializer list" is more succinct and efficient. 
   
 */
class Test_constructor{
public:
    Test_constructor(int v1, int v2): ref(val), val(v1){};
    /* This constructor use constructor initializer list to initialize the members.   
    
    Members of some particular types must be initiazlized:
        Like ordinary C++ statements, 'const' and 'reference' objects must be initialized in the initialization phase, otherwise the program will report errors. 
        
    Order of member Initialization:
        The constructor initializer list in a constructor only "specifies the values used for initialization", not the initializing order. Member are initialized in "the order in which they appear in the class definition", such that we can write "ref(val), val(v1)" in the list and does not get an error.
        NOTE: Best practice is to write constructor initializer in the same order as the member are declared, and avoid using member to initialize other members.
     */
     
/* 
Delegating constructor:
    A delegating constructor uses another constructor from its own class to perform its initialization, it is said to "delegate" some(or all) of its work to this other constructor.
 */
    Test_constructor(int i): Test_constructor(i, i){};
    // Test_constructor(int i){Test_constructor(i,i);};
    /* This constructor delegates its work to the above one.
    
        A delegating constructor "uses the delegated-to constructor as its constructor initializer list" or "places the delegated-to constructor in its body". It's kind of like a constructor calling another constructor to perform the initialization.  
     */     
    void print(){
        std::cout<< this->val << " "<< this->ref << std::endl;
    }
private:
    int val;
    int& ref;
};

int main()
{
    Test_constructor item1(2,3);
    item1.print();
    
    Test_constructor item2(4);//Using the delegating constructor.
    item2.print();
    
    std::cout << 0
         <<std::endl;
    return 0;
}