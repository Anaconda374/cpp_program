#include<stdio.h>
#include<iostream>
#include<vector>
#include<algorithm>

void printVector(std::vector<int> vec){
    for(auto i : vec){
        std::cout<< i<<std::endl;
    }
}

int main()
{
    std::vector<int> iVec = {1, 2, 3, 5};
    int val =  iVec.back();
    auto it = std::find(iVec.begin(), iVec.end(), 3);
    std::vector<int> vec1(iVec.begin(), iVec.begin());
    std::vector<int> vec2(it+1, iVec.end());
    std::cout<<"vec1 size is: "<<vec1.size()<<std::endl;
 
    printVector(vec1);
    std::cout<<"\n"<<std::endl;
    printVector(vec2);

}
