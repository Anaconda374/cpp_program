#include<iostream>

/* 
   Definition of constant expression: A constant expression is an expression whose value cannot change and "that can be evaluated at compile time". 
   In c++, a literal is a constant expression , a const object that is initialized from a constant expression is also a constant expression. 
   NOTE: NOT all expression which contains 'const qualifier' are constant expression.
 */
 
int add(int a, int d);
 
int main()
{
    // NOTE: NOT all expression which contains 'const qualifier' are constant expression.
    
    const int v1 = 20; // v1 is constant expression, evaluated at compile time.
    const int v2 = v1 + 2; //v2 is constant expression, evaluated at compile time.
    int v3 = 46; // Not a constant expression it is a plain int type.
    const int v4 = add(1,2); // Not a constant expression ,since its evaluated at run_time.
    
  
    /* Constexpr Qualifier:
     *  we can ask the compiler to verify that a variable is a constant expression by using 
     *  'constexper qualifier' in the declaration.
     */
    constexpr int v5 = 60; // OK,since '60' is a constant expression.
    
    //constexpr int v6 = add(5,6); // ERROR, 'add()' is not a "constexpr function"
    
    
    /* Literal Types: 
    Because a constant expression is one that can be evaluated at compile time, in order to do so they are basically "literals",so that there are limits on the types that we can use in a constexpr declaration, those types are known as "literal types" because they are simple enough to have literal values, including "reference", "arithmetic", "pointer" types.
    */
     
     /* 
     NOTE: Pointers in constexper, Unlike the pointer in const declaration(const int *p = 9 ,p is a pointer to const),in constexpr declaration, the constexpr specifier applies to the pointer, not the object it points.In general, the 'constexpr' specifier imposes a top_level const on the object it defines.
     */
      
      const int *p = nullptr ;      
      p = &v1; //OK, 'p' is pointer to const . 
      
      constexpr int *q = nullptr;
      // q = &v1; //ERROR, 'q' is a const pointer ,we can not change the object it points.
      
      
    return 0;
}

int add(int a, int d)
{
    
    return a+d;
}