#ifndef CONTAINER_PRINTER_H

#define CONTAINER_PRINTER_H

#include<iostream>
#include<string>
#include<vector>
#include<list>
#include<forward_list>
#include<deque>
#include<iterator>
#include<stack>
#include<queue>

using namespace std;


//print containers with string elements.
void printList(std::list<std::string> lst)
{
   std::list <std::string>::iterator iter;
   for (iter = lst.begin(); iter != lst.end(); ++iter){
        std::cout<<*iter<<' ';
   }
   cout<<endl;
}

void printForward_List(std::forward_list<string> lst){
   std::forward_list<string>::iterator iter;
   for (iter = lst.begin(); iter != lst.end(); ++iter){
        std::cout<<*iter<<' ';
   }
   cout<<endl;
}

void printVector(vector<string> vec){    
    vector<string>::iterator iter;
    for(iter = vec.begin(); iter!= vec.end(); ++iter){
        std::cout<<*iter<<' '; 
    }
    cout<<endl;
}

void printDeque(deque<string> dq){
   deque <string> :: iterator iter;//an iterator for 'deque' object.
   for (iter = dq.begin(); iter != dq.end(); ++iter)
      cout<<*iter<<' ';
   cout<<endl;
}

//when print an array, we need to pass 2 parameters to indicate its range. 
void printArray(string* beg, string* end){
    while(beg != end){
        std::cout<<*beg++<<" ";
    }
    cout<<endl;
}

void printStack(stack<string> strStk){
    while(!strStk.empty()){
        cout<< strStk.top() << endl;
        strStk.pop();
    }
}

//print containers with integer elements.
void printArray(int* beg, int* end){
    while(beg != end){
        std::cout<<*beg++<<" ";
    }
    cout<<endl;
}

void printList(std::list<int> lst){
   std::list <int>::iterator iter;
   for (iter = lst.begin(); iter != lst.end(); ++iter){
        std::cout<<*iter<<' ';
   }
   cout<<endl;
}

void printForward_List(std::forward_list<int> lst){
   std::forward_list<int>::iterator iter;
   for (iter = lst.begin(); iter != lst.end(); ++iter){
        std::cout<<*iter<<' ';
   }
   cout<<endl;
}

void printVector(vector<int> vec){
    
    vector<int>::iterator iter;
    for(iter = vec.begin(); iter!= vec.end(); ++iter){
        std::cout<<*iter<<' '; 
    }
    cout<<endl;
}

void printDeque(deque<int> dq)
{
   deque <int> :: iterator iter;//an iterator for 'deque' object.
   for (iter = dq.begin(); iter != dq.end(); ++iter)
      cout<<*iter<<' ';
   cout<<endl;
}

void printStack(stack<int> intStk){
    while(!intStk.empty()){
        cout<< intStk.top() << endl;
        intStk.pop();
    }
}

void printPriorityQueue(priority_queue<int> pq){
    while(!pq.empty()){
        cout<< pq.top() <<endl;
        pq.pop();
    }
}


#endif