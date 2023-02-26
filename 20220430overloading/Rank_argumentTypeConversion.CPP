#include<iostream>
#include<string>

/* In order to determine the best match from viable functions, the compiler rank the conversions that could be used to convert each argument to the type of its corresponding parameter.
 * 
 * Rank of argument conversions:
 * 1st: An exact match. It happens when:
        i.  The argument and parameter types are identical.
        
        ii. The argument is converted from an array or function type to the corresponding pointer type.Since we cannot really pass an array of function as an argument.    
        
        iii.A top_level const is added to or discarded from the argument.since "top_level const" does not effects the parameter initialization.
            
    2nd: Match through a 'const' conversion. This is talking about 'low_level const' conversion, such as converting a 'pointer_to_nonconst' to a 'pointer_to_const'.

    3rd: Match through a promotion. Remember that the small integral types(like type'char') always promote to 'int'.
         
    4th:Match through an arithmetic conversion(the implicit conversion in arithmetic operation), or a pointer conversion(like value'0'or literal'nullptr' can be converted to any pointer type).

    5th:Match through a class_type conversion.
 */


//NOTES: Match through 'Promotion':
 void _print(int v){
     std::cout << "this is a int type object: "<< v << std::endl;
 } 
 
 void _print(short v){
     std::cout << v << std::endl;
 }
 
//Match through 'Arithmetic conversion':
void _print(long double v){
     std::cout << v << std::endl;

}

//Match through 'const conversion':
void test_double(const int& cp){
    std::cout<< "const: "<< cp*2<<std::endl;
}

void test_double(int& pi){
    std::cout<< "nonconst: "<< pi*2<<std::endl;
}



int main()
{
    _print('a');
    /* Even though the argument'a' is closer to match the 'short' type parameter, but 
     * by default the compiler will promote it to 'int'.
     */
    
    // _print(2.5);//ERROR, ambiguous call.
    /* All the arithmetic conversions are treated as equivalent to each other. the conversion
     * from 'double' to 'long double' does not take precedence over the conversion from 'double'
     * to 'int'     
     */
     
     
     int v1 = 5;
     test_double(v1);;
     /* Since to initialize a 'low_level const' reference with a 'nonconst' object requires a
      * conversion. the version that takes a nonconst parameter is an exact match for 
      * ' test_double(v1) '. Pointer parameters work in a similar way.
      */

    return 0;
}