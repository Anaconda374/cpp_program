#include<iostream>
#include<string>


int main()
{
    const std::string s = "keep out!";
    for(auto &c : s){
// c = toupper(c); //ERROR,we cannot change top_level const 's' through read_only reference 'c'.
        std::cout <<  c <<"\n"
         <<std::endl;
    }
    
    
    std::cout <<  s[0] <<"\n"
         <<  0 <<"\n"
         <<std::endl;
    return 0;
}