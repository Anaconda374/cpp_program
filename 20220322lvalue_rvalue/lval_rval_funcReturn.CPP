#include<iostream>
#include<string>


int global = 100; 

int ret_rval(){//the return type is 'int', this function returns a rvalue(temporary).
    return 666; 
}

int& ret_lval(){ //the return type is 'int&', In other words, this function returns a lvalue(object).
    return global;
}

int main()
{
    // int *p1 = &ret_rval(); //ERROR
    int *p2 = &ret_lval();//we can only take the address of a lvalue.
    // equivalent to " int* p2; p2 = &ret_lval(); "
    
    std::cout <<  *p2 <<"\n"
         <<std::endl;
    return 0;
}