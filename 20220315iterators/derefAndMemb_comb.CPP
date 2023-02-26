#include<iostream>
#include<string>
#include<vector>
#include"d:\cpp_program\cpp_headers\Sales_item.h"
/* 
   When we dereference an iterator, we get the object that the iterator denotes. If that object has a 'class_type', we may want to access a member(or member function) of that object.
 * 
   such as " (*it).empty ".
 */ 

int main()
{
    std::vector<Sales_item> vsale;
    Sales_item item;
/* NOTE:
    when we change the size of a vector(such as push_back) in a loop whilst using 'iterators', this kind of behaviors potentially invalidates all iterators refer to that vector.
 */
    while (std::cin >> item){
        vsale.push_back(item);
    }
//Using '(*is).' to access the member of a class object:
    for (auto is = vsale.begin(); is != vsale.end(); is++){
        std::cout << (*is).isbn() <<" has sold "<< (*is).avg_price() << "$/book"<< std::endl;
    }
    

    return 0;
}