#include<iostream>
#include<string>
#include<deque>//type 'deque' is defined in library <deque>.

/*
    the deque sequence container although uses vector as its core data structure implementation and can be expanded and contracted(truncated) with insertion and deletion at both ends. 
    They are more efficient than vectors, but unlike vectors, contiguous memory allocation is not guaranteed.

    A queue data structure allows insertion only at the end and deletion from the front. This is like a queue in real life, wherein people are removed from the front and added at the back.
    The ‘deque’ essentially means double-ended-queue and works in a similar fashion as queues; in other words, a FIFO (first-in-first-out) manner. Double ended means that the FIFO can occur at both ends (front and rear). 
 
 */

using namespace std;

void print(deque<int> dq)
{
   deque <int> :: iterator iter;//an iterator for 'deque' object.
   for (iter = dq.begin(); iter != dq.end(); ++iter)
      cout<<*iter<<' ';
   cout<<endl;
}

int main()
{
    deque<int> nums;
//The functions for deque are same as vector, with an addition of push and pop operations for both front and back. 
    nums.push_back(9);
    nums.push_back(10);
    nums.push_front(8);
    //right now, the queue 'nums' shoud be "{8, 9, 10}". 
    cout<<"deque contents"<<endl;
    print(nums);
    
    cout<<"Size = "<<nums.size()<<endl;
   
    cout<<"After popping an element from the front"<<endl;
    nums.pop_front();
    print(nums);
    cout<<"After popping an element from the back"<<endl;
    nums.pop_back();
    cout<< nums.front()<<endl;
    print(nums);
    cout<<"Size = "<<nums.size()<<endl;
    
    std::cout <<  0 <<std::endl;
    return 0;
}