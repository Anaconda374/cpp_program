#include<iostream>
#include<map>
#include<set>
#include <iterator> // for std::advance

/*
    Associative containers define 3 overloaded '.erase()' functions to delete the element(s) in the container, and these functions have slightly different features.
*/

void printIntSet(std::multiset<int> s){
    for(auto i : s){
        std::cout<< i <<" ";
    }
}


int main(){
    std::multimap<std::string, int> semana = {{"lunes",1},{"martes",2},{"miercoles",3},{"jueves",4}, {"viernes", 5}, {"lunes",1}};
    std::cout<< semana.count("lunes")<<std::endl;//count("lunes") = 2.

//1. '.erase(k)' removes every element with key 'k' from the container(for both unique and multi), returns a size_type value indicating the number of elements removed.
    int count_removed = semana.erase("lunes");
    std::cout<< count_removed <<std::endl; // 2 elements has been removed.
    std::cout<< semana.count("lunes")<<std::endl; // count("lunes") = 0 now.

//2. '.erase(p)' removes one element denoted by the iterator 'p' from the container, returns an iterator to the element after 'p' or 'end()' if 'p' denoteds the last element.
    std::multiset<int> mSet = {0, 1, 2, 3, 4};
    mSet.erase(mSet.begin());
    printIntSet(mSet);//mSet = {1,2,3,4}
    std::cout<<std::endl;

//3. '.erase(beg, end)' removes the elements in the range denoted by the iterator pair 'beg' and 'end', return iterator 'end'.
    std::multiset<int>::iterator it = mSet.begin();
    
    std::advance(it, 3);
    mSet.erase(mSet.begin(), it);
    printIntSet(mSet);//mSet = {4}

    return 0;
}