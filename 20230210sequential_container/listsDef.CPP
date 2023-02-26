#include<iostream>
#include<string>
#include<list>



/*
    
 */


void print(std::list<int> lst)
{
   std::list <int>::iterator iter;
   for (iter = lst.begin(); iter != lst.end(); ++iter){
        std::cout<<*iter<<' '<<std::endl;
   }
}

int main()
{
    std::list<int> nums;
    
    nums.assign({1, 2, 3, 4});
    
    std::cout<<"list contents"<<std::endl;
    print(nums);
    nums.merge({11,22,33,44});
    std::cout<<"After merging new element in the list"<<std::endl;
    print(nums);
    
    std::cout <<  0 <<"\n"
         <<std::endl;
    return 0;
}