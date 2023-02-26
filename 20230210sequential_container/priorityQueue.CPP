#include<iostream>
#include<string>
#include<queue>
#include<array>
#include "d:\cpp_program\cpp_headers\ContainerPrinter.h"

/*
    A C++ priority queue is a type of container adapter, specifically designed such that the first element of the queue is either the greatest or the smallest of all elements in the queue, and elements are in non-increasing or non-decreasing order.
 *  
    In C++ STL, priority queues are built on the top of the max heap and use an array or vector as an internal structure, that is saying the top element is always the greatest by default. But we can also change it to the smallest element at the top by pasa a comparator as an additional parameter.  
 */

void printPriorityQueue(std::priority_queue<int,std::vector<int>, 
                            std::greater<int>>  pq);

int main()
{
    
    std::array<int, 6> arr = {1,9,8,6,0,2};
    
//1.Default constructor forms a max_heap by default:
    std::priority_queue<int> pq;
    for(auto i : arr){
        pq.push(i);
        // priority queue only can be initialized by '.push(...)'.
    }
    printPriorityQueue(pq);
    
// 2.Forms a min_heap by passing a comparator:
    std::priority_queue<int,std::vector<int>, std::greater<int>> pq2;
    for(auto j : arr){
        pq2.push(j);
    }
    printPriorityQueue(pq2);//OK!
    
   
// 3.use custom_defined comparator as a parameter.
    //use 'lambda' function to define a greater comparator:
    auto cmp = [](int a, int b) {return a>b;};//return 'true' if 'a>b'
    std::priority_queue<int, std::vector<int>, decltype(cmp)> pq3(cmp);
    //Before C++20 we need to pass lambda as argument to set constructor.
    for(auto k : arr){
        pq3.push(k);
    }
    while(!pq3.empty()){
        cout<< pq3.top() <<endl;
        pq3.pop();
    }
    
    return 0;
}


//define print function for that special type of priority queue.
void printPriorityQueue(std::priority_queue<int,std::vector<int>, 
                            std::greater<int>>  pq){
    while(!pq.empty()){
        cout<< pq.top() <<endl;
        pq.pop();
    }
}