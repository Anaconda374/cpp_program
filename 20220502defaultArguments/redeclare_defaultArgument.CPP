#include<iostream>
#include<string>
/* 
   Although "default arguments" ordinarily should be specified with the function declaration in an appropriate header, it is legal to redeclare a function multiple times. 
 * 
   However, each parameter can have its default specified only once in a given scope. Thus, any subsequent declaration can add a default only if all parameters to the right already have defaults in a given scope.
 */

using sz = std::string::size_type;
void char_screen(sz height = 20, sz width = 20, char background = 'x'){
    for(unsigned i = 1; i <= height; ++i){
        for(unsigned j = 1; j <= width; ++j){
            std::cout<<background;
        }
        std::cout<< std::endl;
    }
} 

int main()
{
    char_screen(10,10);//This line is outer to the scope of the redeclaration below. 


/* Redeclaration of the function with defualt arguments.
 * NOTE: 'height' and 'width' become unspecified parameter here. 
 */
    void char_screen(sz height, sz width, char background = 'y');
    // char_screen(); //ERROR, no arguments to 'height' and 'width'.
    char_screen(30,30);//OK.
    
    
//ERROR, re_specification of 'background' which is previously specified in this scope.
    // void char_screen(sz height, sz width = 10, char background = 'z');
    
    return 0;
}