#include<iostream>

#include<typeinfo>

using std::cout;
using std::endl;
int main()
{
    char16_t a = 'h';  
    unsigned b = -2u;
    int x = 017;
    
    cout << x <<endl;
    //when assign a octal number to a variable ,it will still be output as the decimal form.

    cout << -2u << endl; //convert to "unsigned"
    //use suffix to specify the type of integer literals, qoutation marks are removed. 
    cout << u'h' <<endl;
    /* using prefix to specify the type of char of string literals, 
     * u'...' convert the character or string to its 16bit-unicode,the type is converted int char16_t.
     */
    cout << a <<endl; // this statement express the same as the previous one 
   
    cout << u8"hi!"<<endl; // u8"(string)" encodes each characters in the string in utf8(8bit). 
    
    cout << 1E-3f << endl;
    cout << typeid(1E-3f).name() <<endl; 
    /* single-precision float,means: {1*10^-3 | float},
     * and if no "f/F" added behind ,then it will be the "double type".
     */
     
    cout << "who goes with F\145rgus?\012"<< endl; 
    // ' \012 ' is equal to '\12' , 12 and 012 are all octal digits follow "the escape character \ ". 
 
    
 
    return 0;
}