#include<iostream>
#include<string>
/* 
3 possible outcomes of compiler for any given call to an overloaded function:
 * 
    I.  The compiler finds exactly one fucntion that is a "best match" for the actual arguments and generates code to call that function. 
 *
    II. There is no function with parameters that match the arguments in the call, in which case the compiler issues an error_message that there was "no match".
 *
    III. There is more than one function that matches and none of the matches is clearly best. This case is also an error, it is an "ambiguous call".
 */ 
 
 
/* 
It's not simple when the overloaded functions have the same number of parameters and when one or more of the parameters have types that are related by conversions.
There can be at most 3 steps to match an overloaded function:
 *
   1.Determine the set of "Candidate functions", a candidate function is a function with the same name as the called function and for which a declaration is visible at the point of the call(in the same scope).
 *
   2.Winnow "viable functions" from the candidate functions. a viable function must have the same number of parameters as there are arguments in the call, and the type of each argument must match(or be convertible to) the type of its corresponding parameters.
 *
   3.Compiler determines the "Best match" among viable functions, an overall best match is only one function for which:
   i. The match for each argument is no worse than(a match through a built_in conversion is "less good" than one that is exact)the match required by any other viable function. Check the detail in "Conversion Rank" P245.
 *
   ii.There is at least one argument for which the match is better than the match provided by another viable function.
   
   If after looking at each argument there is no single function that is preferable(among viable functions), then the call is in error. The compiler will complain that the call is ambiguous.
 */
 
 
//The following 2 functions are viable functions:
void sum_test(int v1, int v2){
    std::cout << v1 + v2 << std::endl;
}
 
void sum_test(double d1, double d2 = 5.5){
    std::cout << d1 + d2 << std::endl;
}

int main() 
{
  sum_test(42, 2.56); 
  /* In this call, when we look only at the first argument'42' , we find that the function 'sum_test(int,int)' is an exact match. But when we look at the second argument'2.56', the function 'sum_test(double, double)' is the exact match for second argument. Such that the compiler will reject this call because it is ambiguous.   
   */
    
    
    std::cout <<  0 <<"\n"
         <<  0 <<"\n"
         <<std::endl;
    return 0;
}