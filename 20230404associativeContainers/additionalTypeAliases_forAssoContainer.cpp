#include<iostream>
#include<set>
#include<map>
#include<typeinfo>

/*
    In addition to the types of normal sequential containers, 'associative containers' define 3 more type_aliases to represent the container's 'key' and 'value' types. there are:
        1. 'key_type' -- Type of the 'key' for this container type.
        2. 'mapped_type' -- Type of the 'maped_value' associated with each key, 'map' types only(since 'set' only contains keys).
        3. 'value_type' -- For 'set', same as the 'key_type', For 'map', it's a 'pair' type, 'pair<const key_type, mapped_type>'. NOTE: since we cannot change an element's key in a map, the "key part of pair" is 'const'.
*/

int main(){
    std::map<char, int>::value_type t1;
    std::map<char, int>::key_type t2;
    //type of t1 is 'pair<char, int>'.
    std::map<char, int>::mapped_type t3;
    std::cout<< typeid(t1).name() <<std::endl; 
    std::cout<< typeid(t2).name() <<std::endl; 
    std::cout<< typeid(t3).name() <<std::endl; 


    std::set<std::string>::value_type t4;
    std::set<std::string>::key_type t5;
    //both 't4' and 't5' has the same type of 'std::string'.
    std::cout<< typeid(t4).name() <<std::endl; 
    std::cout<< typeid(t5).name() <<std::endl; 

}