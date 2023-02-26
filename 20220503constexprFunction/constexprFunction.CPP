#include<iostream>
#include<string>


/* The idea of 'using constexpr Function' is performance improvement of programs by doing computations at compile time rather than run time. 
Note that once a program is compiled and finalized by developer, it is run multiple times by users. The idea is to spend time in compilation and save time at run time (similar to template metaprogramming).  
 * Keyword 'constexpr' specifies that the value of an object or a function can be evaluated at compile time and the expression can be used in other constant expressions. 
 */

 
/* "The return type" and "the type of each parameter" in a constexpr fucntion must be a literal type. 
 */
constexpr int _double(const int n){
    return n*2;
}
constexpr int _double(char c){
    return c*3;
}
int main()
{
    std::cout << _double(2)<< std::endl; 
    //'_double(2)' is evaluated in compile time and returns a constant expression. 
    
//A constexpr_function is "not required" to return a constant expression:
    int v ;
    std::cin >> v;
    std::cout<< _double(v) <<std::endl;
    /* 'v' is not a constant expression, so '_double(v)' is not evaluated at compile time, and nor return a constant expression.
     */
    
    return 0;
}