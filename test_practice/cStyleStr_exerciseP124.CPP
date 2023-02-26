#include<iostream>
#include<string>
#include<cstring>

int main()
{
/* CAUTION: If a C-style string is not null_terminated, when using a pointer to traverse it may 
 *          cause surprisingly behavior.
 */
    const char ca1[] = {'h','e','l'};
    const char ca2[6] = "hello";
    const char *p = ca2;
    while(*p){
        std::cout<< *p << std::endl;
        ++p;
    }
    
    char catStr1[] = "I love ";
    char catStr2[] = "you";
    char catStr3[] = " ";
    std::strcat(catStr1, catStr2);
    std::strcpy(catStr3, catStr1);
    std::cout<< catStr3 << std::endl;
    return 0;
}