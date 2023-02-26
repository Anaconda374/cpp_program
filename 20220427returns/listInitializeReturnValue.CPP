#include<iostream>
#include<string>
#include<vector>
//list initializing a vector_type return.

 std::vector<int> printDouble(int v1, int v2){
    
    return {v1*2, v2*2};
    /* This function returns "a temporary vector which is list_initialized."
     */
}

int main()
{
    std::vector<int> retVector = printDouble(2, 6);
     for( auto elem : retVector){
             std::cout << elem <<"\n";
     }
     std::cout << retVector[1] << std::endl;
     // vector 'retVector' is accessible.

    return 0;
}