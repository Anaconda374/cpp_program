# include<iostream>

int main()
{
    int val = 1;
    
    int &refval = val ;
    /* A reference must be the same type as the value, and initialized in its definition,
     * after initialization, the variable(not value)cannot be replaced that reference bound to.
     */
    refval = 6; 

    /* int &r1 = 3; ERROR,cannot bind non-const lvalue reference of type 'int&' to an 
     * rvalue of type 'int'.
     */
    refval = 6; 

    
    std:: cout << val << std::endl;
    //assgin a value to a reference means to assign that value to the object bound by the reference. 
    
    // int &refval2 = 7; ERROR, the initializer of reference must be an object.
    
    double d = 2.5, &r2 = d;
    
    refval = r2;
  
    
    std::cout << refval <<"\n"<<val<< std::endl;
    
    /* After the definition ,the reference can be assigned with different type of value,
     *  but translated into the type of reference   
     */
    return 0;
}