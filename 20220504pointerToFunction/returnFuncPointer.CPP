#include<iostream>
#include<string>
/* NOTE: Using aliases can simplify "the definition statement of a function which return a funcPointer". But it requires a fully understanding of the conception about 'typedef', and 'how to define a funcPointer'. 
 */
 
 
/* Like arrays, we cannot return a function type but can return a "pointer to a function type". So it's basically used to allow the function to really return another "real function (pointer)",not just a function type.
 */
int test_sum(int v1, int v2){
    return v1 + v2;
}

int test_dif(int v1, int v2){
    return v1 - v2;
}


/* Define a function which returns "a pointer to a function type" and "a pointer to an array" are using the similar syntax, defined from the inside out.
 */
int(*test_func(char v))(int v1, int v2){
    /* 
        This defines a function 'test_func' which take a 'char' as its own parameter and returns a "pointer to a function" that takes 2 'int' objects and returns 1 'int' object.
     * 
        This function receives an argument and return "the corresponding function" depending the argument value.     
     */
    if(v == 's'){
        return test_sum;
    }
    else{
        return test_dif;
    }
}
/* Use 'decltype' or 'auto' keywords to simplify the definition of 'test_func':
 * 
    If we know this function 'test_func' will return one of functions between 'test_sum' and 'test_dif' which have the same function type, we can use the follow code:
 *
 * " decltype(test_sum)* test_func(char v) {...} "
 * " auto test_func(char v) -> int(*)(int , int)" 
 * These two definitions are much simplier and more readable.
 */


int main()
{
    
    char c;
    std::cout << "please input the operation(sum(s)/dif(d)): ";
    std::cin >> c;
    std::cin.clear();
    if (!((c == 's')||(c =='d'))){
        std::cout<< "Invalid Input! "<< std::endl;
        return 0;
    }
    int v1, v2;
    std::cout << "please input two values for calculation: ";
    std::cin >> v1 >> v2;
    std::cin.clear();
    int(*pf)(int , int);
    //Define a pointer_to_function variable to receiver the return from function 'test_func'.
    pf = test_func(c);
    //NOTE: we can use a pointer_to_function to call that function directly. 
    std::cout << pf(v1, v2) 
         <<std::endl;
    return 0;
}