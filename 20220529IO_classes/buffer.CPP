#include<iostream>
#include<string>
#include<windows.h>

/*
A buffer is a memory area that stores data(heaped up in main memory) being transferred between two devices or between a device and an application.
Input buffer:
    For example, when using 'cin' to read a stream from keyboard, the characters we typed are stored in the input buffer temporarily until we hit the 'enter', then the whole bulk of data in the buffer is sent to the program. this is called "buffer flushed".

Output buffer:
    In a similar way, the output buffer is used for storing the output stream, there are a few ways to flush the output buffer:
    1.the program completes normally;
    2.when buffer becoming full, it will be flushed before writing the next value.
    3.use manipulators to flush the buffer explicitly, such as:
        'endl'--adds a newline to the outstream and flush the buffer. 
        'ends'--adds a 'null' to the outstream and flush the buffer.
        'flush'--adds no data, just flush the buffer.
    4.'unitbuf' manipulator is used to set the stream's internal state, to empty the buffer after each output operation'<<'. By default, 'unitbuf' is set for 'cerr', so that writes to 'cerr' are flushed immediately.
    5.when the tied stream is read or written. An output stream might by tied to another stream, 'cin' and 'cerr' are both tied to 'cout', so reading 'cin' or writing 'cerr' flushed the buffer in 'cout'.
    
NOTE: output buffers are not flushed if the program terminates abnormally. when debug a program that has crashed, it is essential to make sure that any output should have been written was actually flushed.    
 */

int main()
{
    
    std::cout << "aaa" << std::ends;//append a space.
    std::cout << "aaa" << std::flush;
    std::cout << "aaa" <<std::endl;//append a newline.
    
    std::cout << "anacs";
    Sleep(3000);//3,000 milliseconds = 3 seconds.
    return 0;
}