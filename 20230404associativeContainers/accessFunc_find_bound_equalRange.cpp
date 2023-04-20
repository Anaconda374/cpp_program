#include<iostream>
#include<map>

int main(){
    std::multimap<std::string, std::string> regi;
    regi.insert({"professor", "Ramirez"});
    regi.insert({"estudiente", "Carmen"});
    regi.insert({"professor", "Anna"});
    regi.insert({"estudiente", "Fernando"});

//'.find(k)' returns an iterator to the first(if it's a multi container) element with Key 'k', or the off_the_end iterator if 'k' is not in the container.

    //We can use '.find(k)' to print all element related with the same key, since when a 'multimap' or 'multiset' has multiple elements of a given key, those elments will be arranged adjcently within the container.
    auto it = regi.find("professor");
    auto count = regi.count("professor");
    while(count){
        std::cout<< it->second <<std::endl;
        ++it;
        --count;
    }


/*
  '.lower_bound(k)' returns an iterator to "the first element with key not_less_than 'k' (the first element with Key 'k' if Key 'k' is existed within the container.)"
*
  '.upper_bound(k)' returns an iterator to "the first element with key greater_than 'k' (the end_of_last element with Key 'k' if Key 'k' is existed with the container.)"
*
  NOTE: '.lower_bound(k)' and '.upper_bound(k)' are not valid for the unordered containers.And if the element with Key 'k' is not in the ordered container, then both them will return the same iterators("not_less_than == greater_than" in this case), both wil refer to the position at which the key can be inserted without disrupting the order. 
*/
    //use '.lower.bound(k)' and '.upper_bound(k)' to access all student entries:
    std::string key = "estudiente";
    for(auto beg = regi.lower_bound(key), 
             end = regi.upper_bound(key); //no need adding more 'auto' specifier after comma ','.
        beg!= end; ++beg){ //if "key" does not exist in the container, them 'beg' will equal to 'end', and the loop will not execute.

            std::cout<< beg->second <<std::endl;
        }
    

/*
  '.equal_range(k)' is like a compound of 'lower_bound(k)' and 'upper_bound(k)', it returns a structure containing a pair of iterators'pair<begIter, endIter>', refer to "the first instance of the key" and "one past the last instance of the key". 
  If no matching element is found, then both the first and second iterator refer to the position where is key can be inserted without disrupting the order. 
*/
    //use '.equal_range(key)' to access all 'professor' entries:
    for(auto range = regi.equal_range("professor"); range.first != range.second; ++range.first){
        std::cout<< range.first->second <<std::endl;
    }

    
    return 0;
}    