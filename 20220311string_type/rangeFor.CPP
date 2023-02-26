#include<iostream>
#include<string>
#include<cctype>
/* <cctype> is a "C standard library" incorporated by C++ which has functions dealing with 
 * characters.
 */
int main()
{
// Using for_range to print out all characters individually.    
    std::string s1 = "zen47";
    for(auto c1 : s1)
        std::cout << c1 <<std::endl;//print the current character and followed by a newline.


// 'iscontrl' function.
    std::string s2 = "it is a control\n'character'";    
    for(auto c2 : s2 )
        if (!iscntrl(c2))
//'iscntrl()'is a functin of 'ctype.h' for checking if the current character is a control character.
            std::cout << c2 << std::endl;
        else
            break;
        
// Using for_range to change the characters in a string.
    std::string s3 = "Zen.47";
    for(auto &c : s3){
        c = toupper(c);//convert all letters in s3 into uppercase. 
        std::cout<< c << std::endl;
    }
    std::cout << s3 <<std::endl;
        
/* 
    we can use the reference to each character to change the characters in a string, we cannot affect the original string by dealing with the character in for_range, since it's just copy of the character in string.In order to change the orginal object, we need to create a "reference/alias" or "pinter" to it. 
 */   
    return 0;
    
}