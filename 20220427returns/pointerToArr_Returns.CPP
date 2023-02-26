#include<iostream>
#include<string>
#include<iterator>
/* 
   Because we cannot copy an array, so a function also cannot return an array. But a function can return a pointer or a reference to an array.
 * 
 There are generally 4 ways to define such kind of functions:
 */
//1. Normal definition of "a funtion that returns an pointer to an array":
int (*func1(int v1))[3]{
    static int arr1[3];
    /* 
    since to return a pointer to a local variable is undefined, so we would have to define the local variable as static variable, it gets allocated for the lifetime of the program.
     */
     
    //static int arr[3] = {i, i*2 , i*3}
    /* ERROR, if we define a static variable in the function and initialize it at its definition, when we call this function at second time, it will not allocate new memory for this variable, nor to change the value it holds.     
     */     

    //The correct statement to change the values in this static array. 
    for(auto i = std::begin(arr1); i != std::end(arr1); ++i){
        arr1[i - std::begin(arr1)] = v1 + v1*(i - std::begin(arr1));
    }
    return &arr1;
}

//2.Using 'decltype'(similar idea with the Method_1 above):
int _3tupleArr[3];
decltype(_3tupleArr) *declFunc(int val){
    static int array[3];
    for(auto i = std::begin(array); i != std::end(array); ++i){
        array[i - std::begin(array)] = val + val*(i - std::begin(array));
    }
    return &array;
} 

//3. Simplifing the declaration of the function by "a type alias":
typedef int arrT[3]; //equivalent to "using arrT = int[3]".
arrT* func2(int v2){ //perform the same function as 'func1'.
    static int arr2[3];
       
    for(auto i = std::begin(arr2); i != std::end(arr2); ++i){
        arr2[i - std::begin(arr2)] = v2 + v2*(i - std::begin(arr2));
    }
    return &arr2;
}

/*4.Using a Trailing Return Type(under c++11 standard):
 * Trailing returns can be defined for any function, but are most useful for functions with complicated return types, such as a pointer(or reference) to an arrays.
 */
auto func3(int v3) -> int (*)[3]{
    /* A "trailing return type" follows the parameter list and is preceded by an arrow '->', and in order to signal that the return type follows the parameter list, we use 'auto' specifier at where the return type ordinary appears.
     */
    static int arr3[3];
       
    for(auto i = std::begin(arr3); i != std::end(arr3); ++i){
        arr3[i - std::begin(arr3)] = v3 + v3*(i - std::begin(arr3));
    }
    return &arr3;
}




int main()
{
    int (*parr)[3] = func1(6);
//Copy "the values in the array returned by the function via a pointer" into a new array. 
    int iarr[3];
    for(auto i = std::begin(*parr); i != std::end(*parr); ++i){
        iarr[i - std::begin(*parr)] = *i;
    }
    std::cout<< iarr[2] << std::endl;
    
//Output "the new values in that array" using Range_for.      
    for (auto elem : *func1(8)){ 
        std::cout << elem << std::endl;
    }    
    
    
    for (auto elem : *func2(5)){ 
        std::cout << elem << std::endl;
    }
    
    for(auto elem : * declFunc(9)){
        std::cout << elem <<std::endl;
    }
    
    for(auto elem : * func3(10)){
        std::cout << elem <<std::endl;
    }
    return 0;
}