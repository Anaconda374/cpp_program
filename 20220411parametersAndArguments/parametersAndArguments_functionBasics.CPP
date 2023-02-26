#include<iostream>
#include<string>
#include"D:\cpp_program\cpp_headers\Test_subtractTwoNum.h"

/* Parameter initialization works the same way as variable initialization.
 * 
   1. When the argument value is copied, the parameter and argument are independent objects, we say such arguments are "passed by value" or alternatively that the function is "called by value".
 * 
   2. When a parameter is a reference, we say that its corresponding argument is "passed by reference" or that the function is "called by reference", that is, the parameter is an alias for its corresponding argument.
 * 
   Copying of large class types is inefficient, moreover, some class types cannot be copied(such as IO types). SO using "reference parameters" is recommended, and if we do not need to change the value of objects, it is better to make the parameters references to 'const'. 
 */

int demo_add(int x, int y){
    return x + y;
    /* "The return statement" does two things:
     * 1.It returns a value that is used to initialize the result of the calling expression.
     * 2.It transfers control out of "the called function" back to "the calling function".      
     */
}

void passByReference(std::string &x, std::string &y){
    x = "1stChanged";
    y = "2ndChanged";
    /* with a reference as parameter, we can change the value of the argument object directly in the function.
     */    
}

void passByPointer(std::string* ps1, std::string* ps2){
    *ps1 = "1stChangedByPointer";
    *ps2 = "2ndChangedBypointer";
}



int main()
{
    int v1 = 2 , v2 = 8;
    int sum = demo_add(v1, v2);
    /* "A function call" does two things: 
     * 1.It initializes the function's parameters from the corresponding arguments; 
     * 2.It transfers control to that function.
     * "Excution of the calling function" is suspended and "execution of the called function" begins.
     */
    std::cout <<  sum <<std::endl;
    
    
    std::cout << demo_add(3.14, 2.71) << std::endl;
    /* OK, the function call is still legal, if the type of argument(s) can be converted implicitly to the type of parameter(s) by compiler.
     */
    int dif = demo_subtract(v1,v2);
    std::cout<< dif <<std::endl;
    /* Like variables, the function declared in a header file is no need to declare it in the source file again as long as the source file includes the header.
     */    
    
    std::string s1 = "AAA", s2 = "Anacs";
    passByReference(s1, s2);
    std::cout<< s1 << "\n" << s2 << std::endl;

    std::string* sp1, *sp2;
    sp1 = &s1;
    sp2 = &s2;
    /* Unlike "passed by reference", if the parameters of a function are type pointer, the arguments must be pointer type, and the function can also change the value that the arguments point to.      
     */  
    passByPointer(sp1, sp2);
    //equivalent to "passByPointer(&s1, &s2)",the addresses are converted into pointers. 
    
       
    std::cout<< s1 <<"\n" << s2 << std::endl;
    
    return 0;
}