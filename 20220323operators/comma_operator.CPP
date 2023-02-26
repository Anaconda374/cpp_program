#include<iostream>
#include<string>

/* In C and C++, comma (, ) can be used in two contexts: 
 */
 
 int max(int x, int y){
     
     return (x > y)? x : y;     
 }

int main()
{
/* 1." Comma ," acts as a separator :
    when used in function calls and definitions, function like macros, variable declarations, enum declarations, and similar constructs. 
 */    
    int x = 10 , y = 47;
    /* The use of comma as a separator should not be confused with the use as an operator.
     * For example, the following functions 'max()' can be called in any order. 
     */
    int v1 = 5, v2 = 10, v3 = 8, v4 = 11;  
    int maxNum = max(max(v2, v4),max(v1, v3)); 
    std::cout <<  maxNum <<std::endl;
    
    
/* 2.Comma as an operator: 
    The comma operator (expr1 , expr2 ) is a binary operator that " evaluates its first operand and discards the result, it then evaluates the second operand and returns this value(and type)".
    The comma operator has the lowest precedence of any C operator, and acts as a sequence point.  
 */
    
    x = 10;
    y = (x++, ++x);
    //first operand 'x++' is "evaluated(x=11)" but its result is discarded. 
    printf("%d\n", y);

    return 0;
}