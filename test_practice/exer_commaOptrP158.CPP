#include<iostream>
#include<string>
#include<vector>


int main()
{   
    std::vector<int> vi(10);
    std::vector<int>::size_type cnt = vi.size();
    for (std::vector<int>::size_type ix = 0; ix != vi.size(); ++ix, --cnt) {
        /* converting "prefix operators" into "postfix operators" as for_loop operand will not 
         * change the process.
         */   
        vi[ix] = cnt;  
    }
    
    for(auto i :vi){
        std::cout << i <<std::endl; 
    }
    std::cout<<std::endl;
    
    int x = 5, y = 10;
    (1<2)? ++x, ++y: --x, --y; 
    /* Because Comma operator's precedence is lower than Conditional operator, this statement is 
     * actually seperated two statements: "(1<2)? ++x, ++y:-xx" , "--y" .
     *                                              (this comma ^ seperates them is a separator.)
     */
    std::cout <<  x <<"\n"
         <<  y <<"\n"
         <<std::endl;
    return 0;
}