#include<iostream>
#include<string>
#include<list>

/*
 
 */
using namespace std;

int main()
{
    list<int> lst1;
    list<int>::iterator iter1 = lst1.begin(), iter2 = lst1.end();
    
    while(iter1 < iter2){//Invalid! Rational operators only applies for iterators of 'vector' or 'string', but not 'list'. But '==' and '!=' operators work for all types of containers.
        cout<< *iter1 <endl;
        iter1++
    }
    
    
    std::cout <<  0 <<"\n"
         <<  0 <<"\n"
         <<std::endl;
    return 0;
}