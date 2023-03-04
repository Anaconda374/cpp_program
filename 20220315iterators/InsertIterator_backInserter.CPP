#include<iostream>
#include<string>
#include<iterator>
#include<list>
#include "d:\github\cpp_program\cpp_headers\ContainerPrinter.h"

using namespace std;
/*
 An inserter is an iterator adaptor that takes a container and yields an iterator that 'adds' element to the specified container.
 */

int main()
{
    vector<string> strVec = {"bisabuela", "tia"};//empty vector.
    
//define insert iterators bound to the container 'strVec'.

//1.create an iterator that uses 'insert'. Like 'insert()' function it takes a second argument which is an iterator where to insert the new element.
    auto it = inserter(strVec, strVec.begin());

//2.create an iterator that uses 'push_back(...)'.
    auto it_back = back_inserter(strVec);
    
//3.create an iterator that uses 'push_front(...)'
    // auto it_front = front_inserter(strVec);//ERROR, we can use 'front_iterator' only if the container has 'push_front' operation.
    list<string> strLst = {"vaso", "celular"};
    auto it_front = front_inserter(strLst);
    
    cout<< strVec.size() << endl;
    
//we can assgin a value through the iterator in 2 ways:
    *it = "furgoneta"; // 1st way.
    //this assignment calls '.push_back(...)'. when we assign a  value through an insert iterator, the iterator calls a container operation to add an element at a specific position in the given container. 
    
    it = "guia"; //2nd way. OK, now 'strVec' has 2 elements.
    it_back = "aceite"; //equivalent to 'push_back(...)'.
    cout<< "Size of strVec is "<<strVec.size() << endl;
    printVector(strVec);
    
    
    it_front = "chocolate"; //equivalent to 'push_front(...)'.it_front = "chocolate"; //equivalent to 'push_front(...)'.
    cout<< "Size of strLst is "<<strLst.size() << endl;
    printList(strLst);
    
    

    return 0;
}