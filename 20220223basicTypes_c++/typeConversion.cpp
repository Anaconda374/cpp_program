#include<iostream>
/* Arithmetic Conversion Rules(between different types):
 *
 * In Assignments: "the type of right operand" is converted to "the type of left operand". 
 *
 * In Expressions: 1. char -> int;
 *                 2. short -> int;
 *                （1 & 2 are integral promotions which happen in most expressions.） 
 *                 3. int -> unsigned;
 *                 4. single precision -> double precision;
 *                 5. smaller size -> bigger size (int -> long);
 *
 */
 
int main()
{
    unsigned x1 = 10, x2 = 42;
    std::cout << x1 - x2 << std::endl;// when the result is out of the range of its type,it will wrap around.
    std::cout << x2 - x1 << std::endl; 
    int i1 = 10, i2 = 42;
    std :: cout << i2 -i1 << std::endl;
    std :: cout << i1 -i2 << std::endl;
    std :: cout << i1 -x1 << std::endl;
    std :: cout << x1 -i1 << std::endl;
    return 0;
}