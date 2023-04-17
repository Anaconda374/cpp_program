#include<iostream>
#include<set>
#include<vector>

//define a funtion to print a string set.
void printStrSet(std::set<std::string> s){
    for(auto i : s){
        std::cout<< i <<" ";
    }
}
//define a overloading funtion to print a string set.
void printStrSet(std::multiset<std::string> s){
    for(auto i : s){
        std::cout<< i <<" ";
    }
}

//unlike 'set' only contains unique keys, 'multiset' allows us to store duplicate keys in it.
int main(){
    std::vector<std::string>  strVec = {"kuan","is","anacs","kuan","is","anacs"};
    //assign 'strVec' to a 'set' using iterators:
    std::set<std::string> strSet(strVec.begin(), strVec.end());
    //assign 'strVec' to a 'set':
    std::multiset<std::string> strMultiSet(strVec.begin(), strVec.end());

    std::cout<<"strSet: "<<std::endl;
    printStrSet(strSet);

    std::cout<<std::endl;

    //multiset'strMultiSet' can contain all keys copied from 'strVec', but arranged in ASCII order.
    std::cout<<"strMultiSet: "<<std::endl;
    printStrSet(strMultiSet);

    return 0;
}