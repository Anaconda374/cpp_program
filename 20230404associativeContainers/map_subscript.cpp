#include<iostream>
#include<map>

/*
    The containers 'map' and 'unordered_map' provide the subscript operator'[key]' to get the corresponding unique value of this 'key' by passing the 'key' as the index. 
    And function 'at(key)' used to check whether the key is stored in the 'map'.
*   
    The 'set' types do not support subscripting because there is no 'value' associated with a key in a set. And 'multimap' or 'unordered_multimap' also do not support because there may be more than one value associated with a given key.

*/

void printMap(std::map<std::string, int> Mp){
    for(const auto& i: Mp){//iterate each structure in the map.
        std::cout <<"key: "<<i.first << " value: "<<i.second<< std::endl;
    } 
}

int main(){
    std::map<std::string, int> meses = {{"abril", 4},{"mayo", 5},{"junio",6}};
//subcript an associative container 'c[k]' returns the value with Key 'k'; if 'k' is not in Container 'c', adds a new value-initialized(0 for int, "" for string) element with Key 'k' to the container.
    auto elem = meses["abril"];
    std::cout<< elem <<std::endl; 
    meses["julio"];//we can even subcript 'map' without return, just for adding new element. In this case: pair<"julio", 0>.
    printMap(meses);

//'c.at[k]' can be used to check whether the element with Key 'k' in Container 'c', if it exists, returns the corresponding 'value' with 'k', otherwise throw an 'out_of_range' exception.
    auto check = meses.at("abril"); //'check' is '4'.
    std::cout<<check<<std::endl;

    std::cout<< meses.at("augusto") <<std::endl;//"augusto" does not exist, 'out_of_range'.
    
    

    return 0;
}