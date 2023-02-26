#include<iostream>

extern int global_int; 
/* 
   'extern' keyword allows us to use the same global objects across the multiple files while compile them together. "Multiple definitions and re-assignment" of 'extern' variables will cause 'linking errors'.
   
   Except 'static' or 'local' objects, any other global objects can be specified as 'extern'.
 */
 
// int global_int = 5; //ERROR,re-definition of 'global_int'.

 
static int v1 = 5; 
/*
 A static variable or function defined outside the class or struct is only visible(be used and called) for the code which is in the same file with it, which means when we compiled mutiple files, the 'static' variables will not be linked with any code(such as 'assignments', 'functions'etc) in other files. It is like the opposite to the 'global' objects which can be linked and adopted(using 'extern') with other files by the 'Linker'. 
 */


int declaration_test(int x)
{
    
    return global_int + x + v1;
}