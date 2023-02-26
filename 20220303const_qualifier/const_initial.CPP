#include<iostream>

 //A const object must be initialized in its definition. 
 
int getNumber();

int externConst_test();

const int a = 47.8; 
/*
   Initialized at compile time, and this Variable 'a' without 'extern' is different from the Variable 'a' in File "constLocal_initial".
   NOTE:'47.8' will be truncated into '47' in order to convert it into "int type". 
*/

extern const int b = getNumber();//initialized at run time .


int main()
{
    //A const object must be initialized in its definition. 
    
    std::cout << a <<"\n"
              << b << std::endl;
    externConst_test();
    std::cout <<  a << std::endl;
    return 0;
}


int getNumber()
{
    int x;
    std::cin >> x ;
    return x;
}