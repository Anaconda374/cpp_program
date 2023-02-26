#include<iostream>
#include<string>
/* 
   Since the function using "reference parameters" can change the value of the passed objects, so instead of having only one value to return, reference parameters let us effectively return multiple results by assgining the addtional result to the passed objects. 
 */

std::string::size_type find_char(const std::string & s, char c, 
                                    std::string::size_type & occurs)
//'size_type' is an unsigned type used to hold the size of any 'string' or 'vector'.
{   auto firstOccur_position = s.size();
    occurs = 0;
    for (decltype(firstOccur_position) i = 0; i!= s.size(); ++i){
        if(s[i] == c){
            if(firstOccur_position == s.size()){
                firstOccur_position = i;
            //By this 'if' block, the the value of 'firstOccur_position' can only change once.
            }
            ++occurs;
        }
        
    }

    return firstOccur_position;
}

int main()
{
    std::string s;
    char c;
    std::string::size_type occurs = 0;
    std::cout<<"please input a string: ";
    std::cin >> s;
    std::cin.clear();
    std::cout<<"\nInput a char look for in the string: ";
    
    std::cin>> c;
    auto pos = find_char(s, c, occurs);
    std::cout <<"The first appearance is at Positon "<<  pos <<"\n"
         <<"It appears "<<  occurs <<" times"<<"\n"
         <<std::endl;
    return 0;
}