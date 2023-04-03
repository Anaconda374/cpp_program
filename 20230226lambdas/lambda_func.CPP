#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include "d:\cpp_program\cpp_headers\ContainerPrinter.h"


using namespace std;


/*
'Lambda' is introduced in C++ standard: 
    A lambda function is like a "anonymous and disposable function", wherever we set a pointer to a function , we can set a lambda function there. 
*
    The idea of 'lambda' is essentially related to 'pointer_to_function'. For example, when we define a function 'F' that takes a function(pointer_to_function), we are not sure(or not need to decide) what kinds of operations it may do in the future. Once we want to call 'F' to perform a certain behavior temporarily, we can simply difine an specific inline function(lambda), and pass it to 'F'.  
 */

/*
Syntax of Lambda definition: 
    " auto lambdaName = [capture](parameter list) {function body;} "
*
    [capture]: a comma-separated list of zero or more captures, so we can capture local variables defined before the lambda. captures can be passed by either 'copied_value' or 'reference'
      [&] : capture all external variables by reference 
      [=] : capture all external variables by value 
      [a, &b] : capture 'a' by value and 'b' by reference
*   
    (parameter list): unlike the normal function, we can not define the parameters arbitrarily since the lambda function should be pass to another function, so the type and number of its parameters must match to that target function.
*/

//define a generic function that takes an 'int' and a "function which has an 'int' paramter".   
int select_func(int v1, int (*pf)(int)){
    return pf(v1);
}    

void add(int& val){
    val = val + 10;
}

int main()
{
//define a lambda function (with no capture) that calculates the value of a number to 8th power. When we use 'auto' to define a variable initialized by a lambda, we are defining an object of the type generated from that lambda.
    
    auto power = [](int value){ //power is a object created by this lambda.
        int pow = value;
        for(int i = 0; i != 8; i++){
            pow = pow * value;
            }
        return pow;    
    }; 
    
    int val = select_func(2, power);
    cout<< val << endl;
/*
NOTE:
    A lambda can only be converted to a function pointer if it does not have capture. Because when we pass a lambda as a pointer_to_function, it only passed the functionality defined by the lambda. 
    However, if you want to pass the entire object that gets created by the lambda, including the variables captured in the brackets, you need to pass it as a function object instead, not just a function pointer. 
*/
      
      
/*
    Passing a lambda with capture as a function(not a pointer) to the ambient function, we are defining both a new type and an object of that type. 
    By default, the class generated from a lambda(when lambda is defined, not called.) contains a data member corresponding to the variables captured by the lambda. Like the data members of any class, the data members of a lambda are initialized when a lambda object is created.
*/
    vector<int> iVec = {20, 23, 02, 25};
    int addVal = 5;
    
    //for_each(iter1, iter2, unary_function) is a library algorithm.
    for_each(iVec.begin(), iVec.end(), [addVal](int& i){i = i + addVal;});
    //add each element with the local variable 'addVal'.
    printVector(iVec);
    
    //we also pass a self_defined function(which can not take capture) instead of a inline 'lambda'. 
    for_each(iVec.begin(), iVec.end(), add);
    printVector(iVec);

    
    
    return 0;
}