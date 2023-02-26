#ifndef STACK_OF_BINARYTREE_H

#define STACK_OF_BINARYTREE_H

#include<iostream>
#include<string>
#include<cstdlib>
#include"D:\cpp_program\cpp_headers\BinaryTree.h"

class StackBT;
typedef StackBT* ptrToNode; 
typedef ptrToNode stackHead;

class StackBT{
public:
    class TreeNode* root;
    ptrToNode next;
 
    StackBT(){
        root = nullptr;
        next = NULL;
    }
    
void Push(tree r);
void Pop();
bool IsEmpty();
void MakeEmpty();
ptrToNode PopAndTop();

};


void StackBT::Push(tree r){
//Add a new stack node right after the stack head 's'.
    ptrToNode tmpCell;
    tmpCell = new StackBT();
    try{
        if(tmpCell==NULL){
            throw "Error4!";
        }else{
            tmpCell->root = r;
            tmpCell->next = this->next;
            this->next = tmpCell;
        }
        
    }catch(std::string errMes4){
        std::cerr<<errMes4<<"Out of space!"<<std::endl;
    }
    
}


void StackBT::Pop(){
//Delete first node right after the stack head 's'。
    ptrToNode firstTree;
    try{
        if(this->IsEmpty()){
            throw "Error3";
        }
        else{
            firstTree = this->next;
            this->next = this->next->next;
            free(firstTree);
            
        }
    }catch(std::string errMes3){
        std::cerr<<errMes3<<"Empty stack."<<std::endl;
    }
}


bool StackBT::IsEmpty(){
    return this->next == NULL;
}


void StackBT::MakeEmpty(){
    try{
        if(this==NULL){ 
            throw "Error1";    
        }
    else{
        while(!this->IsEmpty()){
            this->Pop();
            }
        }
    }catch(std::string errMes1){
        std::cerr<<errMes1<<"Must use function creatStack first."<<std::endl;
    }
}


stackHead CreateStack(){
//'s' is a head node that used as "a reference to a stack" and for 'Push' and 'Pop' operations.  
    stackHead s;
    s = new StackBT();
    try{
        if(s == NULL){
            throw "Error2!";
        }
    s->MakeEmpty();
    
    }catch(std::string errMes2){
        std::cerr<<errMes2<<"Out of space!"<<std::endl;
    } 
    return s;
}


ptrToNode StackBT::PopAndTop(){
//Delete first node right after the stack head 's' and return its address.
    ptrToNode firstTree;
    try{
        if(this->IsEmpty()){
            throw "Error3";
        }
        else{
            firstTree = this->next;
            this->next = this->next->next;

            
        }
    }catch(std::string errMes3){
        std::cerr<<errMes3<<"Empty stack."<<std::endl;
    }
    return firstTree;
}

#endif