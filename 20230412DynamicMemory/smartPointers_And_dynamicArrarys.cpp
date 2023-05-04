#include<iostream>
#include<memory>

int main(){
/*
'unique_ptr' manages dynamic array:
    The library provides a version of 'unique_ptr' that can manage arrays allocated by 'new'. And even support the subscript operation[] to that 'unique_ptr':
*/
    std::unique_ptr<int[]> up;//'up' can point to a dynamically allocated array of 'int' type.

    std::size_t sz = 3;
    std::string* strPtr = new std::string[sz]{"computadora", "silla", "revista"};
    std::unique_ptr<std::string[]> strUp(strPtr); //'strUp' points to the dynamically allocated array to which the built_in Pointer'strPtr' points.

    //Access all elements in the dynamic array using 'unique_ptr':
    for(std::size_t i = 0; i< sz; ++i){
        std::cout<<"NO. " <<i+1 <<" string element which 'unique_ptr' points is: "
        <<strUp[i] << std::endl;
    }

/*
'shared_ptr' with dynamic arrays:
    Unlike 'unique_ptr', 'shared_ptrs' provide no direct support for managing a dynamic array. since 'shared_ptr' using 'delete' to free the object by default, such that if we want to use a 'shared_ptr' to manage a dynamic array, we must provide our own 'deleter' which using "delete [] p ".
*/
    std::shared_ptr<std::string> strSp(new std::string[sz]{"ventana", "flor", "estanteria"}, [](std::string* strPtr){delete [] strPtr;});

    /*
    Access all elements in the dynamic array using 'shared_ptr':
        Since 'shared_ptr' does not have subscript operator and do not supprt pointer arthmetic operation, we have to convert it into built_in pointer before the access.
    */ 
    for(std::size_t i = 0; i < sz; ++i){
        std::cout<<"NO. " <<i+1 <<" string element which 'shared_ptr' points is: "
        <<*(strSp.get() + i) <<std::endl;
    }

    strSp.reset(); //uses the lambda we supplied that uses 'delete[]' to free the array.

    return 0;
}