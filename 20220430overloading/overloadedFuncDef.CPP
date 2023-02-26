#include<iostream>
#include<string>
#include<iterator>
/* 
Why C++ supports overloaded functions, but C language does not?
    when C compiler translate "C source code" into "assembly language", the names of defined functions in the code is translated directly, such that when overloaded functions is written in C, the linker wouldn't know which function definition is going to be linked with the 'call',it just reports a linking error.
    
    But in C++, the translated name of function in assembly language is composed as "The function name + Acronym for all parameters", so the overloaded functions in C++ differ from each other in the number or the type(s) of their parameters. the linker can deduce which function (among the overloadedfunctions) we want, based on the type(or the number) of the arguments we pass.
    
    NOTE: we should only overload functions that actually do similar things such as dealing with different types of arguments respectively(or similarly), if the overloaded function loses "the information that was inherent in the function names" and makes the call harder to understand, then it should not be overloaded.
 */
void print(const char *cp){
     if(cp){
        while(*cp){
            std::cout<< *cp++ <<" ";
        }
    }
}

void print( int* beg, int* end){    
    while(beg != end){
        std::cout<<*beg++<<" ";
    }
}

int main()
{
    int arr[] = {1, 3, 1, 4};
    print("I love you");
    print(std::begin(arr), std::end(arr));
    //Different arguments determine which function being called.
    return 0;
}
