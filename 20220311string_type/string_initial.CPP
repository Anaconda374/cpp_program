#include<iostream>
#include<string>
/* 
    Although "Library iostream" includes "Library string", but including what library the program needs explicitly is a good practice to avoid ERRORS when program is running on different  compilers.  
 */
 
//'string' is defined using 'vector', and C++ defined lots of operations to manipulate and search a 'string', view more detail on P360 of <C++ primer>.
 
 using namespace std;
 
//Different forms of initialization : "copy form" & "direct"
int main()
{
    string s1 = "juan"; 
    s1 = "zen47";
/* when using ' = ' to initialize a variable,we are asking the compiler to "copy initialize" the object by copying the initializer on the right_hand side into the object being created.
 */ 
  
    string s2("juanjuan");//direct initialization,when we omit operator " = ".
    
    string s3(8,'A');
/* direct initialization, this initialization takes two values: 'count' and 'a character'. When we initialize a variable from more than one value,such as the initialization of s3, we must use the direct form of initialization.
 */ 
 
    string s4 = string(8,'B');
/* compound initialization: we can indirectly use the copy form of initialization by explicitly creating a temporary object to copy.
 *
 */
    std::cout <<  s1 <<"\n"
              <<  s2 <<"\n"
              <<  s3 <<"\n"
              <<  s4 <<"\n"
              <<std::endl;
    return 0;
}