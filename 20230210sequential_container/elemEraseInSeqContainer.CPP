#include<iostream>
#include<string>
#include<vector>
#include<list>
#include<iterator>
#include "d:\cpp_program\cpp_headers\ContainerPrinter.h"

using namespace std;


/*
    Just as there are several ways to add elements to a (nonarray) container there are also several ways to remove elements. 

Note:
    When we need to use iterator to manipulate(insert or erase) the elements in container, it is a good idea to use member function 'insert(...)' and 'erase(...)', since they can return a refreshed iterator after each operation
 */
int main()
{
/*
'c.pop_front()' & 'c.pop_back()' returns 'void': 
similar with '.push_front()' & '.push_back()'. For example, if a container type only supports '.push_back()', then it can only use 'pop_back', such as 'vector', 'string'. 
*/    
    vector<int> vec1 = {1,4,0,3,0,5};
    vec1.pop_back();//erase the last element, if you need the value you are about to pop, you must store that value before 'pop_.()'.
    printVector(vec1);
    
//'c.clear()' returns 'void':
    vec1.clear();//erase all element in the container.
    printVector(vec1);


//'c.erase(p)' & 'c.erase(b, e)' remove element(s) using iterator(s), and return an iterator referring to the location after the (last) element that was removed.
    vector<int> vec2 = {3,0,2,3,0,2,1,7};
    vector<int>::iterator iter = vec2.erase( vec2.begin()+1 );
    //remove the second element.
    cout<< *iter <<endl;
    cout<< "the size of vec2: "<<vec2.size() <<endl;
    cout<< "the capacity of vec2: "<<vec2.capacity() <<endl;
    
   
    auto iter2 = vec2.erase(vec2.begin()+1, vec2.end());
    //remove all elements but the first.
    cout<< *iter2 <<endl;//CAUTION, 'iter' is off_the_end iterator.
    
//NOTE: To 'erase' the element in a container will change the 'size', but not reduce the capacity(reverse the space) of vector.    
    cout<< "the size of vec2: "<<vec2.size() <<endl;
    cout<< "the capacity of vec2: "<<vec2.capacity() <<endl;
    
    
    std::cout <<  0 <<std::endl;
    return 0;
}