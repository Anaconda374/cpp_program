#include<iostream>
#include<string>
#include<vector>
#include"D:\cpp_program\cpp_headers\Sales_data.h"

/* In addition to defining how "an object" of the class type is initialized using constructor, the "classes" also control how an object of its type is copied, assgign,
or destroyed by defining corresponding operations.

Synthesized version of 'copy', 'assignment', and 'destruction' operations:
    If the classes do not define these operation for its objects, the "compiler" will synthesize these operations for the objects. Ordinarily, the version of operations that the compiler generates for an object is to 'copy', 'assign', or 'destroy' each member of the object.
 */

int main()
{
    Sales_data item1;
    item1.bookNO = "123-x";
    item1.units_sold = 2;
    item1.revenue = 20.5;
    
    Sales_data item2 = item1;
    /* The synthesized(default) assignment operation for Class'Sales_data' is equivalent to:
    
       item2.bookNO = item1.bookNO;
       item2.units_sold = item1.units_sold;
       item2.revenue = item1.revenus;
     */
    std::cout<< item2.revenue <<std::endl;

    return 0;
}