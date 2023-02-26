#include<iostream>
#include<string>
#include<fstream>
using namespace std;
/*
 Each stream has "an associated file mode" that represents how the file may be used. We can supply a file mode whenever we open a file--either when we call '.open' or when we indirectly open the file.
 when we initialize a stream from a file name. There are several file modes in C++(which are under the namespace std::ios):
    1. 'in' open for input, it's set only for an 'ifstream'.
    2. 'out' open for output, it's set only for an 'ofstream'.
    3. 'in & out' for input and output, it's set for an 'fstream'.
    4. 'app' seek to the end before every write, it's set for an 'ofstream', 'app' may be specified so long as 'trunc' is not.
    5. 'trunc' truncates the file, by default ,a file opened in 'out' mode is truncated even if we do not specify 'trunc'.
    6.'seek' to the end immdiately after the open, it's set for both 'ifstream' and 'ofstream', it moves the cursor at-end. 
    7. 'binary' does IO operations in binary mode.
 */

int main()
{
    
    fstream s;
    
    s.open("demo1.txt", ios::out | ios::app);
    //to output(or write) the file_stream's' into file. we can combine multiple modes using binary or'|' when open a file.
    if(s){
       s << "changed" << std::ends;
    }
    s.close();
    
    return 0;
}