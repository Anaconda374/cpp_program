#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include "d:\cpp_program\cpp_headers\ContainerPrinter.h"


using namespace std;

/*
Precidate:
    Those comparing algorithms have their default ways to process(or compare) elements, such as < operator for 'sort',  == for 'equal'. But the library also defines versions of these algorithms that let us supply our own comparing operation(using a predicate which returns bool value), so that we can sort a sequence into a different order, or sort elements of a class type(such as Sales_data) which does not have '<' operator.
    
 */

//define a binary predicate(comparison function) to sort strings by length.
bool isShorter(const string& s1, const string& s2){
    return s1.size() < s2.size();
}

//define a unary predicate to check whether a string contains five chars or more. 
bool isLongStr(const string s1){
    return ( s1.size()>= 6 );
}


int main()
{
    vector<string> meses = {"enero", "febrero", "marzo", "abril", "mayo", "junio", "julio", "augusto"};
    
//1.'sort(iter1, iter2, compareFunc)'sort on word length, shortest to longest, the default alphabetical sort feature is discarded in this predicate.
    sort(meses.begin(), meses.end(), isShorter);
    printVector(meses);
    
    
    //use 'sort(iter1, iter2)' and 'stable_sort(iter1, iter2, compareFunc)' to preserve the default sort feature.
    sort(meses.begin(), meses.end());
    stable_sort(meses.begin(), meses.end(), isShorter);
    //after 'stable_sort', the sequence is still in a shortest to longest order, but those adjacent strings which have the same length are also in alphabetic order.  
    
    printVector(meses);


//2.'partition(iter1, iter2, compareFunc)' according to the predicate(unary) to divide a sequence into 2 parts, first part of those elements to which the predicate returns 'True', and the second part elements to which the predicate returns 'False'. And it returns an iterator just past the last element of first part. 
    
    auto iter = partition(meses.begin(), meses.end(), isLongStr);
    cout<<"\n"<< "print all words longer than 6 : "<<endl;
    for(auto i = meses.begin(); i!=iter; i++ ){
        cout<< *i<<" ";
    }
    cout<<endl;

    return 0;
}