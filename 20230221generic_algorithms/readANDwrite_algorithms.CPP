#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<numeric>
#include "d:\cpp_program\cpp_headers\ContainerPrinter.h"


using namespace std;

/*
Since the algorithms do not change the size of a container, so we must take care to ensure that the sequence into which we are going to writes is as least as large as the number of elements we ask the algorithm to write. 
 */

int main()
{
    vector<string> strVec = {"lunes", "martes", "miercoles"};
    
//1.'fill(iter1, iter2, value)' reset each element in range with given value:
    fill(strVec.begin(), strVec.end(), "cambiada");
    printVector(strVec);
    

//2.'fill_n(iter1, n, value)' reset 'n' elements in the container start from 'iter' with 'value'.
    fill_n(strVec.begin(), strVec.size(), "fieras");
    printVector(strVec);
    /*Caution: Algorithms do not check write operations, since algorithm can not change the size of the container, if second argument 'n' inputted is larger than the number of the elements that we can modify, then the result is undefined, and will cause a "Disaster"(break down). 
    *
    To ensure that an algorithm has enough elements to hold the output is to use an 'insert_iterator' which can used to change the size of the container.
    */
    
//3.'copy(1stIter1, 1stIter2, destIter1)' takes 3 iterators to copy the range of 1st_container to 2nd_container, and return an iterator(or pointer for 'array') which points just past the last element copied into 2nd_container.
    vector<string> strVec2(4, "vacio");
    auto ret = copy(strVec.begin(), strVec.end(), strVec2.begin());
    //NOTE: the destination is passed to 'copy' should be at least as large as the input range.
    cout<< strVec2[2]<<" "<<*ret << endl;
 

//4.'replace(iter1, iter2, originalValue, newValue)' replace the origialValue with the newValue within a given range.
    int iarr[] = {2,0,2,3,0,2,2,3};
    printArray(begin(iarr), end(iarr));
    replace(begin(iarr), end(iarr), 2, -1);
    //replace all '2's in 'iarr' with '-1'.
    printArray(begin(iarr), end(iarr));
    
                               
//5.'replace_copy(1stIter1, 1stIter2, destIter1, origialValue, newValue)' is compound function which firstly copy the elements into destination container, and replace the originalValue in new copied elements(others elements in destination not included.). 
    int iarr2[10]={0};
    printArray(begin(iarr2), end(iarr2));
    replace_copy(begin(iarr), (begin(iarr)+4), begin(iarr2), 0, -1);
    printArray(begin(iarr2), end(iarr2));

    return 0;
}