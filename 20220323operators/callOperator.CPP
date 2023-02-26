#include<iostream>
#include<string>

/* 
   Call operator '()' for calling a function, the name of a function(or a function pointer) precedes the parentheses. which enclose a (possibly empty) comma_seperated list of arguments.
 */
void test_func(){
    std::cout << "test" << std::endl;
}

int main()
{
/* No matter when or where the call operator'()' is used, it is basically calling a function
 * either one we defined or one defined in libraries.
 */
    test_func();
    std::string s1= "anacs";
    std::cout<< s1.size() <<std::endl;
    //'size()' is a member function defined in Class'string' of Library<string>.  
    
    
    return 0;
}