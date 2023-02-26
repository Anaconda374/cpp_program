#include<iostream>
/* const reference is " A reference to const",technically speaking,there are no const references,
 * a reference is not an object ,so we cannot make a reference itself const.
 */
int main()
{
    const int ci = 4;
    const int &r1 = ci ; //<-A const reference must be initialized in its definition,like 'const'.
  
    /* r1 is a reference to the const object ci ,it's called "const reference", it cannot be 
     * assigned after its initializer.
     */
     
    const int &r2 = 7; // <- A const reference can also bound to a const literal directly.
    
    double dval = 2.17;
    const int &r3 = dval;
    /* There are 2 exceptions to the rule that the type of a reference must match the type of the object to which it refers:
     (1)A const reference can be initialized from any expression that can be converted to the type of reference.In other words, the other types can be converted into const type or bound by const  reference,but the const can not be bound by non-const reference,since assigning a reference may change the const object which it bound to. 
     */
     int  i = 23;
     const &r4 = i; 
     i =20;
     /* 'r4' bound to 'i' , and that cannot be used to change 'i', but 'i' can be changed by assigning itself or other valid ways, then the value which the const reference refer to will also change accordingly. 
      */
   
    std::cout << r3 <<"\n"
              << i  <<"\n"
              << r4 <<"\n"
              <<std::endl;
    
    return 0;
}