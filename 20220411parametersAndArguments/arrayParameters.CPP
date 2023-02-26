#include<iostream>
#include<string>
/* 
    Since we cannot copy an array, and when we use an array it is usually converted to a pointer, such that when we pass an array to a function, we are actually passing a pointer to the array's first element. 
    By this transfering mechanism, when functions take array_parameters, arrays are passed as pointers, functions ordinarily do not know the size of the array they are given. To ensure that all uses of the array in functions stay within the array bounds must rely on additional information provided by the caller.
 */

/* 1.Using a marker to specify the extent of an array:
    This approach requires the array itself to contain an end marker. e.g. C_style character string(stored in character arrays) with last character followed by a null'\0'.
 */   
void print_charArr(const char *cp){
    if(cp){
        while(*cp){
            std::cout<< *cp++ <<std::endl;
        }
    }
        
} 
 
/* 2.Using std library to pass pointers to the first and one past the last element in the array:
   Some types of arrays do not have "the null character" such as "int arr[]", so we pass two arguments to specify the extent of the array by using 'begin()' and 'end()' functions. 
 */
void print_intArr(const int * beg , const int * end)
/* Like "reference parameters", if a function does not need write access to the array elements, the "pointer parameters" should be 'const'.
 */
{
    while(beg != end){
        std::cout<<*beg++<< std::endl;
    }
}

/* 3.Using 'Reference_to_Array'(or 'pointer_to_Array') as the parameter:
    In this way we can specify the size of the argument array, and it is safe to rely on this dimension in the function. 
 */
void print_doubleArr (double (&arr)[5]){
    for(double elem : arr){
        std::cout << elem << std::endl;
    }
} 


int main()
{
//Call Function_1:
    char c_arr[6] = "hello";
    print_charArr(c_arr);
    std::cout<<std::endl;

//Call Function_2:
    int i_arr[] = {0, 2, 4, 6, 8};
    print_intArr(std::begin(i_arr), std::end(i_arr));
    std::cout<<std::endl;
    
//Call Function_3:
    double d_arr[] = {1, 2.71, 3.14, 4, 5};
    /* Since the parameter of function is already defined as 'double(&)[5]', we may call
     * this funtion only for an array of exactly 5 doubles.
     */
    print_doubleArr(d_arr);
    
    return 0;
}


