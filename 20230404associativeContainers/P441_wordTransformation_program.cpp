#include<iostream>
#include<map>
#include<fstream>
#include<sstream>
#include<stdexcept>

std::map<std::string, std::string> buildMap(std::ifstream& map_file){
    std::map<std::string, std::string> trans_map;
    std::string key; //a acronym to transform.
    std::string value; // phrase to use instead.

    //reade the first word of each line into 'key', and the rest of the line into 'value':
    while(map_file >> key && getline(map_file, value)){
       if(value.size()>1){
        trans_map[key] = value.substr(1); //skip the leading space of 'value'.
       }
       else{
        throw std::runtime_error("no rule for " + key);
       }
    }
    return trans_map;
}

std::string transform(std::string& word, std::map<std::string, std::string>&  trans_map){
    auto map_it = trans_map.find(word);
    if(map_it != trans_map.end()){
        return map_it->second;
    }
    else{
        return word;
    }

}

//define a function to print the transformed text:
void word_transform(std::ifstream& map_file, std::ifstream& input){
    auto trans_map = buildMap(map_file);
    std::string text;
    while(getline(input, text)){
        std::istringstream lineStream(text);
        std::string word;
        bool firstWord = true;//use a flag to control whether a space" " is printed.
        while(lineStream>>word){
            if(firstWord){
                firstWord = false;
            }
            else{
                std::cout<<" ";
                //if the word is the firstWord of each line, then not print the space" ".
            }
            std::cout<< transform(word, trans_map);
        }
        std::cout<<std::endl;//print a new line after each line.
    }


}


int main(){
    std::ifstream transRules("map_file.txt");
    std::ifstream input("input.txt");
    word_transform(transRules, input);


    return 0;

}