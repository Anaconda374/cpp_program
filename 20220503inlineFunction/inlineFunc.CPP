#include<iostream>
#include<string>
/* On most machines, a function call does a lot of work(called 'overhead'):
 Registers are saved before the call and restored after the return; arguments may be copied; and the program branches to a new location(switch the control flow). 
 
 For functions that are large and/or perform complex tasks, the overhead of the function call is usually insignificant compared to the amount of time the function takes to run. 
 
 However, for small, commonly-used functions, the time needed to make the function call is often a lot more than the time needed to actually execute the function’s code. This overhead occurs for small functions because execution time of small function is less than the switching time.
 
 "Inline function(defined before the function with Keyword 'inline')" is a 
 function that is expanded "in line" when it is called. When the inline function is called whole code of the inline function gets inserted(or substituted) at the point of inline function call. This substitution is performed by the C++ compiler at compile time. Inline function may increase efficiency if it is small.
 */

inline const std::string&
shorterString(const std::string &s1, const std::string &s2){
    return s1.size() < s2.size()? s1: s2;
}

int main()
{
    std::cout<< shorterString("aaa", "bbbb") << std::endl;
    /* this statement would be expanded during compilation into:
     * " std::cout<< ( s1.size() < s2.size()? s1: s2 ) << std::endl; "
     */
    return 0;
}
/* "Inlining" is only a request to the compiler, not a command. Compiler can ignore the request for inlining. Compiler may not perform inlining in such circumstances like:
 * 1) If a function contains a loop. (for, while, do-while)
 * 2) If a function contains static variables.
 * 3) If a function is recursive.
 * 4) If a function return type is other than void, and the return statement doesn’t exist in function body.
 * 5) If a function contains switch or goto statement.
 */