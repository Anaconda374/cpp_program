#include<iostream>
#include<string>
#include<string>
#include<algorithm>
#include "d:\cpp_program\cpp_headers\ContainerPrinter.h"

using namespace std;
/*
 
 */

int main()
{
//Say we want to eleminate all duplicate words in following vector.
    vector<string> text = {"una", "persona", "de", "unos", "cuarenta", "anos", "de", "una", "campo", "llamade", "cuarenta"};
    printVector(text);
    
//1. 'sort(iter1, iter2)' rearrange the elements in the given range in increment order.
    sort(text.begin(), text.end());
    //after 'sort', the duplicated words are adjacent to each other.
    
//2. 'unique(iter1, iter2)' eliminates the adjacent duplicate entries in the given range so that all unique elements is placed at the first portion of the container, and returns an iterator(or pointer) to one past the range.
    auto end_unique = unique(text.begin(), text.end());
    
//3. '.erase(iter1, iter2)' to truncate the useless elements in the container. since the algorithm can not change the size of the container, after performing 'unique(...)' there will be some garbage elements remained at the end of the contianer.
    text.erase(end_unique, text.end());
    
    printVector(text);//print the text without duplicate words.
    

   
    return 0;
}