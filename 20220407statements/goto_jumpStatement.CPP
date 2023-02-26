#include<iostream>
#include<string>
/* 
    'goto' is unconditional jump, from the goto to a another statement which is labeled in the same scope(or function). 
 * 
    CAUTION: 'goto' statements make programs hard to understand and hard to modify.
 *
    Form: goto labelName;
 */

int main()
{
    //Label statement is any statement that is preceded by "an identifier" followed by a colon.
    getC: while(char a = getchar()){//'getC' is an identifier.
        if(a != '\n'){
            unsigned asciiCode = a;
            std::cout << asciiCode << std::endl;//Output the ASCII_code of the input chars.
        }   
        else{
            break;
        }
    }
            
    goto getC;
    /* 
        using 'goto' to jump back to a point before the variables are defined(such as 'ascciCode' and 'a' here) will destroys the variables and constructs, and then define them a new along the execution flow.
     */
    
    return 0;
}