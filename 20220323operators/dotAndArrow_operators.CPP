#include<iostream>
#include<string>

// ptr->mem == (*ptr).mem

int main()
{
//The arrow operator'->' requires "a pointer operand" and yields "an lvalue."
    std::string s1 = "CJ_Anacs";
    std::string *p = &s1;
    int size = p->size();
    /* 'p' is a pointer to an string object's1'(under the Namespace'std'), the arrow operator is used by a pointer(e.g. p) to call the member functions(e.g. size()) of Class string.
     */
    
    std::cout <<  (*p) <<"\n"
         <<  p->size() <<"\n"
         <<std::endl;
    return 0;
}