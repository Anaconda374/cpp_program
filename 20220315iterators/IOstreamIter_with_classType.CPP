#include<iostream>
#include<string>
#include<vector>
#include<iterator>
#include "d:\github\cpp_program\cpp_headers\Sales_item.h"

using namespace std;

/*
We can create an 'istream_iterator' for any type that has an iput operator'>>'. Similarly, we can define an 'ostream_iterator' so long as the type has an output operator'<<'.
 */

int main()
{
//we can rewrite a print_sales program of the book store using iostream iterators of class(Sales_item) type.

    //define an iterator to read from standard input.
    istream_iterator<Sales_item> item_iter(cin);
    //define empty iterator to indicate the end of strea.
    istream_iterator<Sales_item> eof;
    
    //define an iterator to write to standard output(for printing) followed by a newline.
    ostream_iterator<Sales_item> out_iter(cout, "\n");
    
    Sales_item sum = *item_iter++;//initialize the sum by 'cin', and increment the iterator'item_iter' to next position.
   
    
    while(item_iter != eof){//call 'cin' again, and check if it's not empty.
        
        if(item_iter->isbn() == sum.isbn()){
            sum += *item_iter++;//if recently sold books is same as the last batch of books, add they together. And increment the iterator.
        }
        else{//otherwise, print the last batch of sales, and overwrite the sum with the new sales.
            out_iter = sum;
            sum = *item_iter++;
        }
    }
    out_iter = sum; //finally, do not forget print the last sales in the input.
    
    return 0;
}