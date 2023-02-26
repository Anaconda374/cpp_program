#include<iostream>
#include<string>
/* 1.Function returns a 'copy':
 * The returned value is used to initialize(to copy) a temporary object at "the call site".
 */
std::string longerString(std::string& s1, std::string& s2){
    return s1.size() <= s2.size() ? s2 : s1;
}

/* 2. Function returns a 'reference':
 * By setting reference parameters, we can return a reference which directly refer the argument passed to the function.
 */
std::string& shorterString(std::string& s1, std::string& s2){
    return s1.size() <= s2.size() ? s1 : s2;
}

/* NOTE:Never return a Reference or Pointer to "a Local Object defined in the function", since when a function completes, its storage is freed, so "the reference or pointer to a local object"(the reference or pointer is refer to memory) is no longer valid.
 */

int main()
{
    std::string a = "aaa", b = "bbbb";
    std::string& ss = shorterString(a, b);
    ss = "changed_ss";
    //we can even change the value of arguments by the returned reference variable.
    std::cout <<  ss <<"\n"
         <<  a <<std::endl;
    
    
    std::string c = "cj", d = "Anacs";
    std::string ls = longerString(c, d);
    std::cout << ls << std::endl;
    ls = "changed_d";
    //we cannot change the value of argument by the returned copy.
    std::cout<< ls <<"\n"
             << d << std::endl;
    
    return 0;
}