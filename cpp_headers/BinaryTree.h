#ifndef BINARY_TREE_H

#define BINARY_TREE_H


#include<iostream>
#include<string>

//define alias of types:
class TreeNode;
typedef TreeNode* ptrToTree;
typedef ptrToTree tree;


//definition of tree ADT:
class TreeNode{
public:
    char data;
    tree parent;
    tree left;
    tree right;
    
//define constructors:
    TreeNode(){
        data = ' ';
        parent = nullptr;
        left = nullptr;
        right = nullptr;
    }
    TreeNode(char d){
        data = d;
        parent = nullptr;
        left = nullptr;
        right = nullptr;
    }
    
//define member fucntions:
    char getData(){ return this->data;}
    
    ptrToTree getLeft(){ return this->left;}
    
    ptrToTree getRight(){ return this->right;}
    
    void setData(char d){
        this->data = d;
    }
    
    void setLeft(ptrToTree l){
        this->left = l;
        l->parent = this;
    }
    
    void setRight(ptrToTree r){
        this->right = r;
        r->parent = this;
    }
    
    void addSubTree(tree sub){
        try{
            if(this->left != nullptr && this -> right != nullptr){
                throw "Error:";
            }
            else if(this->left == nullptr){
                setLeft(sub);
            }
            else{
                setRight(sub);
            }
        }catch(std::string errMes){
            std::cerr<<errMes
            <<"The binary tree is full, add failed"<<std::endl;
            
        }
    }


//declarations of non-member functions:
friend tree CreateTree(char data);    
friend tree MergeTrees(tree a , tree b);
friend tree MergeLeaves(char& a , char& b);
};


//definitions of non-member functions:
tree CreateTree(char data){
    tree newtree = new TreeNode(data);
    return newtree;
}


tree MergeTrees(tree a , tree b){
    tree newtree = new TreeNode();
    newtree->setLeft(a);
    newtree->setRight(b);
    return newtree;
}


tree MergeLeaves(char& a , char& b){
    tree subLeft = new TreeNode(a);
    tree subRight = new TreeNode(b);
    tree newtree = new TreeNode();
    newtree->setRight(subRight);
    newtree->setLeft(subLeft);

    return newtree;
}


void PrintInorder(ptrToTree node){
    if(node == nullptr){
        return;
    }
    PrintInorder(node->left);
    
    std::cout<<node->data<<" ";
    
    PrintInorder(node->right);
}


#endif