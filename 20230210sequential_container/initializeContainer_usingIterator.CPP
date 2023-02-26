#include<iostream>
#include<string>
#include<list>
#include<vector>
#include<deque>

using namespace std;


/*
Container initialization
1.List initialization:
    using curly braces.
    
2.Copy initialization:
    To copy a container to another container directly, "the types of two container and their elements" must match. 

3.Iterator initialization:
    c++ allows us to pass two iterators(denote the range) of a container to initialize another container. 
    In this way, the containers types are not required to be identical, and the element types in the new and original containers can differ as loong as it is possible to convert the elements' type. 
    
4.Initialization using size-related constructors:
    Similar with associative containers(ej. array...), we can also initialize the sequential containers(other than array) from a size and an (optional) element initializer.
 */
 
void printList(std::list<std::string> lst);
void printVector(vector<string> vec);
void printDeque(deque<string> dq);


int main()
{
//list initialization
    list<string> lstModo = {"me ", "llamo ", "kuan."};
    vector<const char*> vecModo= {"se", "llama", "chiqui."};
    
//Iterator initialization    
 // vector<string> vec1(vecModo);//Error. Element types not match.
    vector<string> vec1(vecModo.begin(), vecModo.end());//Ok;
    printVector(vec1);
    
    deque<string> que1(lstModo.begin(), lstModo.end());
    printDeque(que1);
    
//size-related constructor initialization
    vector<string> vec2(3, "zen");
    std::cout <<  vec2[2] <<std::endl;
    return 0;
}


void printList(std::list<std::string> lst)
{
   std::list <std::string>::iterator iter;
   for (iter = lst.begin(); iter != lst.end(); ++iter){
        std::cout<<*iter<<' ';
   }
   cout<<endl;
}


void printVector(vector<string> vec){
    
    vector<string>::iterator iter;
    for(iter = vec.begin(); iter!= vec.end(); ++iter){
        std::cout<<*iter<<' '; 
    }
    cout<<endl;
}

void printDeque(deque<string> dq)
{
   deque <string> :: iterator iter;//an iterator for 'deque' object.
   for (iter = dq.begin(); iter != dq.end(); ++iter)
      cout<<*iter<<' ';
   cout<<endl;
}