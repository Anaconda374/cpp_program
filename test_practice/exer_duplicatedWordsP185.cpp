#include<iostream>
#include<string>
#include<vector>
#include<iterator>


int main()
{
    std::vector<std::string> text;
    std::string word;
    while(std::cin >> word){
        text.push_back(word);
    }
    unsigned int cnt = 1;
    std::string most_word;
    unsigned max_cnt = 1;
    for(auto i = text.begin(); i != text.end(); ++i){
        if(*i == *(i+1)){
            ++cnt;
            if(max_cnt < cnt){
                max_cnt = cnt;
                most_word = *i;
            }
        }
        else {
            cnt = 1;
        }
        
    }
    std::cout<<"The most duplicate word is \"" << most_word << "\" appears " << max_cnt<<
    " times"<<std::endl;
    
    return 0;
}