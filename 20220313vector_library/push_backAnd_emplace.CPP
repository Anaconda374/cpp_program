#include<iostream>
#include<string>
#include<vector>
/* 
   since vectors grow efficiently, it's unnecessary to define a vector a specific size, except all the elements actually need the same value. if differing element values are needed, it is usually more efficient to define "an empty vector" and add elements as the values become known at run time by using push_back member.
 */

int main()
{
    std::string word;
    std::vector<std::string> text;
    while(std::cin >> word)
        text.push_back(word);
    //The 'push_back' operation takes a value and "pushed" that value as a new last element onto the "back" of the vector.
 
    while(text.size() != 0){
        std::cout<< text.back() <<std::endl;
        //'.back()' returns a reference to the last element.
        
        text.pop_back();
        //'.pop_back()' removes last element in the vector.
    }
 
//We can also using ' .emplace(pos, element)' to insert an element at a specific position(by using iterator), and it returns an iterator that points to the newly inserted element.
    
    auto pos = text.emplace(text.end(), "end.");

    std::cout <<"The insert string is "<< *pos 
    << " at position " << pos - text.begin()<<std::endl;
    
    for(int i = 0; i < text.size();++i)
        std::cout <<  text[i] <<"\n"
         <<std::endl;
    return 0;
}