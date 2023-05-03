#include<iostream>
#include<memory>
#include"D:\cpp_program\cpp_headers\CompanionClasses_StrBlob_StrBlobPtr.h"


int main(){
//Usage of 'StrBlobPtr':
    StrBlob sp({"enero", "febrero", "marzo"});//list_initialization.

    //Use self_defined iterators(StrBlobPtr) to traverse all elements in the vector.
    StrBlobPtr begIter = sp.begin();
    StrBlobPtr endIter = sp.end();
    while(!(begIter == endIter)){
        std::cout<< begIter.deref() <<"\n" <<std::endl;
        begIter.incr();
    }
    return 0;
}