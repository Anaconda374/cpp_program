#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<numeric>

using namespace std;

/*
 
 */

int main()
{
    vector<string> strVec = {"para", "contar", "un", "cuento"};
    int ia[] = {20, 23, 02, 22, 23, 02};
    
//1. 'find(iter1, iter2, val)' algorithm:
    string findVal = "un";
    auto result = find(strVec.begin(), strVec.end(), findVal);
    //'find(...)' returns an iterator to the first element that is equal to that value. If there is no match, it returns its second iterator(parameter) to indicate failure.    
    cout<< "The string \""<< findVal <<"\" " 
    << (result == strVec.end() ? " is not present" : " is present") <<endl;
    
    //We can also look in a subrange of the sequence by passing iterators(or pointers) to the first and one past the last element of the subrange.
    auto result2 = find(strVec.begin(), (strVec.begin() + 2), findVal);
    cout<< "The string \""<< findVal <<"\" " 
    << (result2 == (strVec.begin() + 2) ? 
    " is not present in this subsequence" : 
    " is present in this subsequence") <<endl;    
    
    //'find(...)' also works for arrays.
    int intVal = 24;
    int* findRet  = find(begin(ia), end(ia), intVal);
    //returns a pointer to 'int'.
    cout<< "The integer \""<< intVal <<"\" " 
    << (findRet == end(ia) ? " is not present" : " is present") <<endl;
    

//2. 'count(iter1, iter2, val)' return a count.
    int intVal2 = 22;
    unsigned cnt = count(begin(ia), end(ia), intVal2);
    cout<< "The value " << intVal2 << " appears " << cnt<< " times"<<endl;
  
  
//3. 'accumulate(iter1, iter2, startValue)' returns a summation:
    int startVal = 10;
    int sum = accumulate(begin(ia), end(ia), startVal);
    //add together the sequence of 'int' values with '10'.
    cout<<"the summation of Sequence with base value \"" <<startVal<< "\" is "<< sum <<endl;
    
    //'accumulate(...) also works for 'string' type by concatenating strings using operator '+'.
    string concat = accumulate(strVec.begin(), strVec.end(), string(""));
    //NOTE: we cannot use a string literal "..." as the third argument here. In that way, the type of the object used to hold the sum would be ' const char* ' at beginning, and there is no '+' operator for this type ' const char* '   .
    cout<< concat <<endl;


//4. 'equal(_1stIter1, _1stIter2, _2ndIter1)' to compare 2 sequences:
    string strArr[] = {"para", "contar", "un"};
    
    //we can call 'equal(...) to compare elements in containers of different types as long as their elements are of the same type or convertible types.'
    auto boolRet = equal(begin(strArr), end(strArr), strVec.begin());
    //NOTE:Algorithms that uses a single iterator to denote the second sequence assume that the second sequence is at least as large as the first. If the second sequence is a subset of the first, then our program has a serious error -- 'equal' will attempt to access elements beyond the end of the second sequence.
    
    if(boolRet){
        cout<< "Array 'strArr' is a subsequence or equal to the Vector 'strVec' " <<endl;
    }else{
        cout<< "Array 'strArr' is not a subsequence or equal to the Vector 'strVec' " <<endl;
    }
    
    return 0;
    
}