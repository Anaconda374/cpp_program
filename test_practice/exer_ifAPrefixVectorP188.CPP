#include<iostream>
#include<string>
#include<vector>
#include<iterator>


int main()
{
    std::vector<int> v1, v2;
    int num1;
    std::cout<< "Please input 1st number sequence:";
    while(std::cin >> num1){
        v1.push_back(num1);
    }
    std::cout<< "Please input 2nd number sequence:";
    
    /* Note:we need to clear the "input buffer" between two independent 'cin>>' operations,
     * otherwise, the second 'cin>>' may meet the 'EOF'.
     */
    std::cin.clear();
    
    int num2;
    while(std::cin >> num2){
        v2.push_back(num2);
    }
    
    std::cout<< v1.size() << "\n" << v2.size() <<std::endl;
    
    std::vector<int>::size_type i;
    if (v1.size() < v2.size()){
        for( i = 0; i != v1.size(); ++i){
            if(v1[i] != v2[i]){
                std::cout<< "None prefix vector"<<std::endl;
                return 0;
            }
        }
        std::cout<<"v1 is a prefix of v2."<< std::endl;
            
    }
    else {
        for(i = 0; i != v2.size(); ++i){
            if(v2[i] != v1[i]){
                std::cout<< "None prefix vector"<<std::endl;
                return 0;
            }
        }
        std::cout<<"v2 is a prefix of v1."<< std::endl;
            
        
    }
    
    return 0;
}