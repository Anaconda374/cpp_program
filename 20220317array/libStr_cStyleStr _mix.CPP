#include<iostream>
#include<string>


int main()
{
// "C_style string" initializes "Libaray string object":
    char ca[] = "zen47";
// We can use a null_terminated character array to initialize or assign a string.
    std::string s = ca;
    std::cout <<  s << std::endl;
    
    
// Addition of "c_style string" and "Libaray string":
    std::string s1 = "A ";
// We can add a null_terminated character array as one operand(but not both operands) to a string. 
    std::string s2 = s1 + ca;
    std::cout <<  s2 <<"\n"
              <<std::endl;
              
// make a char pointer to a libaray string:
    
    std::string s3 = "anacs347";
    const char *ps = s3.c_str();
    /* 
    's3.c_str()' returns a pointer to the beginning of a null_terminated character array that holds the same data as the characters in the String's3'.
    'c_str' indicate that the function converts the "lib_string" into a "C_style string".
     */
    std::cout << ps[1] << std::endl;
/* NOTE: 
    the type of the pointer is "const char*" for preventing us from changing the contents of the array. If a program needs to change the contents of the array, we can copy the array into a vector object.
 */ 

    return 0;
}