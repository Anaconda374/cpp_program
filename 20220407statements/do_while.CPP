#include<iostream>
#include<string>
/* "Two Notes" for 'do_while' loops:
 * 1.Variables used in "the condition" must be defined outside "the body of the do_while".
 * In the other way around, variables used in "the body" cannot define in "the condition", since the condition is not evaluated until after the body.
 *
 * 2.A 'do_while' ends with a semicolon';' after the parenthesized condition.
 */

int main()
{
//ERROR, variable'i' is freed after the execution of the do_while body:

    // do{
        // int i = 0;
        // std::cout<< i << std::endl;
        // i++;
    // }while(i < 5); 
    
    
    
//ERROR, cannot define a variable in condition:

    // do{
        // std::cout << "test" << std::endl;
        
    // }while(char a = getchar());
    
    
    
//OK, define the variable in condition outside the body:
    int j = 1; 
    do{
        int val = 0;
        std::cout << val << std::endl; 
        // always outputs '0' since variable'val' is freed after each execution of the body.
        ++val;
        ++j;
    }while(j<5);
    
    return 0;
}