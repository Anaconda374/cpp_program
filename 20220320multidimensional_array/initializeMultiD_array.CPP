#include<iostream>
#include<string>
/* 
   In a two_dimensional array, the first dimension is usually referred to as the row and the second as the column.
 * 
   NOTE: "int arr[2][3]" is totally different from "int arr[6]". 
 */
int main()
{
//Initialize all elments respectively by list initialization:
    int arr[2][3] = {{0,1,2},{3,4,5}};//this is equal to " int arr[2][3] = {0,1,2,3,4,5}"
        std::cout<< arr[1][1]<< std::endl;
    
    
//Initialize all elements to 0: 
    int arr1[3][4] = {0};//we can only use such this initializer to initializing arrays to 0.
        std::cout <<  arr1[2][2] <<std::endl;
        
        
//Initialize only first Element in each row:
    int arr2[3][4] = {{0},{1},{3}};
    std::cout <<  arr2[2][0] << "\n"<< arr2[2][1] <<std::endl;
    //the remaining elements are initialized to 0. 
    

    return 0;
}