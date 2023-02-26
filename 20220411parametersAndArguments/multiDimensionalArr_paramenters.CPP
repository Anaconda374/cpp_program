#include<iostream>
#include<string>
/* 
   Recall that "a multidimensional array is just an array of arrays". As with any array, a multidimensional array is passed as a pointer to its first element, that is an array, so the pointer is a pointer to an array, and the size of the second dimension is part of the element type and must be specified. 
 */

void print_multiArr(int matrix[][3], int rowSize){
    for(int i = 0; i!= rowSize; ++i){
        for (auto elem : matrix[i]){
            std::cout <<elem << std::endl;
        }
    }
    
}
int main()
{
    int i_multiArr [][3]{{1, 2, 3}, {3, 4, 5}};
    print_multiArr(i_multiArr, 2);//take a multidimensional array as a argument.
    /* the size of the second dimension is also part of the element type , so it must be specified.
     */
    
 
    return 0;
}
