#include<iostream>
#include<string>
#include<vector>
#include "d:\cpp_program\cpp_headers\ContainerPrinter.h"
#include "d:\cpp_program\cpp_headers\BinaryTree.h"

using namespace std;
/*
 except 'array', we can use '.resize(...)' to make a container larger or smaller.
 */

int main()
{
//'.resize(count, valure)':
    vector<int> vec1 = {2,0,2,3,0,2,1,8};
    vec1.resize(10, 3);
    //extend the size of 'vec1' to 10, use '3' to initialize the two new elements. 
    printVector(vec1);
    
//'.resize(count)':
    vector<TreeNode> bosque;
    bosque.resize(5);
    //if the container holds elements of a class type and resize adds elements, we must supply and initializer or the element type must have a default constructor.
    TreeNode tree('a');
    bosque.resize(10, tree);//initialized class object append to back.

    
    std::cout <<  bosque[4].data <<"\n"
         <<  bosque[5].data <<"\n"
         <<std::endl;
    return 0;
}