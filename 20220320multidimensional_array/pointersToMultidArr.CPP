#include<iostream>
#include<string>
#include<iterator>

int main()
{
    char sarr1[2][3] = {'a','b','c','d','e','f'};
    char (*p)[3] = &sarr1[0];
//this statement is equal to " char (*p)[3] = sarr1 " and "auto p = sarr1"; 
    /* '&sarr1[0]' returns the address of three elements in first row,
     * NOTE: 'p' is a pointer which points to "a char_array which contains three elements". 
     */
    
    
//Create a pointer which points to a two_dimensional int array. 
    char (*p1)[2][3] = &sarr1;
    std::cout <<  (*p)[1] <<"\n"
         <<  (*p)[4] <<"\n" 
         <<(*(p+1))[1]<<"\n"// ' *(p+1)' is point to the second row of array, &sarr1[1] 
         <<std::endl;
//we can subscript (*p) to access the elements in the array,'(*p)[4]' is equal to '(*(p+1))[1]'.
    

//Print an two_dimension array by nested For_loop:
    for(auto pa = sarr1; pa != sarr1+2 ; ++pa){ 
        //'pa' is a pointer which points to an array of 3 chars.
       for(auto q = *pa; q != *pa +3 ; ++q){
           /* '*pa' is an array of 3 chars ,'q' is a pointer to individual element of '*pa',
            * for example, in the first iteration  *q = (*pa)[0] ;
            */
           std::cout<< *q << " ";
       }
        std::cout<< std::endl;
    }

//Use 'begin()' and 'end()' functions to clarify the For_loop above:
    for(auto pa = std::begin(sarr1); pa != std::end(sarr1);++pa){
        //'begin(multid_Arr)' will return a pointer which points to an array of ints(1st_dimension). 
        for(auto q = std::begin(*pa); q != std::end(*pa); ++q){
            std::cout << *q << " ";
    /* the variables initialized in For_loop are only work inside this For_loop scope, 
     * after that, it will be freed in memory. 
     */
        }
        std::cout<<std::endl;
    }
    
    //std::cout << *q << std::endl;//ERROR, Pointer'p' is already freed. 
    return 0;
}