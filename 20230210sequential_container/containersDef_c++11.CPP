#include<iostream>
#include<string>
#include <array>
#include <vector>
#include <deque>
#include <forward_list>
#include <list>

/*
 "c++ 11" standard released the new library containers(vector, deque, list, forward_list, array, string), and they defined in different manners from which in 'C language'. 
 */

int main()
{
//Type 'string':
    std::string str1 = "kuan";
    
//Type 'array':
    std::array<int, 4> arr1 = {1, 2, 3 ,4};

//Type 'vector':
    std::vector<int> vec1;
    
//Type 'double_ended queue':
    std::deque<int> deq1;

//Type 'singly linked list/forward list':
    std::forward_list<int> singly_list1;
    
//Type 'doubly linked list':
    std::list<int> doubly_list2;

  
    
    
    std::cout <<  0 <<"\n"
         <<  0 <<"\n"
         <<std::endl;
    return 0;
}