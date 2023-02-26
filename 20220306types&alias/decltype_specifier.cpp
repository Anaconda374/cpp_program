#include<iostream>
#include<typeinfo>

/* 
   'decltype(operand)' specifier allows us to define a variable with 'the type that the compiler deduces from an expression/opreand' but do not use that expression to initialize the variable.
 */

double pi();
int main()
{
    decltype(pi()) dv = 2.71;//'dv' has the type which 'pi()' returns,in this case ,it is double.
    
/* CONST,REFERENCE types with 'decltype()':
 Unlike 'auto' specifier, when the operand in 'decltype()' is a variable, decltype returns the exact type of that variable ,including 'top_level const' and 'reference'. 
 * NOTE: Only in 'decltype()',a variable defined as a reference is treated as a reference object, not as the synonym for the object to which it refers.
 */  
    const int ci = 0, &cr = ci;
    decltype(ci) x = dv;//'x' has type 'const int', it has top_level const,and must be initialized.
    decltype(cr) y = x; // 'y' is type 'const int&'and bound to 'x',a reference must be initialized.


/* 
   when we apply 'decltype()' to an expression that is not a variable, we get the type that expression yields.
 */ 
    int i = 17, *p1 = &i, &r = i;
    decltype(r+0) b; // OK, 'b' has type 'int', since the addition operation 'r + 0' yields an int. 
   
/* 'decltype()' returns "A Reference Type":
  In general, 'decltype()' returns a reference type for " expressions which yield object that can stand on the left_hand side of the assignment", for example, 'dereference to variables', such as to access a object by its pointer(*p). so when apply 'decltype()' to such a deference, it always returns 'a reference type'.
 */
    decltype(p1) p2;//'p2' has type 'int*'
    decltype(*p1) c = i;// 'c' has type 'int&',and must be initialized.


/* 'decltype()' with "parenthesized variable" and "assignment" as the operand:
 * The type deduced by 'decltype()' depends on the form of its given expression.
 * 1. 'decltype((variable))' (double parentheses) always returns a reference type, but
 
 * 2. 'decltype(variable)' is a reference type only if variable is a reference.

 * 3.'decltype(assignment)' deduces a type which is a reference to 'the type of the left_hand operand'. 
 */
   int v1 = 47;
   decltype((i)) d = v1;//'d' has type 'int&' and must be initialized.
   decltype(v1 = ci) e = v1;
   //since the left_hand operand 'v1' is an int, so 'e' has type 'int&',and must be initialized.
   
    std::cout <<  typeid(dv).name() <<"\n"
              <<  x <<"\n"
              <<  typeid(e).name() <<"\n"
              <<  typeid(c).name() <<"\n"
              <<std::endl;
    return 0;
}

double pi()
{
    return 3.14;
}