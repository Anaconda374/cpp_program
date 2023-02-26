#include<iostream>
#include<string>

/* Using nested "Range_for" loops to traverse a multidimensional array.
 */
int main()
{
//Assign an int array with incrementing unsigned numbers from 0:
    int ia[2][3] = {0};
    unsigned val = 0;
    for(auto &row : ia)
        for(auto &col : row){
            col = val;
            val++;
        }
    
//print the new assigned array by nested "Range_for":
    for(auto &row: ia) 
        for(auto col: row)
            std::cout<< col <<std::endl;
    /* NOTE: 
        To access a multidimensional array in nested Range_for loops, the loop control variable for all arrays(but the innermost one) must be references.
        In this case, 'row' in outter Range_for loop must defined as a reference, "auto &row: ia" == "auto &row = ia[0]", 'auto'specifier will deduce 'row' as a reference to an array of 3 int elements. 
        Otherwise when the compiler initializes 'row' ,it will convert each first_dimensional arrays of 'ia'(ia[0],ia[1]) as the addresses of their first element, then in this loop, "auto row : ia" == "auto row = ia[0]" ,'auto' specifier will deduce the type of 'row' as 'int*' by default, such that 'row' cannot point to an int array in Range_for loop.  
     */
    return 0;
}