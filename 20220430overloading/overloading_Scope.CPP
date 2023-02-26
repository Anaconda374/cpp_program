#include<iostream>
#include<string>
/* For C++ compiler, 'name_lookup' happens before 'type_checking', such that when we declare a name in an inner scope, this inner_name will hide "uses of that name declared in an outer scope" in its own scope. 
This property works the same to 'common_named variables' and 'overloaded functions'.
 */
void print(const std::string cs){
    std::cout << cs <<std::endl;
}

int main()
{   
    void print(int i);
    /* Bad practice for demo: it's a bad idea to declare functions at local scope.
     * After this declaration, the use of the outer_scope defined Function 'void print(const std::string cs)' is hidden.
     */
    print(2);
    
    
    std::cout <<  0 <<"\n"
         <<  0 <<"\n"
         <<std::endl;
    return 0;
}

void print(int i){
    std::cout << i <<std::endl;
}