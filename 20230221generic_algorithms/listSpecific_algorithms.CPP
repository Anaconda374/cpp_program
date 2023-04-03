#include<iostream>
#include<string>
#include<vector>
#include<list>
#include<algorithm>
#include "d:\cpp_program\cpp_headers\ContainerPrinter.h"


using namespace std;

/*
  Unlike the other containers, 'list' and 'forward_list' are not stored in consecutive memories. Such that instead of using generic algorithms, the list typs define their own versions(member functions) of 'sort', 'merge', 'remove', 'reverse', and 'unique' algorithms.
 *
  NOTE: the list_specific operations do change the containers, such as "change the size", "destory the already copied list
  , etc.
 */

int main()
{
//the list_specific generic algorithms:
    list<string> lst1 = {"enero", "febrero", "marzo"};
    list<string> lst2 = {"abril", "mayo", "junio"};
    printList(lst1);
    printList(lst2);
    
    //1st1.merge(1st2, optionalComp) merges list 'lst2' into 'lst1', by default, use the '<' operator.
    lst1.merge(lst2);
    printList(lst1);
    
    //after merge list 'lst2' is changes.
    printList(lst2);
    cout<< lst2.size() <<endl;//empty list.
    
//'lst1.splice(begIter, lst2)' splices(concatenates) two lists into one. Thanks to the implementation of 'list' structure, it can have its unique 'splice' member functions.
    list<string> lst3 = {"lunes", "martes", "miercoles"};
    list<string> lst4 = {"jueves", "viernes", "sabado"};
    lst3.splice(lst3.end(), lst4);//first argument is an iterator that denotes the start position in 'lst1' for splicing.
    printList(lst3);
    printList(lst4);//after splice operation,lst4 is emptied.
    
    return 0;
}