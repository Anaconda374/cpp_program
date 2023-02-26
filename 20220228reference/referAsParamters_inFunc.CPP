#include<iostream>
#include<string>
/* 
    A reference is an alias to an object, we cannot change the object a reference is bound to once it is defined(also must initialized), and we change the variable of a objects through its reference. 
 */


void smap_ref(int& x, int& y){//takes "two references" as parameters.
    int temp = x;
    x = y;
    y = temp;
}

void smap_val(int x, int y){ //takes "two ints" as parameters.
    int temp = x;
    x = y;
    y = temp;
}

int main()
{
    int i1 = 10;
    int i2 = 100;
    smap_val(i1, i2); 
    /* when a function takes "int type parameters" , the compiler is actually coping the int values of arguments into the parameters in that funtion, so the modification only affects the parameters inside the function, but not the variables which we passed.
     */
    std::cout <<  i1 <<"\n"
         <<  i2 <<"\n"
         <<std::endl;
    
    smap_ref(i1, i2);
    /* by passing the references to a function, the modification will affects the real objects which the references bound to.
     */
        std::cout <<  i1 <<"\n"
         <<  i2 <<"\n"
         <<std::endl;
    
    return 0;
}