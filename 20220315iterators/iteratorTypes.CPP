#include<iostream>
#include<string>
#include<vector>
/* 
   We generally do not know--and do not need to know--the precise type of an iterator.Instead, as with size_type, "the library types that have iterators" define types named 'iterator' and 'const_iterator' that represent actual iterator types.
 */
 
int main()
{
//Type 'iterator':
    std::vector<int> iv {1,2,3,4};
//Instead of using 'auto' to deduce the type, we can use 'iterator' to define a iterator variable.
    std::vector<int>::iterator it = iv.begin();
    std::cout <<  *(it+2) <<"\n"
         <<std::endl;

// Type 'const_iterator':
    std::string s = "I love juanjuan";
/* 
   A 'const_iterator' object may read but not able to write the element it denotes; if a vector or string is 'const', we may use only its 'const_iterator type'. With a nonconst vector or string, we can use either 'iterator' or 'const_iterator'.
 */
    for(std::string::const_iterator si = s.begin(); si != s.end(); si++){
        std::cout<< *si ;    
    }
    std::cout<<std::endl;
/* Abstractive definition of "iterator types":
    A type is an iterator if it supports a common set of actions. Those actions let us access an element in a container and let us move from one element to another. Therefore, each container class defines (its own) a type named 'iterator', that "iterator type" supports the actions of an (conceptual) iterator.  
 */    
    return 0;
}