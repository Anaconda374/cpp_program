#ifndef SALES_DATA_H 
/* '#ifndef' and '#ifdef' are "header guards",header guards are preprocessor variables designed 
 *  to ensure that the contents of a given header file are not copied more than once into any 
 *  single file.
 */
 
/* If the variable has not been defined then '#ifndef' is true ,and everything following the 
 * #ifdef or #ifndef is processed up to the matching #endif.
 */

#define SALES_DATA_H
/* "Preprocessor" is program or text substitution tool,it is run automatically by C_compiler 
 * before the real compilation.'preprocessor' will transfrom "source code" into "pure c code"
 * by replacing each 'preprocessor variable' by its value/code text.   
 * All pre_processing directives will begin with a "#"; <file.h> file in angle brackets is 
 * predefined 'system header file' and located in the system directory, "file.h" are user defined. 
 */
#include<iostream>
struct Sales_data{
    std::string bookNO;
    unsigned units_sold = 0;
    double revenue = 0 ;
};

#endif 