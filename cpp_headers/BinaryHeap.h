#ifndef BINARY_HEAP_H

#define BINARY_HEAP_H

#include<iostream>
#include<string>
#include<cstdlib>
// Header "stdlib.h" is actually included in "iostream.h"

#define MinHeapSize 5
#define MinData 0 //define the value in position 0. the position 0 in array is not for storing data, it works as a sentinel for insersion operation so that we can insert the minimum value to root(see detail in 'Insert' function ), and its value must be less or equal to the root(position 1). 

/*
'Binary Heap(or Heap)' can be regard as a binary tree data structure, but be implemented by using simple arrays(so that the maximum size of a heap is pre-defined). 
For element in array position 'i', its left child is in position '2i', the right child in '2i+1', and its parent is in 'i/2'  

'Heaps' have 2 properties:
1.Structure property: it is constructed as a complete binary tree, with the possible exception of the bottom level, which is filled from left to right.

2.Order property: the keys in the child nodes are always greater or equal to the keys in the parent node.  
 */

class Heap;
typedef Heap* PriorityQueue;

class Heap{
public:  
    int capacity;
    int size;
    int* dataArray;//a pointer to an array for storing data, and its size is equal to 'capacity'.
  
    Heap(int maxElements){
        capacity = maxElements;
        size = 0;
        dataArray = NULL; 
    }
  
};

PriorityQueue Initialize(int maxElements){
    
    PriorityQueue h;
    if(maxElements < MinHeapSize){
        std::cerr <<"Priority queue size is too small"<<std::endl;
        exit(0);
    }
    h = new Heap(maxElements);
    
    h->dataArray = (int*)malloc((maxElements +1)*sizeof(int));
    
    h->dataArray[0] = MinData;
    return h;
}

bool IsFull(PriorityQueue h){
    return h->size == h->capacity;
}

bool IsEmpty(PriorityQueue h){
    return h->size == 0;
}

void Insert(int key, PriorityQueue h){
    int i;
    if(IsFull(h)){
        std::cerr<<"The heap is full!"<<std::endl;
        exit(0);
    }

//if the value of the parent node is greater than 'key', than assign that value to the target inserting node(firstly the last element), and assign 'key' to the parent node. 
    for(i = ++h->size; h->dataArray[i/2] > key; 
    i = i/2){
        h->dataArray[i] = h->dataArray[i/2];
        //the array implementation of tree is different than the linked list implementation
    }
    h->dataArray[i] = key;
}


void PercolateDown(int hole, PriorityQueue h){
    int lastElement, child;
    if(IsEmpty(h)){
        std::cerr<<"Priority Queue is empty"<<std::endl;
        exit(0);
    }
    lastElement = h->dataArray[h->size--];
    for(; hole*2 <= h->size; hole = child){
        child = hole * 2;
            
        //find the smaller child.
        if(child != h->size && 
        h->dataArray[child+1]<h->dataArray[child]){
            child++;
        }
        
        //if the last element is greater than the hole's child, fill the child to the hole. Otherwise the percolation is finished , fill the last element to hole.
        if(lastElement > h->dataArray[child]){
            h->dataArray[hole] = h->dataArray[child];
        }
        else
            break;
    }
    h->dataArray[hole] = lastElement;
    
}


/*
Since we pop up the root, a hole is created at the root and the heap size becomes one smaller, so that the "last element" in the heap must move somewhere in the heap. So we percolate the hole down by sliding the smaller of the hole's children into the hole, until the last element can be placed in the hole.   
*/
int DeleteMin(PriorityQueue h){
    int minElement;
    if(IsEmpty(h)){
        std::cerr<<"Priority Queue is empty"<<std::endl;
        exit(0);
    }
    minElement = h->dataArray[1];//minumum element is the root.
    PercolateDown(1, h);   
    return minElement;
    
}



#endif