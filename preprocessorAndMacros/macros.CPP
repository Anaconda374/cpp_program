/* The C preprocessor is a macro preprocessor(allows you to define macros) that transforms your program before it is compiled. These transformations can be the inclusion of header file, macro expansions etc.
 * All preprocessing directives begin with a '#'symbol.
 */
 
 

#include<iostream>
/* Here, 'iostream.h' is a header file. The '#include' preprocessor directive replaces the above line with the contents of iostream.h header file. That's the reason why you need to use #include <iostream.h> before you can use functions like 'cout' and 'endl'.
 * 
 NOTE: when we "#include" a header file in a program, all source codes in that header file are fully copied into that program, including the macro directives inside the header, and compiler will compile them as normal code, nothing special! 
 */
#include<string>

#define PI 3.14 //not followed by a ';'. 
/* 
   A macro is a fragment of code that is given a name. You can define a macro in C using the #define preprocessor directive.
 */
 #define circleArea(r) 3.14*r*r //This marco directive take a argument.
 /* 
   we can also define macros that work in a similar way like a function call.  This is known as function-like macros. 
  */
int main()
{
    
    std::cout <<  PI <<"\n"
         <<  circleArea(4) <<std::endl;
         
 /* Predefined Macros:The standard predefined macros are specified by the relevant language standards, we can use these marco_methods directly without defining it since they are predefined.And they are available with all compilers that implement those standards. 
  
  * e.g.:
  * __DATE__	A string containing the current date
  * __FILE__	A string containing the file name
  * __LINE__	An integer representing the current line number
  * __STDC__	If follows ANSI standard C, then the value is a nonzero integer.
  * __TIME__	A string containing the current time.
  */
  
    std::cout<<__TIME__<<std::endl;//output the current time.
    return 0;
}