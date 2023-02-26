#include<iostream>
#include<string>
#include<sstream>
/*
  The 'sstream' header defines three types 'istringstream', 'ostringstream', 'stringstream' to support in-memory IO  means these types read from or write to a string as if the string were an IO stream.
  Like 'fstream' these types inherit from the types defined in 'ios'
 */

int main()
{
    std::string s1 = "kuan";
    std::stringstream strm(s1);
    // define a stringstream object 'strm' that holds a copy of the string 's'. This constructor is explicit.
    
    std::cout <<  strm.str() <<std::endl; 
    std::cout <<  strm.str() <<std::endl; 
    //'.str()' returns a copy of the string that 'strm' holds.
    
    strm.str("A_Kuan");
    strm.str(s1);
    //copy the string and append it into 'strm', not overwrite. this operation returns void.
    std::cout <<  strm.str() <<std::endl; 
    return 0;
}