#include<iostream>
#include<map> //types 'map' and 'multimap' are defined in the header 'map' under the namespace'std'.


/*
    like the sequential containers, the associative containers are templates. whenever we define or declare a 'map', we must specify both the key and value types.
*/

void printMap(std::map<std::string, std::size_t> mp){
    /*
    A map is an associaltive array(array_like) of structures which have 2 public members 'first's(indicates the key) and  '.second' (indicates the value bound to the key). 
    */
    for(const auto& w: mp){//iterate each structure in the map.
        std::cout <<"key: "<<w.first << " value: "<<w.second<< std::endl;
    } 
}


int main(){
    //define a map to record how many times each word appears.  
    std::map<std::string, std::size_t> word_count;
    std::string word;
    while(std::cin >> word){
        /*
            Unlike normal arrays, an associative array do not have to use 'integers' as its subscripts, but use the key 'mp[key]' to map to the corresponding value(although we can still define the keys of 'int' type).
        */ 
        word_count[word]++; 
        /* if 'word' is not already in map 'word_count', the following 'subscript_operator' creates a new element whose key is 'word' with the value '0'. */
    }
    printMap(word_count);//all paired-values in map will be arreranged in ASCII order according to the 'keys'.

    return 0;
}