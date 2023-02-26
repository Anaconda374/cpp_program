#include<iostream>
#include<string>
#include"D:\cpp_program\cpp_headers\StackOfBinaryTree.h"
/*
 
 */


int main()
{
    StackBT* sbt = CreateStack();
    tree right = CreateTree('r');
    tree left = CreateTree('L');
    (*sbt).Push(left);
    sbt->Push(right);
    sbt->Pop();
    
    
    std::cout <<  sbt->PopAndTop()->root->data <<"\n"
         <<  sbt->PopAndTop() <<"\n"
         <<std::endl;
    return 0;
}