#include<iostream>
#include<string>
/* 
   "A Cast operator" is an unary operator which forces one data type to be converted into another data type. C++ supports four types of casting:
 * 1. static_cast
 * 2. dynamic_cast
 * 3. const_cast
 * 4. reinterpret_cast
 *
   The cast_operators inform both the readers and the compiler that we are aware of and are not concerned about the potential loss of precision. 
 */

int main()
{   
    int i = 5, j = 2;
    double slope = i/j; 
    /* if we want a floating type quotient of ints'i/j', we need to explicitly convert 'i' or/and 'j' to type double by using "cast_operators"
     */     
    std::cout << slope << std::endl;
    
/* "Static casts": A compile time cast. 
 * It does things like implicit conversions between types(such as int to float, or pointer to void*), and it often used to override an implicit conversion that compiler would that the compiler would otherwise perform.
 *
  Any well_defined type conversion can be requested using "static_cast", except those involving low_level const(which uses 'const_cast').
 */ 
    slope = static_cast<double>(i)/j;//'i' is converted to 'double' type explicitly.
    std::cout << slope << std::endl;
    
    const int *p = &i;
    // const char *pcc = static_cast<const char*>(p);
    // ERROR ,"static_cast" cannot cast "a low_level const object" into other types.    


/* "Const Casts": 
 * It is used to convert a 'low_ level const' object to the corresponding "nonconst type" or vice versa. Called "cast away the constness of objects".
 */
    const int ci = 5;
    //char c2 = const_cast<int>(ci); //ERROR, top_level const is cannot be casted away. 
    
    const int * pci = &ci;
    int *pi1 = const_cast<int*>(pci);
    *pi1 = 6;//Dereferencing the const_casted pointer '*pi' will not change const int 'ci'.
    std::cout<< ci << std::endl;
    
//Using 'const_cast' to write a nonconst object:
    int i2 = 47;
    const int* pci2 = &i2;
    int *pi2 = const_cast<int*>(pci2);
    *pi2 = 50;//Dereferencing the const_casted pointer '*pi2' can we change int 'i2'.
    std::cout<< i2 << std::endl; //the value of 'i2' is 50 now. 
    
    /* 
       However if the object was originally not a 'const', using a cast to obtain write access is legal, but using a 'const_cast' in order to write "a const object" is undefined.
     */



/* "Reinterpret Casts": Dangerous!
 * Interprets the contents of the operand as a different type, It can be used to convert a pointer of some data type into a pointer of another data type, even if the basic data types before and after conversion are different.
 */
 
    int *ip;
    char *pc = reinterpret_cast<char*>(ip);//Dangerous! convert an 'int*' to 'char*'.
    
    /* Because 'reinterpret_cast' simply converts the pointer type and does not check if the pointer type and data pointed by the pointer is same or not, it generally performs a low_level reinterprtation of the bit pattern of its operands, and it is often used when we want to work with bits. 
     */
    
    
// "Old-style Casts": inherited from C language and not recommended in C++; "(type)expr" .

    char *pc2 = (char*)ip; //equivalent to last statement.

    return 0;
}