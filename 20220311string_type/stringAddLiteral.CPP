#include<iostream>
#include<string>
using namespace std;
/* 
   Like build_in types, the 'string library' lets us convert both "character literals(e.g. 'a')" and "character string literals(e.g."hello")" to "string type". 
   NOTE:when we mix "strings" and "string or character literals", at least one operand to every '+'operator must be of string type. 
 */
int main()
{
    string s1 = "hello";
    // string s2 = "hello"+"juanjuan";//ERROR, cannot add two string literals.
    string s3 = s1 + ",juanjuan";//OK.
    string s4 = s1 + ',' + "juanjuan";
    /* OK, the statement will perform the subexpression " s1 + ',' " and returns a new sting 
     * firstly, then perform the new string + "juanjuan", so that this statement is valid.
     */
    
    cout <<  s1 <<"\n"
         <<  s3 <<"\n"
         <<  s4 <<"\n"
         <<endl;
    return 0;
}