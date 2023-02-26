#include<iostream>
#include<string>
#include<iterator>
#include "d:\cpp_program\cpp_headers\ContainerPrinter.h"

using namespace std;
/*
 
 */

int main()
{
    vector<string> strVec;//empty vector.
    
//define an insert iterator bound to the container 'strVec'.
    auto it = back_inserter(strVec);
    *it = "furgoneta"; 
    //we can assgin through that iterator, this assignment calls //'.push_back(...)' to add an element with the given value to the //container.
    *it = "guia"; //now 'strVec' has 2 elements.
    printVector(strVec);
    
    
    
    std::cout <<  0 <<"\n"
         <<  0 <<"\n"
         <<std::endl;
    return 0;
}