#include<iostream>
#include<string>

/* 
   If a function return a pointer, reference or object of "class type", we can use "the result of that function call" to call a member of the resulting object.
 * 
   Any other return types yield rvalues.
   The 'call_operator: () ' has the same precedence as the "dot operator: . " and the "arrow operator -> ", and it's also left associative.
 */

std::string & shorterString(std::string& s1, std::string& s2){
    return s1.size() <= s2.size() ? s1 : s2;
}

int main()
{
    std::string a = "aaa", b = "bbbb"; 
    auto shorterSize = shorterString(a, b).size();
    /* 
        The return of Function'shorterString' is the left_hand operand of the dot operator. That operator fetches the member 'size' of the class_type 'string', and the member'size' is also the left_hand operand of the 'call_operator ()'.
     */
    
    std::cout <<  shorterSize <<std::endl;
    return 0;
}