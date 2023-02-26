#include<iostream>
#include<string>
#include"D:\cpp_program\cpp_headers\BinaryTree.h"
/*
 
 */

int main()
{
    TreeNode root('R');
    TreeNode left('l');
    TreeNode right('r');
    tree ptr;
    ptr = MergeTrees(&left, &right);
    ptr->data = 'R';
    
    std::cout <<  ptr->left->data <<"\n"
         <<  right.parent->data <<"\n"
         <<std::endl;
    return 0;
}