#include<iostream>
#include<string>

/* 
   When we using scope operator'::' to define a object such as "std::string s1;" we are defining it as a Type'string' which is a type(or class) defined in the scope of 'std'. 
 */
 
 using namespace std;
/* 
   The statement "using namespace std;" means to include(or input) all members and function defined in the scope of 'std', and we can use these members and functions directly, but it is also at a high risk of getting a name collision. 
 */ 

int main()
{
    
    
    
    cout <<  0 <<"\n"
         <<  0 <<"\n"
         <<endl;
    return 0;
}