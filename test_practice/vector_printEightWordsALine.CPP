#include<iostream>
#include<string>
#include<vector>

int main()
{
    std::vector<std::string> sen;
    std::string word;
    while(std::cin >> word){
        sen.push_back(word);
    }
    decltype(sen.size()) i = 0;
    
    for(i; i<sen.size(); i++){
        for(unsigned j = 0; j < sen[i].size(); j++){
            sen[i][j] = toupper(sen[i][j]);
        }
        if (i%3 == 0)
            std::cout<<"\n" <<std::endl;
        std::cout<< sen[i] << " "; 
        /* without std::endl, the output buffer wouldnot flush, so three words can print 
         * on the same line until it meets the 'std::endl' in Line20.
         */ 
    }
    return 0;
}