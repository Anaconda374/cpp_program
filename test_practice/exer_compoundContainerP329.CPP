#include<iostream>
#include<string>
#include<list>
#include<deque>

using namespace std;

//define a function that print a list of double_end_queues that hold 'int's. 
void printListOfDeque(std::list<deque<int> > lst)
{
   std::list<deque<int> >::iterator iterList;
   for (iterList = lst.begin(); iterList != lst.end(); ++iterList){
        deque <int> :: iterator iterQue;//an iterator for 'deque' object.
        for (iterQue = (*iterList).begin(); 
            iterQue != (*iterList).end(); ++iterQue){
            cout<<*iterQue<<' ';
            
            }
            cout<<endl;
   }
}

int main()
{
//define a list of double_end_queues that hold 'int's.  
    deque<int> que1;
    deque<int> que2;
    que1.push_back(5);
    que1.push_back(5);
    que2.push_back(6);
    que2.push_back(9);
    
    list<deque<int> > setsNums;
    
    
    setsNums.assign({que1, que2});
    printListOfDeque(setsNums);
    
    que2.swap(que1);
    
    setsNums.assign({que1, que2});
    printListOfDeque(setsNums);
    
    
    std::cout <<  0 <<"\n"
         <<  0 <<"\n"
         <<std::endl;
    return 0;
}