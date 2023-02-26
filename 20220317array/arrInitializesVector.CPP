#include<iostream>
#include<string>
#include<vector>
/* 
   Although we cannot initialize "a built-in array" from another array nor from a vector, but we can use an array to initialize a vector.
 */

int main()
{
    int ia[] = {0, 1, 3, 5, 7};
/* 
   To do so, we specify the address of the first elment and one past the last element that we wish to copy through "constructing initialization".
 */
    std::vector<int> iv1(std::begin(ia), std::end(ia));//copy the whole Array'ia' into vector'iv1'.
    for(auto i : iv1){
        std::cout << i
             <<std::endl;
    }
    
    std::vector<int> iv2(std::begin(ia), std::begin(ia)+2);//copy the first two elements into 'iv2'.
    for(auto i : iv2){
        std::cout << i
            <<std::endl;
    }
    
// Copy a vector into an array:
    const unsigned si = iv1.size();
    int va[si];
    for(auto i = iv1.begin(); i != iv1.end(); i++){
        va[i-iv1.begin()] = *i;
    }
    std::cout<< va[3] <<std::endl;
    

    return 0;
}