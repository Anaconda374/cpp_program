#ifndef STACK_H

#define STACK_H

#include<iostream>
#include<string>
#include<cstdlib>




class StackNode{
public:
    char data ;
    StackNode* next;
    
    StackNode(){
        data = ' ';
        next = NULL;
    }
};

bool IsEmpty(StackNode* s){
    return s->next == NULL;
}

void Pop(StackNode* s){
//Delete first node right after the stack head 's'.
    StackNode* firstCell;
    try{
        if(IsEmpty(s)){
            throw "Empty stack.";
        }
        else{
            firstCell = s->next;
            s->next = s->next->next;
            free(firstCell);
        }
    }catch(std::string errMes3){
        std::cerr<<errMes3<<std::endl;
    }
}


StackNode* PopAndTop(StackNode* s){
//Delete first node right after the stack head 's' and return its address.
    StackNode* firstCell;
    StackNode* tmp;
    try{
        if(IsEmpty(s)){
            throw "Empty stack.";
        }
        else{
            tmp = s->next;
            firstCell = s->next;
            s->next = s->next->next;
            free(firstCell);
            
        }
    }catch(std::string errMes3){
        std::cerr<<errMes3<<std::endl;
    }
    return tmp;
}


void PopAndPrintTop(StackNode* s){
//Delete first node right after the stack head 's' and print it.
    StackNode* firstCell;
    try{
        if(IsEmpty(s)){
            throw "Empty stack.";
        }
        else{
            std::cout<< s->next->data <<" ";
            firstCell = s->next;
            s->next = s->next->next;
            free(firstCell);
        }
    }catch(std::string errMes3){
        std::cerr<<errMes3<<std::endl;
    }
}

void MakeEmpty(StackNode* s){
    try{
        if(s==NULL){ 
            throw "Must use function creatStack first.";    
        }
    else{
        while(!IsEmpty(s)){
            Pop(s);
            }
        }
    }catch(std::string errMes1){
        std::cerr<<errMes1<<std::endl;
    }
}


StackNode* CreatStack(){
//'s' is a head node that used as "a reference to a stack" and for 'Push' and 'Pop' operations.  
    StackNode* s;
    s = new StackNode();
    try{
        if(s == NULL){
            throw "Out of space!";
        }
    MakeEmpty(s);
    
    }catch(std::string errMes2){
        std::cerr<<errMes2<<std::endl;
    } 
    return s;
}

void Push(StackNode* s, char x){
//Add a new stack node right after the stack head 's'.
    StackNode* tmpCell;
    tmpCell = new StackNode();
    try{
        if(tmpCell==NULL){
            throw "Out of space!";
        }else{
            tmpCell->data = x;
            tmpCell->next = s->next;
            s->next = tmpCell;
        }
        
    }catch(std::string errMes4){
        std::cerr<<errMes4<<std::endl;
    }
    
}

void Print(StackNode* head){
    StackNode* temp = head->next;
    while(temp != NULL){
        std::cout << temp->data<<" ";
        temp = temp->next;
    }
}

#endif 
