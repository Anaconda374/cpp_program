#include<iostream>
#include<string>
using namespace std;

int main()
{
    string s1; 
    int s2;
    cin >> s1; //read a whitespace-separated string into 's1'.
/* 
   The string input operator ' >> ' reads and discards any leading whitespaces(e.g.,spaces, newlines, tabs), it then reads characters until the next whitespace character is encountered.
 */
    cin >> s1 >> s2;
/* 
    Like the input and output operations on the build-in types, the string operators " << ,>>" return their left_hand operand as their result.
 *
    In this example,Directive'cin' read a string from external medias/devices,and input it into 's1',after the operation it returns a boolean reference to 'cin', if the current operation is done successfully ,it returns 'True(1)' state and continues perform 'cin', otherwise it returns 'False(0)' and ends, and this is why we can use 'cin>>' as an argument in conditional or iterative statements such as "while(cin>>)".
 */
    cout << s2 << s1 <<"\n"<< endl;
// BTW,we cannot use 'cout<<' as an argument in conditional statements. 

    return 0;
}