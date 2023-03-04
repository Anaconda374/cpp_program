#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include "d:\github\cpp_program\cpp_headers\ContainerPrinter.h"

using namespace std;

/*
 A reverse iterator is an iterator has the inverse order to the normal iterator, it traverses a container backward.
*
 4 reverse iterators in C++:
    > 'vec.rbegin()' or 'vec.crbegin()', point to the last element.
    > 'vec.rend()' or 'vec.crend()', point to the off-begin element.
 *
 NOTE: Reverse iterators require decrement operators:
    We cannot create a reverse iterator from a 'forward_list' or a 'stream'.
    The purpose of a reverse iteraotor is to move the iterator backward through the sequence. Aside from 'forward_list', the iterators on the standard containers all support decrements as well as increment. However , stream iterator do not, since it's not possible to move backward through a stream.
    
 */

int main()
{
    vector<string> strVec = {"tarjeta", "termo", "calor"};
//using reverse iterator to print backwards:
    for(auto iter = strVec.rbegin(); iter != strVec.rend(); iter++ ){
        cout<< *iter<< endl;
    }
    
//using reverse iterator to inverse the function of algorithms:
    vector<int> iVec = {2,9,60,2,53,13,03};
    
    //the increment'+' and decrement'-' operators for reverse_iterators moves opposite direction to the normal iterators. 
    cout<< *(iVec.rbegin()+2) << endl;
    
    //sort in normal order:
    sort(iVec.begin(), iVec.end());
    printVector(iVec);
    
    //sort in reverse order:
    sort(iVec.rbegin(), iVec.rend());
    printVector(iVec);
    
 
    
//'rIter.base()' used to convert 'this' reverse iterator into a normal iterator.
    auto rIter = iVec.rend();//'rIter' is a reverse_iterator points to off-begin element(unreal).
    
    //'rIter.base()' transforms the reverse_iterator into normal, and it's bound to the element one past the original element which 'rIter' points to.
    for(auto iter = rIter.base(); iter != iVec.end(); iter++ ){
        cout<< *iter<< " ";
    }
    
    
    return 0;
}