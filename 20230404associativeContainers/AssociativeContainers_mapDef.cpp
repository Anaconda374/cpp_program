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
    //Each associative container type has a default constructor, when we define an associative container(without initialization) like above, it creates an empty container of the specified type.

    //We can also initialize or assign an associative container as a copy of another container of the same type or from a range of values(denoted by iterators), so long as those values can be converted to the type of the container.
    word_count = {{"enero",1},{"febrero",2},{"marzo",3}};//list initialization.

    //if a map is assigned by another map, its original values will be eliminated and will have a copy of the lvalue map.
    std::map<std::string, std::size_t> meses = {{"abril", 4},{"mayo", 5},{"junio",6}};

    word_count = meses;

    std::string word;
    while(std::cin >> word){
        /*
            Unlike normal arrays, an associative array do not have to use 'integers' as its subscripts, but use the key 'mp[key]' to map to the corresponding value(although we can still define the keys of 'int' type).
        */ 
        word_count[word]++; 
        /* if 'word' is not already in map 'word_count', the following 'subscript_operator' creates a new element whose key is 'word' with the value '0'. */
    }
    printMap(word_count);
/*
NOTE: Associative container do not support  the sequential_container position_specific operations, such as '.push_back()' or '.push_front()':
    Because all elements in an ordered associative container('map','set','multimap' and 'multiset') will be arreranged in ASCII order according to the 'keys'(ascending order by default), those operations would be meaningless for the associative containers. 
*
    And thanks to this storing mechanism, the associative containers do not support the normal array constructors or insert operation that take only an element value and a count.
*/
    return 0;
}