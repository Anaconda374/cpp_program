#include<iostream>
#include<string>
/* 
If a function does not change the value of arguments, it much better to use "references to const" as the parameters. Since using "plain references" in this condition unduly limits the type of arguments, we cannot pass "const objects(cannot assgin 'const' to 'plain_ref')", "literals", or "objects that requires conversion".
 */
 
 std::string::size_type find_char(const std::string & s, char c, 
                                    std::string::size_type & occurs)
{   auto firstOccur_position = s.size();
    occurs = 0;
    for (decltype(firstOccur_position) i = 0; i!= s.size(); ++i){
        if(s[i] == c){
            if(firstOccur_position == s.size()){
                firstOccur_position = i;
            }
            ++occurs;
        }
        
    }
    return firstOccur_position;
}

//Initialize "the parameters" from "const argument of another function".
bool is_sentence(const std::string s){
    //if there is a '.' at the end of String's', then 's' is a sentence.
    std::string::size_type ctr = 0;

    return find_char(s, '.', ctr) == s.size()-1 && ctr==1;
    //The 1st parameter of 'find_char()' is initialized by the parameter of the outter funciton.
}

int main()
{
    std::string::size_type count = 0;
    char c = 'a'; 
//Initialize the const_reference parameters with 'literals'.
    std::string::size_type pos = find_char("AAAanacs", c, count);
    std::cout <<  pos <<"\n"
         <<  count <<"\n"
         <<std::endl;
         
    std::cout<< is_sentence("anacs.")<<std::endl;
    return 0;
}