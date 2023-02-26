#include<iostream>
#include<string>
#include<list>
#include<vector>
#include "d:\cpp_program\cpp_headers\ContainerPrinter.h"


using namespace std;

/*
Operations that add elements to a sequential container:(not for array, since the size of the container will be changed). 
    Depends on whether the container_type holds the pointer to its back or front, some containers support to append to back, some support to append to front, and some support to append to both front and back.
    The appending element is copied to append to the container, so after operation, subsequent changes to the element in the container have no effect on the original object, and vice versa.
 */

int main()
{
//1.'push_back(...)' for "vector, string, deque, list"(not valid for 'forward_list'):
    char c = 'K';
    string str1 = "Anacs";
    str1.push_back(c);//OK,since string type is a container of 'char's.
    std::cout<< str1 << std::endl;

    //'.emplace_back(...) for list, vector...'
    vector<string> vec1 = {"junio","julio", "augusto"}; 
    vec1.emplace_back("septiembre");//OK, append rvalue to back.
    vec1.emplace_back(str1);//OK, append lvalue to back.
    printVector(vec1);
  
  
//2. 'push_front(...)' for "list, forward_list, deque"(not valid for 'vector' or 'string'):
    
    list<int> lst = {2, 0, 2, 3};
    lst.push_front(2);
    printList(lst);
    
    
//3.'insert(p, n, t)': Inserts 'n' element with value 't' before the element denoted by iterator 'p', and returns a iterator to "the first element inserted"(not the front).

    vector<string>::iterator iter = vec1.insert(vec1.begin(), 3, "mes");//
    cout<< (*iter) <<endl;
    
//'insert(p, b, e)': Inserts the elements from the range denoted by iterator 'b' and 'e'.
    vector<string> vec2 = {"septiembre", "octobre", "noviembre"};
    iter =  vec1.insert(vec1.end(), vec2.begin(), vec2.end());//OK
    cout<< (*iter) <<endl;

//'insert(p, {list constructor})':    
    iter =  vec1.insert(vec1.end(), {"deciembre", "enero", "febrero"});//OK
    cout<< (*iter) <<endl;
    
//NOTE: Operation '.insert(...)' can work for "vector, deque, list, string, forward_list",  Since it uses an iterator to indicate the position for insertion, such that we can insert elements at the beginning of a container even through it do not have a '.push_front()' operation.     
    std::cout << 0 <<std::endl;
    return 0;
}