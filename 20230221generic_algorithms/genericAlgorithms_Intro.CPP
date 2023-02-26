#include<iostream>
#include<string>
#include<vector>
#include<array>

using namespace std;


/*The standard library defines a set of generic algorithms:    
    "algorithms" because they implement common classical algorithms such as 'sorting' and 'searching', and "generic" because they can operate on elements of different types and across multiple container types(including the built_in array type).
*/

#include<algorithm>//most of the algorithms are defined in the 'algorithm' header. 
#include<numeric> //the 'std' library(provides more than 100 algorithms) also defines a set of generic numeric algorithms that are defined in the 'numeric' header.


/*
The generic algorithms do not themselves execute container operations. They operate solely in terms of iterators and iterator operations:
    Since the algorithms are called generic, such that the algorithms do not work directly on a container. Instead, they operate by traversing a range(input range) of elements bounded by two iterators(or pointers for 'array'), as the algorithm traverse the range, it does something with each element.
*
    And generic algorithms never change the size of the underlying container.
*/
int main()
{
    return 0;
}