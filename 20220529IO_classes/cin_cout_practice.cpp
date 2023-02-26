#include<iostream>

int main()
{
    std::cout << "enter two numbers:" << std::endl;
    /* 
     *    ' :: ' is a scope operator ,define "cout/cin objects used" is from namespace std.
     *  'endl' is a manipulator ,for ending the current line and flushing the buffer,
     *  'endl' ensure all output-content generated so far is actually written into the ostream object. 
     */
    int v1=0, v2= 0;
    std::cin >> v1 >> v2;
    std::cout<<"the sum of " << v1
             <<"and"<< v2
        <<" is "<< v1+v2 << std::endl;
    // c++ code block can be seperate into few fines without changing the performance.
    std::cout<<"the product of " << v1 <<"and"<< v2
        <<" is "<< v1*v2 << std::endl;  
    return 0;
}