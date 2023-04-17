#include<iostream>
#include<vector>
#include<utility> 
//The pair container is a simple container defined in <utility> header under namespace 'std'.

/*
 Type 'pair' is a consisting of two public data members--'first' and 'second'. it is used to combine together two values that may be of different data types. 
*
 Pair provides a way to store two heterogeneous objects as a single unit. It is basically used if we want to store tuples.  
*/

int main(){
//define 'pair' objects:
    std::pair<std::string, size_t> word_count; //without initialization, 'word_count' holds an empty string and a 'size_t' value = 0.
    std::pair<std::string, std::vector<int> > line; //without initialization, 'line' holds an empty string and an empty vector<int>.


//'pair' initializations in different manners:
    std::pair<std::string, int> mes1("enero", 1);
    std::pair<std::string, int> mes2 = {"febrero", 1};
    std::pair<std::string, int> mes3 = std::make_pair("marzo", 3);


//Operations on 'pairs':
    std::cout << mes1.first << std::endl; //call the data member 'first' of 'mes1'.
    std::cout<< mes3.second << std::endl; //call the data member 'second' of 'mes3'.

    /* 
    "pair1 relaOp pair2" compares the 'first' and 'second' members of 'pair1' and 'pair2' respectively. firstly compare 'pair1.first' with 'pair2.first', if the result is clear (true or false) then return (1 or 0), otherwise use the same relational operator to compare 'pair1.second' with 'pair2.second'.
    */
    bool res = mes1 < mes2; //return '1'.
    std::cout << res <<std::endl;

    return 0;
}