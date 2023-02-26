#include<iostream>
/*
 * nested comment is incorrect, since the inner commnet brace " * / " will match the outer comment brace. 
 *
 */
 using std::cout;
 using std::endl;

int main()
{
    cout << "/*" << endl; 
    cout << " */ "<< endl;
    //cout << /* " */ " */ << endl; <-- this line is illegal.
    cout << /* "*/" /* " /* " */;
    return 0;
}
