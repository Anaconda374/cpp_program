#include<iostream>
#include<vector>
#include<map>
#include<set>


void printIntSet(std::set<int> s){
    for(auto i : s){
        std::cout<< i <<std::endl;
    }
}

int main(){
    std::set<int> iSet = {2,0,2,3,2,0,2,3};
    //'iSet' only contians 3 elements {0,2,3}, since 'map' and 'set' contain unique keys.
    printIntSet(iSet);
    std::cout<<std::endl;

    //'iSet' contians 4 elements {0,1,2,3} now, inserting an element that is already present has no effect.
    iSet.insert({1,2,3});
    printIntSet(iSet);

/*
    '.emplace(args)' for both 'map' and 'set', the element is inserted only if an element with "the given key(args)" is not already in the container. It returns a pair oject'pair<iterator, bool>' containing "an iterator referring to the element with the given key", and "a bool value indicates whether the element was actually inserted".
*/ 
    auto resPair = iSet.emplace(3);
    std::cout<< *resPair.first <<" "<< resPair.second<< std::endl;//'3' is not inserted.


    //To insert into a map we have to pass a 'pair' as the argument.
    std::map<std::string, int> meses = {{"enero",1},{"febrero",2},{"marzo",3}};
    meses.insert({"abril", 4});
    meses.insert(std::make_pair("mayo", 5));
    meses.insert(std::pair<std::string, int>("junio", 6));
    //using 'value_type' to explicitly construct a pair.
    meses.insert(std::map<std::string, int>::value_type("julio", 7));



    return 0;
}