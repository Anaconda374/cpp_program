#include<iostream>
#include<string>


int main()
{
    int x = 100;
    int &r1 = x; //OK, we can make a reference to a lvalue;
    
    // int &r2 = 100; //ERROR, we cannot bind a reference to a rvalue.
    
// Exception: create a "const reference to rvalue"
    const int &cr = 47;//OK.
    /* This statment is actully equal to :
     *   int __internal_unique_name = 47;  //
     *   const int& ref = __internal_unique_name;
     * 
       Under the hood, the compiler creates an hidden(unnamed) variable for you(i.e. an lvalue) where to store the original literal constant, and then binds that hidden variable to your reference. 
     */
    
    std::cout <<  cr <<"\n"
         <<  0 <<"\n"
         <<std::endl;
    return 0;
}