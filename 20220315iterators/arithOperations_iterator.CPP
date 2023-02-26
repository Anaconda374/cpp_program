#include<iostream>
#include<string>
#include<vector>


int main()
{
    std::string s1 = "zen47";
    auto it1 = s1.begin(),it2 = s1.end();
    auto dif = it1 - it2;
    std::cout <<  dif <<"\n"
         <<std::endl;
/* 
   Subtracting two iterators yields the number that when added to the right_hand iterator yields the left_hand iterator, the iterators must denote the elements or one past the end of the same container.
 *
   The result type is a signed integral type named 'difference_type', such that, we can convert "an iterator" to "a signed int type" by doing this kind of operations.  
 */
    
    
    
    //auto sum = it1 + it2;//ERROR, the operation of adding 2 iterators is undefined.

    
    
    return 0;
}