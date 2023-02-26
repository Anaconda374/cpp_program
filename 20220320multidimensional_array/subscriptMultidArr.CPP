#include<iostream>
#include<string>


int main()
{
//Reference to an array:
    char (&ref)[3] = sarr1[0];
    //this statement is equal to "auto &ref = sarr1[0]".
    //'ref' is bound to Array 'sarr1[0]' of 3 int elements.
    
    std::cout << ref[4] <<std::endl;
    
    return 0;
}