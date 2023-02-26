#include<iostream>
#include<string>
#include<vector>


int main()
{
//Adding a newline after "each empty string or a string ends with a period.
    std::vector<std::string> text = {"I","love", "you.", "","you", "too."};
    
    for(const auto &s : text){
    /* Making 's' a reference, we can avoid copying the elements(for saving storage). because 
     * we do not need to write to the elements, we made 's' a reference to const.
     */
        std::cout <<s ;
        if(s.empty() || s[s.size()-1]=='.'){
        /* Using logical operator "||" as a condition, means the body of "if control" will perform
         * if either operand is 'True'.
         */
            std::cout<<std::endl;
        }
        else{
            std::cout<< " ";
        }
    }
    
    
    return 0;
}