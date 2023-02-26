#include<iostream>
#include<string>
#include<vector>

/*
 
 */
using namespace std;

int main()
{
    vector<string> vec1 = {"cuarto"};
    if(!vec1.empty()){
        auto val = *vec1.begin(), val2 = vec1.front();
        auto last = vec1.end();
        auto val3 = *(--last);
        auto val4 = vec1.back();
        
    //va1~ val4 son mismos. 
        cout<< val <<endl;
        cout<< val2 <<endl;
        cout<< val3 <<endl;
        cout<< val4 <<endl;
    }
    
    
    std::cout <<  0 <<"\n"
         <<  0 <<"\n"
         <<std::endl;
    return 0;
}