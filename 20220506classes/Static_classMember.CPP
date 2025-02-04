#include<iostream>
#include<string>

/*
2 main uses of static members:
    1.As default value of the class.
    2.A 'static' data member can have incomplete type. In particular, a static data member can have the same type as "a class type" of which it is a member of the class.
    
mechanism:    
    A (defined) static member has its own static memory, it is kind of like the global static variable defined in a C++ file which can be used and linked internally, anywhere the 'static' appears or modified is linked to the same memory where that 'static' located in.  
    A static member in class that are associated with the class type, rather than with individual objects specifically. If the static member changes, the new value will be updated across all objects since all object access the static member at the same address.
*/

class Account{
public:
    Account() = default;
    Account(std::string name, double money):ownerName(name),amount(money){}
    
//the 'static' and 'mutable' members can be changed in const member functions:    
    void test_changeStatic(double d) const {
        interestRate = d;
    }
    
/*
Ordinary member function:
    Member functions can use the value of 'static' members directly, without the scope operator, since the functions themselves are already qualified as in the scope of class.
*/
    void calculate(){amount += amount * interestRate;}
    
/* 
'static' member functions:
    Since 'static' members and 'static' functions are not specifically associated with one certain object, such that they are shared by all the objects of the class. 
    A static member function cannot have a 'this' pointer to the object. As a result, 'static' member functions may not be declared as 'const', and we may not refer to 'this' object in the body of a static member function.(even the implicit use of 'this' is not allowed.) 
 */
    static double rate() {return interestRate;}
    static void rate(double);
    void printInfor(){
        std::cout<<"Name: "<<this->ownerName<<"\n"
        <<"Balance: "<<this->amount<<std::endl;
    }


private:
    std::string ownerName = "";
    double amount = 0.0;  
/*
private 'static' members:
    Following static members are just declarations, not definitions, they should be defined outside the class, and the Keyword'static' appears only with the declaration inside the class body(not precede the definition). Since we only want the users of this class to 'read' the 'interestRate' but not to change it, so we defined them in 'private', and the users can check it out by calling the public function 'rate()'. 
*/
    static double interestRate; 
    static double initRate();
    
//In-class intialization(not definition) of static member:
    static constexpr int period = 30;
    double daily_tbl[period];
    /* Ordinarily, the 'static' member may not be intialized in the class body. However we can provide in-class initializers(constant expressions) for static members that are 'constexpr' of literal type.
    So that members are themselves constant expressions, they can be used where a constant expression is required, such as "the dimension of an array member".
    If we use the member in a context in which the value cannot be substituted(like a function require a reference), then there must be a definition for that member. Because the system will not allocate memory to 'constexpr' literals, they are simply substituted by literal values in the compiling time.
    In the respect of "Robustness" of program(cope with various conditions), even if a const static data member is initialized in the class body, that member ordinary should be defined outside the class definition.
    */
};


/*
Define and initialize 'static' data members:
    Because 'static' data members are not part of individual objects of the class, they are not defined when we create objects, thus, they are not initialized by the class' constructors.
    In general, we may not initialize a 'static' member inside the class. Instead, we must define and intialize each static data member outside the class body. 
*/
double Account::interestRate = initRate();
constexpr int Account::period;//definition with no initializer which is provided in the class.
 
//Define 'static' member function outside:
void Account::rate(double newRate){
    interestRate = newRate;
}
double Account::initRate(){return 0.012;} 


int main()
{
    double r1, r2, r3;
//Access the static member(function) through the scope operator:
    r1 = Account::rate();
    std::cout<< r1 <<std::endl;
    
    
//Access the static member(function) through "a object(using dot'.')" or "a pointer to object(using arrow '->')":
    Account ac1;
    Account* pac = &ac1;
    Account::rate(0.02);
    r2 = ac1.rate(); 
    r3 = pac->rate();//equivalent ways to call the static member function' rate()'
    std::cout<<r2<< " " << r3 <<std::endl;
/*
    Although 'static' members are not part of the objects of its class, we can use an 'object', 'reference', or 'pointer' of the class type to access a public static member.
 */ 
    Account ac2("Anacs", 10);
    ac2.calculate();
    ac2.printInfor();
    ac2.test_changeStatic(0.05);
    std::cout<< ac2.rate()<<std::endl;
    
    return 0;
}  



