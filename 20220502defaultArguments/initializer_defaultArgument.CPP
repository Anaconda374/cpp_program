#include<iostream>
#include<string>
/* 
   "Local variables(which defined out of the declaration of the function)" may not be used as a default argument to that function. Excepting this restriction, a default argument can be "any expression" that has a type as the same(or convertible) to the type of the parameter.
 */

using sz = std::string::size_type;

sz ht = 10;
sz wd = 10;
char bg = getchar();

//initialize the default arguments with 'variables' and 'function call'.
void char_screen(sz height = ht, sz width = wd, char background = bg);

int main()
{
    char_screen();//equivalent to 'char_screen(10,10,getchar())'.
    wd = 20;//change the value of the variable can also change the default arugment.
    char_screen();//equivalent to 'char_screen(10,20,getchar())'.
    
    
    sz ht = 20;
    /* This overload variable will hide the outer definition of 'ht' but does not change the default argument of the function.
     */
    char_screen();//still equivalent to 'char_screen(10,20,getchar())'.
    
    
    return 0;
}

void char_screen(sz height, sz width, char background){
    for(unsigned i = 1; i <= height; ++i){
        for(unsigned j = 1; j <= width; ++j){
            std::cout<<background;
        }
        std::cout<< std::endl;
    }
} 