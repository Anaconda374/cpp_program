#include<iostream>
#include<string>
/* The call to "a functions that returns a reference" is a lvalue, and it can also be assigned with a value to modify the original object to which it refers. 
 */
std::string & shorterString(std::string& s1, std::string& s2){
    return s1.size() <= s2.size() ? s1 : s2;
}

int main()
{
    std::string a = "aaa", b = "bbbb"; 
    shorterString(a, b) = "changed_shorterString";//the assignment is appied to string'a'.
 
    std::cout <<  a <<std::endl;

    return 0;
}