#include<iostream>
#include<string>
#include<vector>

void printVector(std::vector<std::string> vec , 
                        std::vector<std::string>::size_type count){
    std::vector<std::string>::size_type index = count - 1;
    if(index != 0 ){
        printVector(vec, index);
    }
    std::cout << vec[index] << std::endl;
    
}


int main()
{
    std::vector<std::string> sv = {"I", "love", "juanjuan"};
    printVector(sv, sv.size());
    
    return 0;
}