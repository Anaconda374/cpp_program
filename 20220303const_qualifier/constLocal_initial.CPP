#include<iostream>

extern const int a = 46 ;
/* 
   since the const is initialized from the compile_time constant,the compiler has to see the variable's initializer substitute the value at compile time since the const object has the constant value in its initializer, and in order to do this the const variable must be defined as local to each file,this manner can also avoid the problem of "multiple definitions of the same variable."
 */
 
 extern const int b;
 /* 
   when a const object whose initializer is not a constant expression such as run_time initialized ,and we want to share it across multiple files,since in this case we don't need the compile to generate a separate variable in each file,so we only need to define the const in one file ,and declare it in the other files. 
   NOTE:we need use the keyword "extern" to specify on its both definition and declaration(slightly different from non-const variables).
  */
 
int externConst_test()
{
    std::cout << a << "\n"
              << a + b << "\n"
              <<std::endl;
    
    
    return 0;
}