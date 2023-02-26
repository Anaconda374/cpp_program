#include<iostream>
#include<string>

int v2;
/* By default initialization, the built-in type "global variable(s)" with no initializer is initialized to '0'.
 */
 
 int demo_static(){
     static int sta1;//Local static variable is initialized to '0' by default. NOTE: "local static variable" is different from the "Local variable".
     /* Although we cannot use this static varibale'sta1' out of this function, but the "Local static object" corresponding to this variable are not destroyed when a function ends, they are destroyed when the entire program terminates.
      */
     return ++sta1;
 }
 
 
int main()
{
    int v1 = 2;
    /* The object that correspond to ordinary local variables are created when the function's control path passes through the variable's definition , and they are destroyed when control passes through the end of the block in which the variable is defined, this duration is called the lifetime of an object.
     */
  
    int v3;// Caution!
    /* The "local varibales(which inside any funtion)" with no initializer are uninitialized, which have undefined values.
     */
    std::cout << v1 + v2<<"\n"    
         << v1+ v3 <<"\n"
         <<std::endl;
         
    std::cout<< demo_static() <<std::endl;
    std::cout<< demo_static() <<std::endl;
    return 0;
}

