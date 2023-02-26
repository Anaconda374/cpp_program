#include<iostream>
#include<string>

using namespace std;
/*
 C++ 11 standard defines several functions that convert between 'numeric data(int, double, ...)' and 'libaray strings(std::string)'.
 */

int main()
{
    string str1 =  to_string(71);//convert int 71 into string '71'.
    string str2 = "flor";
    // int val = stoi(str2);//Invalid argument, we can only convert 'string with numeric characters' into 'int' type.
    int val = stoi("89");//OK.
    
    
    std::cout <<  str1 <<"\n"
         <<  val <<"\n"
         <<std::endl;
    return 0;
}