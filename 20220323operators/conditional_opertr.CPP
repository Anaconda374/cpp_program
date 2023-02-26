#include<iostream>
#include<string>

/* " cond ? expr1 : expr2 "; 
 * 
   The type 'expr1' and 'expr2' must be the same type, or be convertible to a common type.
 */ 

int main()
{
/* 
    The result of the conditional operator is an lvalue if both expressions are lvalues, otherwise the result is an rvalue.
 */    
    std::string s1 = "true" , s2 = "false";
    std::string &sref = (1+1 == 2) ? s1 : s2; // this conditional operation returns "an lvalue".
    
    std::cout <<  sref <<"\n"
         <<std::endl;
         
//Nested Conditional Operations: 

/* The conditional operator can be used as "the condition" or "the expression(s)" of another
 * conditional expression. 
 */
    //As an expression -- Grade the input score:
    int score;
    std::cin >> score; 
    char grade = (score >= 90) ? 'A' : (score >= 75) ? 'B' : (score >= 60)? 'C' : 'D';
    std::cout<< grade << std::endl;
    //As a condition -- Return the max_number:
   
    int x, y, z;
    std::cin >> x >> y >> z;
    int max = (z > ((x > y)? x : y)) ? z : (x > y)? x : y; 
    /* since the conditional operator is right associative, this statement is equal to : 
     * (z > ((x > y)? x : y)) ? z : ((x > y)? x : y)
     */
    std::cout<< max << std::endl;
// NOTE: Nested conditional quickly become unreadable, a good idea is do not nest more than 2.

    return 0;
}