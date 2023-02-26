#include<iostream>
#include<istream>
#include<bitset>
#include<string>

/*
'streamType::iostate' is a machine-dependent integral type that can hold the value returned by '.rdstate()',and represents the condition state of a stream, normal contains 4 bits:     
    1st bit--badbit: indicate a system-level failure, such as an unrecoverable read or write error, which means the stream is corrupted and it's not possible to use a stream once badbit has been set. 
    
    2nd bit--failbit: it's set after a recoverable error, such as "reading a character when numeric data was expected", it's possible to correct such problems and continue using the stream.
    
    3rd bit--eofbit: indicate that the stream hit end-of-file'\0', reaching end-of-file sets both 'eofbit' and 'failbit'.

    4th bit--goodbit: used to indicate that a stream is not in an error state. *This value is guaranteed to be 0. The '.good()' operation returns 'True' iff none of the error bits is set.
 */

int main()
{
//If any of 'badbit','failbit', or'eofbit' are set, then the condition that evaluates that stream will fail.
    int v1;
    if(std::cin>> v1){
    //if we input a char of eof here, then this condition is evaluated as fail.
        std::cout<< v1 << std::endl;
    }
    std::cin.clear();
    
    
    int v2;
    std::istream& is = std::cin >> v2;
    std::istream::iostate is_state = is.rdstate();
//value returned from '.rdstate()' can only be held by Type 'iostate'.
    std::cout<< std::bitset<8>(is_state)<<"\n"
    << std::bitset<8>(is.eofbit) <<"\n"
    <<std::bitset<8>(is.goodbit)<<"\n"
    <<is.good() << std::endl;
//each operation of '.eof()', '.fail()', '.bad()', '.good()' returns a bool value, 'True' if its corresponding bit of that stream is set. 

    
//'.clear() operation':
/*
    '.clear()' resets all condition values in the stream to valid state, this operation returns 'void'. 
    the overloaded '.clear(flags)' operation take a flags argument which is 'iostate' type 
*/
    
    is.clear(is.rdstate() & ~is.failbit);
    //turns off failbit but all other bits unchanged.
    
    std::cout<< std::bitset<8>(is.rdstate())<< std::endl;
    is.setstate(is_state);
    //set the iostate of 'is' back to the old state.
    
    std::cout<< std::bitset<8>(is.rdstate())<< std::endl;
    
    return 0;
}