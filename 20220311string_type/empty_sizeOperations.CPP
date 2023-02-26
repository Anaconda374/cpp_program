#include<iostream>
#include<string>
using namespace std;

/* 'empty' and 'size' are member functions of string library: 
 To call these function, we use the dot operator to specify the object which we want to run * the function 'object.empty()', 'object.size()'. 'empty' member returns "a bool value", 'size' member returns "the length of a string".
 */
int main()
{
    string line1, line2;
//keep reading newlines into 'line1' until meeting a empty line, then the while loop breaks.
   while(getline(cin ,line1) && !line1.empty())
        cout <<  line1 <<"\n"
             <<endl;
         
    while(getline(cin ,line2))
//read input a line at a time and only print lines that are longer than 5 characters.
        if(line2.size() > 5){
            cout <<  line2 <<"\n"<<endl;
        }
/* NOTE:the function 'size' doesnot return 'an int' ,instead it returns "a string::size_type" value, which is a companion type in string library for the purpose of using the library types in a machine_independent manner. "the size_type" is unsigned, so do not mix signed value(e.g.,int) with it, since when they perform arithmetic/comparing operations, the negative signed value will be converted into a big unsigned value, and it may cause surprising results. 
 */ 
 
  
  
    return 0;
}