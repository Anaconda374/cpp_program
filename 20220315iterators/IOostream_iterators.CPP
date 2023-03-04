#include<iostream>
#include<string>
#include<vector>
#include<sstream>
#include<iterator>
#include "d:\github\cpp_program\cpp_headers\ContainerPrinter.h"


using namespace std;

/*
 Even though the 'stream types' are not containers, there are iterators that can be used with object of the IO types.
    1. 'istream_iterator' reads an input stream;
    2, 'ostream_iterator' reads an output stream.
*
 These iterators treat their corresponding stream as a sequence of elelments of a specified type. Like other types of iterators, we can use the generic algorithms(that takes iostream iterators) to read data from or write data to stream objects.
 */

int main()
{
    vector<string> strVec;
    string str = "hora de almorzar.";
    
//'istream_iterator<type> it_name(stream)'
    //define a stringstream object.
    stringstream strm(str);
    //define a istream_iterator bound to the begin of 'strm'.
    istream_iterator<string> str_it(strm); 
    istream_iterator<string> eof;//define a empty istream_iterator. 
    
    //An iterator bound to a stream is equal to the end iterator once its associated stream hits end-of-file of encounters an IO error.
    while(str_it != eof){
          strVec.push_back(*(str_it++) );//read a stream seperate by 'space' , and push_back each section of stream into the vector.
    }
    std::cout <<  strVec[0] <<"\n"<<std::endl;
    
    //we can also use iostream_iterators to define a range.
    string str2 = "teclear el ordenador";
    stringstream strm2(str2);
    istream_iterator<string> beg(strm2);
    vector<string> strVec2(beg, eof);
    printVector(strVec2);
    
    
//ostream_iterator<type> ot_name(stream, str1): when we create an ostream_iterator, we may optionally provide a second argument that specifies a character string to print following each element. 
    vector<string> strVec3 = {"cuidado","de","romperlo"};
    ostream_iterator<string> out_iter(cout, " ");
    for(auto elem : strVec3){
        *(out_iter++) = elem;//print each element in strVec2 followed by a space using 'cout'.
    }
    
    cout<<"\n";
    
    //we can also use 'copy(1stIter1, 1stIter2, destIter1)' to copy a vector into standard output stream--'cout'.
    ostream_iterator<string> ot(cout, "\n");
    copy(strVec3.begin(), strVec3.end(), ot);
   
    return 0;
}