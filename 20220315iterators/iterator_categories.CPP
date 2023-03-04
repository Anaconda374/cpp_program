#include<iostream>
#include<string>
#include<vector>
#include<algorithm>

using namespace std;

/*
 The most foundamental properties of any algorithm is the list of operations it requires from its parameters(normally 'iterators'). Iterators of different containers may have different operations, according to their functionalities, they can be grouped into 5 iterator categories:
 *
 5 iterator categories in 4 levels:
    Level 1: Input iterator -- Read only(but not Write), single-pass(can not set a range manually), increment only(++); ej. 'istream_iterator'.
             Output iterator -- Write only, single-pass, increment only; ej. 'ostream_iterator'.
    Level 2: Forward iterator -- Read and Write, multi-pass, increment only; ej. 'iterator' of Forward_list.
    Level 3: Bidireactional iterator -- Read and Write, multi-pass, increment and decrement; ej. 'iterator' of List.
    Level 4: Random-access iterator -- Read and Write, multi-pass, full iterator arithmetic; ej. 'iterators' of Vector, Deque, array, string.
 *
 These topological iterators form a sort of herarchy, an iterator of a higher level provides all the operations of the iterators of a lower level.
 */


int main()
{
//we can pass a higher level iterator into an algorithm that only requires lower level iterator.
    vector<string> strVec = {"naranja", "gris", "marron", "amarilla"};
    //'find()' requires only forward_iterators, but we can pass higher level iterators to it.
    auto it = find(strVec.begin(), strVec.end(), "gris");
    
    
    std::cout << "the subscription of string in Vector is "
            << it - strVec.begin() <<"\n";
            
    return 0;
}