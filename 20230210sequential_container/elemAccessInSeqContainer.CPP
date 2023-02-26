#include<iostream>
#include<string>
#include<list>
#include<vector>
#include<array>
#include<deque>

using namespace std;
//Operations access the element in a sequential container, and return 'reference'. 

int main()
{
//1.'c.front()' returns a reference to first element:
    vector<string> vec1 = {"primero", "segundo", "tercero"};
    auto& vRef =  vec1.front();//return a reference, 
    vRef = "cambiado";//and we can modify the element by dereference.
    // vRef = vec1.front()++; //ERROR, unlike iterator, reference can not perform arithmetic operations. 
    
//2.'c.back()'(not valid for forward_list):
    auto cpy = vec1.back();//'cpy' is a copy of the last element.
    cpy = "cambiado";//and we cannot change the real element via 'cpy'.
    
    std::cout <<  vec1[0] <<"\n"
         << vec1[2] <<std::endl;
         
//3.subscript'c[]' also returns a reference:
    list<int> lst = {2,0,2,3,0,2,1,7};
    // auto lRef = lst[7];//Error, subscipt operator valid only for 'string', 'vector', 'deque', 'array'.
    
    deque<int> que = {2,0,2,3,0,2,1,7};
    auto& qRef = que[7];//OK.
    qRef = 8;
    cout<< que.back() <<endl;
    
//4.use 'c.at(n)' to avoid out_of_range dereference.
    auto cpy2 = que.at(3);//returns a reference to the element indexed by 3 == que[3];
    
    cpy2 = que.at(9);//ERROR!
//unlike the subscript, if the index is out of range, the '.at()' will terminate the program, and throws an "out_of_range exception". 
    
    cout<< cpy2 <<endl;
    return 0;
}