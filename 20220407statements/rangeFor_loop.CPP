#include<iostream>
#include<string>
/* Range_for is not for "adding elements to a vector(or other container)":
  Execution of Range_for's body ends once all the elements have been processed, for this purpose the value of 'vectorName.end()' is cached. If we add elements to(or remove them from) the sequence, the value of 'end' might be invalidated. 
 */

int main()
{
//Range_for can iterate a "braced initializer list":
    for(auto ival :{1 , 3, 5}){ 
        ival = 6; //OK, but this assignment will not change the original values.
        std::cout << ival << std::endl;
    }
        
  
    return 0;
}