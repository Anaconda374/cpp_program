#include<iostream>
#include<string>
/*
    By using 'template', we can define a "name" which can be substituted by any type name(such as 'int', 'std::string') according to the different situations.
    Such that we can define a general function once ,and it can be used in various situations(such as different types of arguments) by using 'template'. 
 */

template<typename N>
void print(N value){
    std::cout << value << std::endl;
}

int main()
{   
    print(7); 
    /*
        In this call of "print", the 'N' in the definition is substituted by 'int' in compiling time, since the complier can recognize '7' is a basic 'int' type.
     */
     
    print<std::string>("anacs");//In this call, 'N' is substituted by 'std::string'.
    
    return 0;
}