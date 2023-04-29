#include<iostream>
#include<map>

/*
    'multimao' is implement using red-black tree data structure.
    a 'multimap'(is kind of like 'hash_table') contains a sorted list of key-value pairs while permitting multiple entries(a entry in database: an item, a record. For example a piece of information.) with the same key.
*
    unlile 'map', 'multimap' do not has subscript operator[] to dereference the keys for getting a specific value, since each key can be bound by multiple values.  
*/

//define a funtion to print a descending multimap.
void printMultiMap(std::multimap<std::string, int ,std::greater<> > mulMp){
    for(const auto& i: mulMp){//iterate each structure in the map.
        std::cout <<"key: "<<i.first << " value: "<<i.second<< std::endl;
    } 
}

int main(){

    //define a 'multimap' in descending order by passing the third parameter--The predicate 'std::greater<>':
    std::multimap<std::string, int, std::greater<> > mulmp;
    
    //Sevaral ways to form key-value pairs:
    //1.'{key, value}'
    mulmp.insert({"lunes",1});

    //2.'std::pair<keyType, valueType>(key,value)'
    mulmp.insert(std::pair<std::string, int>("lunes",11));
    
    //3.'std::make_pair(key, value)'
    mulmp.insert(std::make_pair("martes",2));

    mulmp.insert({"martes",22});
    mulmp.insert({"miercoles",3});

    printMultiMap(mulmp);

    //use '.equal_range(key)' to get all pairs of the given key, it returns a pointer which points to the key-value structure(of give key) in multimap:
    auto keyValue = mulmp.equal_range("lunes");
    auto test = mulmp.equal_range("martes");
    
    //'count' the number of pairs of given key in multimap:
    std::cout<<"The number of lunes in multimap: "<< mulmp.count("lunes") <<std::endl;

    /*
    use iterator to access the pairs in multimap:
        NOTE:
    */
    auto it = mulmp.begin(); 
    std::cout<<"The first pair is: "<< it->first << " "<<it->second <<std::endl;
    ++it;
    std::cout<<"The second pair is: "<< it->first << " "<<it->second<<std::endl;
    ++it;
    std::cout<<"The third pair is: "<< it->first << " "<<it->second<<std::endl;

    //get a first value of key 'lunes' by dereference the key-value structure.
    std::cout<< keyValue.first->second << std::endl;

    //get a seond value of key 'lunes' by dereference the key-value structure.
    std::cout<< (++keyValue.first)->second << std::endl;

    std::cout<< test.second->first << std::endl;//Undefined behavior, Caution!!!
    //NOTE: the 'keyValue.second' is pointer which points to the end-off the last key-value pairs of 'keyValue', such that to dereference 'keyValue.second->first' is undefined.

    return 0;
}