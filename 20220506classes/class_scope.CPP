#include<iostream>
#include<string>

/*
Scope rule of 'classes':
    In class definitions, once the class name is seen, the remainder of the definition--including the parameter list and the function body--is in the scope of the class.

    Every class defines its own new scope using ' {...}; ', outside the class scope, we can use following method to access the class' scope:
    1. Objects use dot operator'.' to access the members or member functions
    2. References or Pointers use member access operator'->' to access the members or member functions.
    3. use scope operator'::' to access the defined type-members in the class(such as 'std::string').
    4. use Scope operator'::' to qualify a member function that defined outside the class, to indicates it belongs to that class. if the member function has a return type which is also defined in the class, we need to qualify this return type use 'className::' too.  
 */
class Test{
public:
    Test() = default;
    typedef std::string::size_type pos;
    // changeChar(pos i, char c);
    Test& changeChar(pos i, char c); 
private:
    std::string str = "defaultValue";
};

Test& Test::changeChar(pos i, char c){
    /*
       Since the function name is qualified by 'Test::', so the Parameter type'pos', Reference'this', and Data-member'str' is already in the scope of Class'Test'.
    */    
    (*this).str[i] = c;
    return *this;
} 


int main()
{
    
    
    
    std::cout <<  0 <<"\n"
         <<  0 <<"\n"
         <<std::endl;
    return 0;
}