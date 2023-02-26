#include<iostream>
#include<string>
#include<stack>
#include<deque>
#include<vector>
#include<queue>//both 'queue' and 'priority_queue' defined in 'queue.h'
//C++ container adaptors defined in corresponding headers under the namespace 'std'.
#include "d:\cpp_program\cpp_headers\ContainerPrinter.h"



using namespace std;

/*
    Instead of defining every data structure by our own, C++ defines various types of sequential containers in library such as 'vector', 'list', 'array', 'deque'...
    In addition to the sequential containers, C++ library defines 3 seuqential container adaptors(each adaptor defines a new interface on top of an underlying sequential container type): 
        1.'stack'(implemented in terms of 'deque');
        2.'queue'(implemented in terms of 'deque');
        2.'priority_queue'(implemented in terms of 'vector'), since it only need to 'pop' on one side.
*
    Each container adaptor defines its own operations in terms of operations provided by underlying container type, and we can use only the adaptor operations and cannot use the operations of the underlying container type. See details on P370 in C++ primer.
 */

void printStack(stack<string, vector<string>> strStk);

int main()
{
//Defining an adaptor: each adaptor defines 2 constructors.
//1.default constructor(create an empty object has the type of the adaptor).
    stack<int> intStk;
    priority_queue<int> intPriQue;
    
    //or we can initialize a stack or queue with its base container 'deque'. 
    deque<int> dq = {1,2,3};
    stack<int> intStk2(dq);//initialize 'intStk' in 'FILO' way.
    printStack(intStk2);
    
//2.use a constructor that takes a container(other than its base container type) and initializes the adaptor by copying the given container.
    vector<string> strVec = {"flor","libros", "sillas"};
    
    // stack<string> strStk1(strVec); //ERROR. 
    stack<string, vector<string>> strStk1(strVec); //OK.
    // strStk1.push_back("movil");//ERROR, can not use the 'vector' members.
/* 
   convert this stack object 'strStk1' implemented on top of 'vector'. 
   NOTE: 'strStk1' has type of 'stack<string, vector<string>>', not 'stack<string>'.
*/
    printStack(strStk1);
    

    return 0;
}

//define a function to print stack type 'stack<string, vector<string>>'
void printStack(stack<string, vector<string>> strStk){
    while(!strStk.empty()){
        cout<< strStk.top() << endl;
        strStk.pop();
    }
}