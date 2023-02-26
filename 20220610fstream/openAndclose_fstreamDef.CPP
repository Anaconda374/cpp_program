#include<iostream>
#include<istream>
#include<string>
#include<fstream>
/*
 <fstream> header defines three types to support file IO: 
    'ifstream' to read from a given file;
    'ofstream' to write to a given file;
    'fstream' reads and writes a given file.    
 */
using namespace std;

/* 
  since we can use an object of an inherited type in places where an object of the original type is expected. If we have a function that takes an 'ostream&', we can call that function passing it an 'ofstream' object, and similarly for 'istream&' and 'ifstream'.
 */
std::string& read(istream& is, std::string& str){
    //read a input stream ,and extract it into a string object. 
    is >> str;
    return str;
}



int main()
{
//1.creates an ifstream object and opens a file initially:
    ifstream i("test.txt");
    //With new standard, file names can be either 'library strings' or 'C-style char arrays'. 
    std::string s1;
        std::cout<< read(i, s1)  << std::endl;
/* 
    'i' is an input stream that is initialized to read a single string from the file named by the string argument "test.txt", until it meets the first 'space' or 'newline', but we can use vector to store multiple strings.
*/
    i.close();
    
    
//2.create an ofstream object and opens a file initially:
    ofstream o("test.txt", std::ios::app);
    /*
     By fault, 'o' will overwrite the data that originally in "test.txt", so that we can pass an additional argument 'app'(append) when '.open' the file.
    */
    o << "kuan"<< std::ends;
    


//3.manually associate a file to a stream object.
    o.close();
/* 
    calling 'open' on a file stream that is already open will fail and set 'failbit' on that stream object, and the subsequent attempts to use that file stream will fail. To associate a file stream with a different file, we must first close/untie the existing file by using '.close()', then associate/tie it to another file.
*/
    o.open("test2.txt");
    //if no such file, the '.open()' will create a new file.
    
    if (o){//equivalent to "if(o.is_open())",     
/*
    if the open successfully, then '.open()' sets the stream's state so that '.good()' is true.
*/
        o << "open and write successfully." << std::ends; 
    }
    else 
        cerr << "open fail! \n";
    //if the file is set 'read-only', the ofstream will fail to open it.
    
    
    return 0;
}