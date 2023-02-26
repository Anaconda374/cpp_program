#include<iostream>
#include<string>
/* When a parameter of a function that is almost given a particular value, we can declare that common value a default argument for that parameter(as an initializer in parameter list).
  Functions with default arguments can be called use or unuse(by passing a new) that argument.
 */
 
/* The default arguments are used for the trailing(right_most) arguments of a call:
 * If a parameter has a default argument, all the parameter that follow it must also have default arguments, so the strategy of designing a function with default arguments is that ordering the parameters, so that those least likely to use a default value appear first(probably gonna be changed), and those most likely to use a default appear last.
 */

double nthPower(const double number = 10 ,const int exp = 2){//default arguments.
    double power = 1;
    for(int i = 1; i <= exp; ++i){
        power = number * power;
    }
    return power;
}


int main()
{
    
    
    std::cout <<  nthPower() <<"\n"
         <<  nthPower(7) <<"\n"//OK, 'nthPower(7,2)', the trailing argument can be omitted.
         // <<nthPower( , 4) //ERROR, the first argument cannot be omitted.
         <<std::endl;
    return 0;
}