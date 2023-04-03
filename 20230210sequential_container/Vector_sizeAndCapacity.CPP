#include<iostream>
#include<string>
#include<vector>

using namespace std;
/*
'vector','string' containers are stored in a bunch of contiguous memory. 
*
'c.size()' and 'c.capacity' are different:
    The containers will allocate extra memory for quick access.
    the size of a container is the number of elements it already holds; its capacity is how many elements it can hold before more space must be allocated. "capacity = size + reserved memory"
 *
 C++11 defined 3 member function to manipulate the 'capacity'.
 */

int main()
{
    vector<string> vec1 = {"autobus", "ventana", "celular","botella"};
    cout<<"size: " <<vec1.size() <<"\n"
    << "capacity: " << vec1.capacity()<< endl;
    
//'.reserve(n)' to allocate space for at least 'n' element.
    vec1.reserve(3); //if 'n' is less than current size, do nothing.
    vec1.reserve(10);
    cout<<"size: " <<vec1.size() <<"\n"
    << "capacity: " << vec1.capacity()<< endl;
    
//'.shrink_to_fit()' request to reduce 'capacity' to equal 'size':
    vec1.shrink_to_fit();
    cout<<"size: " <<vec1.size() <<"\n"
    << "capacity: " << vec1.capacity()<< endl;
    
//the size of 2 dimensional vector:
    vector<vector<string> > twoDimVec;
    twoDimVec.push_back(vec1);
    twoDimVec.push_back(vec1);
    twoDimVec.push_back(vec1);
    cout<<"size of 2 dimensional vector: " <<twoDimVec.size() <<"\n"<< endl;
    return 0;
}