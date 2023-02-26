#include<iostream>
/* 
   For compiling 2 C++ files, firstly the C++ Compiler will compile these two files individually and translate into the object files(.obj), and the C++ Linker will link the two object files together in order to generate the executable file(.exe).
   In linking process, the Linker checks the name collisions among objects in both files, so if we need to use the same variable across multi_files, we can use the keyword 'extern' to declare that variable in other different files, but cannot re_assign it.
 */


int declaration_test(int x);

int global_int = 3;

int v1 = 1;
/*
    Even variables 'v1' are defined separately in 2 files, because of the 'v1' in the other file is declared as 'static', so that it's not visiable to other files, and wouldn't cause "the name collision". 
 */

int main()
{
 
    std::cout << declaration_test(2) + v1 << std::endl;
    
    return 0;
}
