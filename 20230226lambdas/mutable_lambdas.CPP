#include<iostream>
#include<string>
#include<vector>


using namespace std;

/*
    By default, a lambda may not change the value of a variable that it "copies by value". If we want to do so, we must follow the parameter list with the keyword 'mutable'. 
    But we can change the variable captured by reference directly in the function body of lambda.
 */

int main()
{
    int val = 10;
    // auto f = [val]{return val++;};//ERROR, variable 'val' is read_only. 
    auto f = [val]() mutable {return val++; };//OK
    int res = f();//'res' will be 10, since 'val' is returned before it increments.
    
    auto g = [&val]{return ++val;};//OK
        
    std::cout <<  res <<"\n"
         <<  f() <<"\n"
         <<  g() <<"\n"
         <<std::endl;
    return 0;
}