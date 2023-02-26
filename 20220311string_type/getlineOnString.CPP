#include<iostream>
#include<string>
using namespace std;
/* 
   Like the input operator '>>', 'getline' returns its istream argument,as a result, we can use 'getline' as a condition.  
 */

//print a whole line through 'getline' operator.
int main()
{
    string line;
    while(getline(cin, line)){
    //this statement will keep reading newlines until it meets end_of_file(^Z).
        cout <<  line <<endl;
       
    }
    
    
    return 0;
    
    
}