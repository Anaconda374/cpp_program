#include<iostream>

using std::endl;
using std::cout;
int main()
{
    cout << " backspace test\b" << endl;
    cout << " carriage return \r test" << endl; 
    /* " \r "  moves the cursor to the beginning of the line without advancing to the next line,
     * and it'd obliterate all before it when other things is going to write or output . 
     */
    cout << " \117\103\124" <<endl;
    cout << " \x48\x45\x58 " <<endl;
    /* we can use escape character " '\' followed by octal digits" 
     * or " '\x' followed by hexadecimal digits to represent characters"
     */
    
    return 0;
}