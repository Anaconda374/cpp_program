#include<iostream>
#include<string>

/* We can use both 'typedef' and 'using' keywords to define an alias to a function, and the most uses of "alias to function" is to defining a "pointer to function" easier.
 */
 int test_sum(int v1, int v2){
    return v1 + v2;
}
// Use 'typedef' to define an alias to a function type and a 'function_pointer':
typedef decltype(test_sum) fun1;//equivalent to "typedef int fun1(int v1, int v2);"
fun1 *pf1;

// Use 'using' to define an alias to a function type and a 'function_pointer':
using fun2 = int (int v1, int v2);
fun2 *pf2; 
/* Now we defined 2 type alias 'fun1' and 'fun2', both are the same(sort of)function type
 * that takes 2 'int' arguments, and return an 'int'.
 * 'pf1', 'pf2' are 2 pointers which point to this type of function.
 */

int main()
{
    
    pf1 = test_sum;
    int sum1 = pf1(2 ,4);
    std::cout << sum1 << std::endl;
    
    pf2 = test_sum;
    int sum2 = pf2(10 ,37);
    std::cout << sum2 << std::endl;
    
    
    return 0;
}