#include<iostream>
#include<map>
#include<set>
#include<iterator>

/*
    Associative containers also have 'iterators' as the normal sequential containers have, such as '.begin()' and '.end()', but has slightly different features.
*/

int main(){

//Iterator of 'map' is used to dereference the key_value pairs(structures), so that we have to use arrow operator '->' to retrieve 'key' or 'value' instead of using asterisk operator '*'/   
    std::map<std::string, int> meses = {{"enero",1},{"febrero",2},{"marzo",3}};
    std::map<std::string, int>::iterator mapIter = meses.begin();
    while(mapIter != meses.cend()){
        // mapIter->first = "cambiado"; //ERROR, the key_type is 'const', read_only.
        std::cout<< mapIter->first << " is No. " << mapIter->second << " mes." <<std::endl;
        ++mapIter;
    }

//Iterator of 'set' is used to dereference the keys, we can use asterisk operator'*' to retrieve 'key', but cannot write the key(const) through the iterator too.
    std::set<std::string> alimentos = {"azucar", "chocolate", "agua"};
    std::set<std::string>::iterator setIter = alimentos.begin();
    while(setIter != alimentos.end()){
        // *setIter = "cambiado"; //ERROR, the key_type is 'const', read_only.
        std::cout<< *setIter <<std::endl;
        ++setIter;
    }

/*
Arithmetical operations to iterators of associative container:
    Since 'std::set' is implemented as a binary search tree, the elements are not stored contiguously in memory, and it is not possible to use the addition operator to directly move the iterator forward by a certain number of positions. Instead, you can use the std::advance function to increment the iterator by a certain number of positions. 
*/
    auto it = meses.begin();
    std::advance(it, 2);//equivalent to "it = it + 2;"
    std::cout<< it->second <<std::endl;

    return 0;
}