#include<iostream>
#include<string>
#include<vector>
#include<array>
#include<list>

#include "d:\cpp_program\cpp_headers\ContainerPrinter.h"


using namespace std;
/*
 
 */



int main()
{
//assign  member_fucntion(except 'array'):
    vector<int> vec1 = {1, 2, 3};
    list<int> lst = {19, 94, 03, 20};
//1.assign from another container
    // vec1 = lst;//Error, using '=' to assign requires both objects have the same type.
    
    vec1.assign(lst.begin(), lst.end());//OK, assgined by using iterators, and the length of 'vec1' is updated.
    
    vec1.assign({1, 3, 5, 7});//OK, assgined from a initializer list.
    vec1.assign(5, 6);//OK, assgined with five integers '6'.
    
    printVector(vec1);
    
//2.swap member_function: '.swap( )' requires both container and their element types are matched(in the same type).
    array<string, 3> semana1 = {"lunes", "martes", "miercoles"};
    array<string, 3> semana2 = {"jueves", "viernes", "sabado"};
    swap(semana1, semana2);//swap the elements in 2 arraies.
    printArray(semana1.begin(), semana1.end());
    printArray(semana2.begin(), semana2.end());
    
    // vec1.swap(lst); //Error, 'vec1' and 'lst' have different types.
    vector<string> vecStr1 = {"enero", "febrero", "marzo"};
    vector<string> vecStr2 = {"abril", "mayo", "junio"};
    // vec1.swap(vecStr);//ERROR, the element types are different.
    vecStr1.swap(vecStr2);//OK.
    printVector(vecStr1);
    printVector(vecStr2);

/*
NOTE: what 'swap' function actually does is to swap the element memory pointers which bound to those two lvalues/container_names(except for 'array' type), such that it does not copy, delete, or insert any elements, and the sizes of 2 containers are also swaped. 
after the swap, pointers, references, and iterators will be invalidated, since they are still bound to the same elements they denoted before the swap.
And this function is guaranteed to run in constant time O(1).    
*/
    
    std::cout << 0 <<std::endl;
    return 0;
}