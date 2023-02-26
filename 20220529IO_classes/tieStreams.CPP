#include<iostream>
#include<string>

/*
In IO library, we can manually tie or untie an istream or ostream to another ostream using '.tie(ostream*)'. 
    1. To tie a given stream to a new ostream, we pass '.tie()' a pointer to the ostream.
    2. To untie the stream completely, we pass a null pointer.
 
 */

int main()
{
    int v1;
/*
  the overloaded '.tie()' operation takes no argument and returns a pointer to the ostream it is currently tied. this operation returns the null pointer'0' if the stream is not tied.
*/
    std::cout<< std::cin.tie() << std::endl;
    //library ties 'cin' and 'cout' by default.
    
    std::cin.tie(nullptr);//untie 'cin' manually. 
    std::cout<< std::cin.tie()  <<std::endl; 
    std::cin >> v1;    
    std::cout <<  0 <<"\n"
         <<  0 <<"\n"
         <<std::endl;
    return 0;
}