#include<iostream>
#include<string>
#include<initializer_list> 
//'initializer_list' is defined in Header<initializer_list>, under Namespace'std'.

/* Def.: 'initializer_list' is a template type(like 'vector'), which used to initialize a variable with a list of type_specified const values(if not, the value will be converted into const value implicitly), so that to protect the value of the elements of an  initializer_list from changing.
 */

int main()
{
    auto il = {2,4,6}; //'il' has the type 'initializer_list'.
    /* Objects of 'initializer_list' can be automatically constructed by the compiler from initialization list declarations, which is a list of comma-separated elements enclosed in braces, this is why the type is named 'initializer_list'. 
     */
    
    int i = 3;
    std::initializer_list<int> il2{1, i, 5};
    /* The initializer_list object refers to the elements of this array without containing them: copying an initializer_list object produces another object referring to the same underlying elements, not to new copies of them (reference semantics).
     */
    
    std::cout <<  *(il2.begin()+1) <<std::endl;
    /* In order to access the member of an 'initializer_list' object, we need to dereference the iterator which returnd by functions '.begin()' or '.end()'. 
     */
    
    return 0;
}