#include<iostream>
#include<string>

/* 
Extraction operator '>>' :
This operator'>>' applied to an input stream is known as extraction operator. It is overloaded as a nonmember function in Class'istream', and its basically used for several ways:
    1. Arithmetic types(bool, char, int, string): Extracts and parses characters sequentially from the stream(until it meets a space\0 or newline\n, etc.) to interpret them as the representation of a value of the proper arithmetic type.
    
    2.Stream buffers: Extracts as many characters as possible from the stream and inserts them into the output sequence controlled by the stream buffer object pointed by 'sb'(if any), until either the input sequence is exhausted or the function fails to insert into the object pointed by 'sb'. 
    
 PS. ^ This Part2 needs example to demonstrate. 
 */
 
 
/* 
Insertion operator '<<' :
This operator'<<' applied to an output stream is known as insertion operator.It is overloaded as a nonmember function in Class'ostream', and its basically used for several ways:
    1.Arithmetic types: Generates a segment of stream from a value(literal or variable), properly formatted according to the locale and other formatting settings selected in the stream(e.g. UTF-8), and inserts them into the output stream.
    2.Stream buffers: Retrieves as many characters as possible from the input sequence controlled by the stream buffer object pointed by sb (if any) and inserts them into the stream, until either the input sequence is exhausted or the function fails to insert into the stream.
 */

int main()
{   
    std::string a;
    std::cin >> a;
    /* extract a segment of steam from input, and interpret it into 'int' value, then
     * stores the value in a.
     */
    
    
    std::cout << a <<std::endl;
    //generate a segment of stream form the value of 'a' in UTF-8 standard.
    return 0;
}