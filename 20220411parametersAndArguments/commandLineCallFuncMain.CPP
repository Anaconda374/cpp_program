#include<iostream>
#include<string>
/* 
Command-line options are commands used to pass parameters to a program. These entries, also called command-line switches, can pass along cues for changing various settings or executing commands in an interface.
 
Properties of Command Line Arguments:
  1.They can only be passed to main() function.
  2.They are parameters/arguments supplied to the program when it is invoked.
  3.They are used to control program from outside instead of hard coding those values inside the code.
  4.argv[argc] is a NULL pointer.
  5.argv[0] holds the name of the program. 
  6.argv[1] points to the first command line argument and argv[n] points last argument.
 */

int main(int argc, char* argv[])
{
/* 
we typically define main() with two parameters: 
 1st is the number of command line arguments(conventionally named: argc--ARGument Count)which automatically deduces(no need to pass an argument to it manually) and stores the number of command-line arguments passed by user(including the name of the called program). 

 2nd is list of command-line arguments(conventionally named: argv--ARGument Vector) which is "an array of pointers" to C_style character string(char * arr[]) listing all the arguments. 
 */
 
    std::cout<< argc <<" arguments received."<<"\n"
             <<"The input string is: ";
    
    for (int i = 1; i< argc; ++i)
        std::cout << argv[i] <<" ";
    /* 
        It's the same mechanism of "running g++ command line instructions". For this simple program, we can run it in "command line" and input: "commandLineCallFuncMain (any character strings)" to print our string.
       
In this case: "d:\cpp_program\20220411parametersAndArguments>commandLineCallFuncMain a b c"
     */
    return 0;
}