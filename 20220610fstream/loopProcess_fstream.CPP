#include<iostream>
#include<string>
#include<fstream>
#include<ostream>
using namespace std;

void process(ostream& os, std::string str);

//Using 'command-line switch' to pass file names to the program.
int main(int argc, char* argv[])
{
    //using 'for' loop to batch process the files.
    for(auto p = argv+1; p!= argv + argc; ++p){
        ofstream of(*p);
        /* 
        each iteration constructs a new ofstream and associate it to write a file to which 'p' points. because 'input' is local in 'for', it is created and destroyed on each iteration. When an fstream object goes out of scope, the file it is bound to is automatically closed'.close()'.
         */
        if(of){
                process(of, "processd");
        }
    }
    
   
    return 0;
}


void process(ostream& os, std::string str){
    os << str << std::ends; 
}