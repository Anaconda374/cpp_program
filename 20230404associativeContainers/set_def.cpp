#include<iostream>
#include<set>//types 'set' and 'multiset' are defined in the header 'set' under the namespace'std'.

/*A set is simply a collection of keys, the associative container'set' is most useful when we simply want to check whether a value is present among a bunch of keys*/
int main(){ 
    // 'set' is a template type. whenever we define or declare a 'set', we must specify the type of the keys it contains.
    std::set<std::string> strSet = {"kuan","is","anacs"};

//the call to 'find' returns an iterator. If the given key is in the set, the iterator refers to that key. if the element is not found, 'find' returns the off_the_end iterator.

    //use relative operator '==' to check whether word 'anacs' is present in set'strSet':
    if(strSet.find("anacs") == strSet.end()){
        std::cout<<"not present :( ..." <<std::endl;
    }
    else{
        std::cout<< "Yes, it is present :) !";
    }
    return 0;
}