#include<iostream>
#include<string>
#include<iterator>
#include<array>

// 3 ways to print a multidimensional array:
int main()
{
    int ia[3][3] = {1, 3, 5, 7, 9, 11 ,13, 15, 17};
    
//"Range_for":
    for(int(&p)[3] : ia){
        for(int q : p){
            std::cout << q << " ";         
        }
        std::cout << std::endl;
    }
    
//"For_loop" with "subscripts" :
    for(size_t i = 0; i != 3 ;i++){
        for(size_t j = 0 ; j != 3 ; j++)
            std::cout << ia[i][j] << " ";
        std::cout << std::endl;
    }

//"For_loop" with "pointers":
    for(int (*p)[3] = std::begin(ia); p != std::end(ia); p++){
        for(int *q = std::begin(*p); q != std::end(*p); q++){
            std::cout<< *q <<" ";
        }
        std::cout<<std::endl;
    }
    return 0;
}