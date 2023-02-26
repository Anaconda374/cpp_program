#include<iostream>
#include<string>

/* Although every member must be declared inside its class, we can define a member function's body either inside or outside of the class body.
 */

//The definitions of member_functions of 'Sales_data' class:
std::string Sales_data::isbn() const {
    return bookNO;
}
/* Implicit Parameter'this': 
  although there is no argument passed to 'isbn()', when we use the dot operator'.' to fetch the 'isbn()' member of a object, such as 'total.isbn()'. Member functions access the object on which they were called though an extra, implicit parameter named 'this'(the calling object), When we call a member function with an object(e.g. total) and dot operator'.' preceded, Parameter'this' is initialized with the address of the object(&total) on which the member_function was invoked. 
  Inside the member function body, thanks to the implicit parameter 'this' we can refer directly to the members of the objects on which the function was called. So any direct use of a member of the class is assumed to be an implicit reference through 'this'. Such that we can just write "return bookNO;" instead of "return this->bookNO;(X)".
 */

/*
Keyword 'const' in the definition of the member_function: 
    Because Parameter'this' is intended to always refer to "this object".  By default, 'this' is kind of a 'pointer' to the "nonconst class object", since we can initialize 'this' with any (Sales_data type) object ,and we cannot call an ordinary member_function on a 'const object'. 
    In another respect, because of the keyword'const' in member funtions that we cannot change the address that 'this' holds(means 'isbn()' cannot modify the members of the object to which this points).
    Keyword'const' follows the parameter list indicates that 'this' is a 'pointer_to_const'. Member_functions that use 'const' in this way are 'const_member_function'.
 */
 
 
double Sales_data::avg_price() const {
    if (units_sold)
        return revenue/units_sold;
    else
        return 0;
}
/* Class Scope:
 Since C++ compiler processes classes in 2 steps -- The member declaration are compiled first, then compiles the member function bodies. So that the member function bodies may use other members of their class regardless of where those members appear. 
 The name of "a member" defined outside the class must include the name of the ambient class using scope operator'::'(e.g. Sales_data::avg_price). Once the compiler see the function name in this manner, the rest of the code is interpreted as being inside the scope of the class. 
 */ 
 
 
 Sales_data& Sales_data::combine(const Sales_data& rhs){
     /* 
      'rhs' stands for 'right-hand operand of 'Sales_data' type, since we do not need to change the value 'rhs' refers, we define it as a 'const_reference'.
      But we do need to use this function to change the object to which the implicit parameter'this' points, so we do not use Keyword'const' in the definition, and use a reference to return the object. 
      */
    unit_sold += rhs.units_sold;
    revenue += rhs.revenue;
    return *this;
    /* 
    In the function body, we do not need to use the implicit 'this' pointer to access the members of the object(e.g. unit_sold), However, we do need to use 'this' to aceess the object as a whole entity(e.g. return *this).
     */
 }

    

int main()
{

    return 0;
}