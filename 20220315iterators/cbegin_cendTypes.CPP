#include<iostream>
#include<string>
#include<vector>
/* 
   The type returned by '.begin' and '.end' depends on whether the object on which they operate is 'const'. Often this default behavior is not what we want, it is usually best to use a const_type(such as 'const_iterator') when we need to read but do not need to write to an object.
 * 
   Functions '.cbegin()' and '.cend()' give us specifically 'const_iterator' type.  
 */

int main()
{
    std::vector<int> v = {1, 2, 4};
    const std::vector<int> cv;
    auto it1 = v.begin();//'it1' has type 'vector<int>::iterator'.
    auto it2 = cv.begin();//'it2' has type 'vector<int>::const_iterator'.
    
// By using the '.cbegin()',we can enforce 'it3' to be type 'vector<int>::const_iterator'
    auto it3 = v.cbegin();  
    
    
    std::cout <<  *it1 <<"\n"
         <<  0 <<"\n"
         <<std::endl;
    return 0;
}