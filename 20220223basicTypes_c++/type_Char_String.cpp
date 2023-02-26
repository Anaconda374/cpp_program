#include<iostream>
#include<string>
#include<istream>
#include<cstring>

int main()
{
    char cstr1[10];
    // 'gets' can only used for 'cstring', it gets a string from the standard input, and ends with a '\0'. 
    gets(cstr1);
    puts(cstr1);
    char cstr2[10] = "kuan";
    
    //catenate the second cstring to the end of  the first one. And the end '\0' of the first cstring have been removed. 
    strcat(cstr1, cstr2);
    puts(cstr1);
    
    //copy the second cstring to the first, and it will overwrite the data in the first. 
    strcpy(cstr1, cstr2);
    puts(cstr1);
    
    //compare two cstrings char by char according to the ASCII code.
    int index = strcmp(cstr1, cstr2);
    std::cout<< index <<std::endl;
    //if two cstrings are equal, return 0; if the first is bigger, return 1; if the second is bigger, return -1. 
    
    
    std::string str1;
    //'getline' can only used for 'std::string'.
    getline(std::cin, str1);
    str1[str1.size()-1] = '\0';
    //It's easy to modify an object of type 'string'. 
    
    std::cout<< str1 << std::endl;
    
     
    // getline(std::cin, cstr);
    
    
    std::cout << "two adjacent "   
                "strings output test"  << std::endl; // they will get concatenated.
    
    
    return 0;
}