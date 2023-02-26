// #define NDEBUG 
/* 
"#define NDEBUG" should be writen at the beginning of the program. 
 We can "turn off" debugging by defining a Preprocessor_variable 'NDEBUG', the behavior of 'assert' depends on the status of 'NDEBUG', if 'NDEBUG' is defined(#ifdef =1), 'assert' does nothing. By default, 'NDEBUG' is not defined, then 'assert' perform a run_time check.
 */


#include<iostream>
#include<string>
#include<cassert> //'assert' is a Preprocessor_variable defined in header<cassert>.

/* C++ programmers use "preprocessor macros" in their programs in order to conditionally execute 'debugging_code', which is the similarly with the 'header guards', and these 'debugging_code' is executed only while the program is being developed. When the application is completed and ready to ship, the debugging code is turned off.
 * 
 * This approach uses two preprocessor facilitiess :
 * 1. Macro 'assert'; 2. Preprocessor_variable 'NDEBUG'.  
 */


/* 
    'assert(expr)' is a preprocessor macro, it takes a single expression which it uses as a condition, if the expression is false(i.e., 0), then 'assert' writes a message and terminates the program. if the expression is ture(i.e., nonzero), then 'assert' does nothing.
 * 
    "Preprocessor names" are managed by the 'preprocessor' not the 'compiler', so we use'assert' macro directly(not std::assert) and do not provide a 'using' declaration for it.
 */



int main()
{
    int a, b;
    std::cin >> a >> b;
    assert(b > 0);//if (b > 0), 'assert' does nothing, otherwise it will abort the program.
    std::cout << a + b << std::endl; 
    
    
/* In addition to using 'assert', we can write our own conditional debugging_code using header guard 'ifndef'  with 'NDEBUG'. 
 */
 
#ifndef NDEBUG 
//If this statment is true(since 'NDEBUG' is not defined) and the program is running correctly, then the following code executes.
    std::cerr << __func__ << std::endl;
    /* 'cerr' is the standard error stream which is particularly used to output the errors.
     * It is an instance of the ostream class. As cerr stream is un-buffered so it is used when we need to display the error message immediately and does not store the error message to display later. 'c' refers to 'character'. Hence cerr means “character error”. 
     * It is always a good practice to use 'cerr' to display errors.
     */
    
    /* '__func__' print the name of the function we are debugging, defined by C++ compiler.
     * The preprocessor also defines four other names that are useful in debugging:
     * 1. __FILE__
     * 2. __LINE__
     * 3. __TIME__
     * 4. __DATE__
     */
#endif
    return 0;
}