#include<iostream>
#include<string>
#include<list>
#include<forward_list>
#include<iterator>
#include "d:\cpp_program\cpp_headers\ContainerPrinter.h"

using namespace std;
/*
Because 'forward_list' is a singly linked-list, to 'insert' or 'erase' in such container, we need to keep track of 2 positions(the precedessor and the targeting one) by using iterator. Such that c++ defined series special operations for 'forward_list'.
 */

int main()
{
//lst.before_begin() & lst.cbefore_begin(): return an iterator denoting the nonexistent element just before the beginning of the list.
    
    forward_list<int> lst1 = {1,4,0,3,0,5};
    forward_list<int>::iterator f_lst = lst1.before_begin();
    
//'lst.insert_after(p, t)' &'lst.insert_after(p, n, t)' returns an interator to the last inserted element: ('n' is a count, 't' is an object) ;     
    int val = 0;
    cout<< *lst1.insert_after(lst1.before_begin(), val) << endl; 
    
//'lst.emplace_after(p, args)'returns an iterator to the new element:
    cout<< *lst1.emplace_after(lst1.before_begin(), 2) << endl;
    //'lst1' becomes {2,0,1,4,0,3,0,5}
    printForward_List(lst1);

//'lst.erase_after(p)' & 'lst.erase_after(b, e)' erase element after iterator, and returns an iterator to the element after the last one deleted.
    cout<< *lst1.erase_after(++lst1.before_begin()) <<endl;
    //erase the second element in 'lst'
    printForward_List(lst1);
 
    std::cout <<  0 <<"\n"
         <<  0 <<"\n"
         <<std::endl;
    return 0;
}