#include<iostream>
#include<string>


int& getElem(int *arr, int index){
    return arr[index];
    /* OK, since the array is passed as a pointer to this function, so 'arr[index]' is 
     * a lvalue.
     */
}
int main()
{
    int ia[10];
    for(int i = 0; i != 10; ++i){
        getElem(ia, i) = i;
    }
    
    for(auto elem : ia){
        std::cout << elem << std::endl;
    }
    return 0;
}