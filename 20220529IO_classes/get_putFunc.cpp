#include<iostream>
#include<string>

/*
Method'.get(...)' or Function'getline(...)' is used to get chars from standard iostream.  
 */

int main()
{
    
    std::string input;
    getline(std::cin, input);
    std::cout <<  input <<  " done" <<"\n"
         <<std::endl;
/*
'cin.get()' is used for accessing character array. It includes white space characters and the end of file char '\0'.
*/
    char carr[5];
    std::cin.get(carr, 2);
    //feed 2 chars into 'carr' from standard iostream, carr[1] is '\0'.
    std::cout.put(carr[0]);//output a char once.
    
    return 0;
}