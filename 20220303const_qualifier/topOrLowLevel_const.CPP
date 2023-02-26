#include<iostream>
/* "const qualifiers" in definitions can have different levels__Top or Low.
 *
 The top_level const means the object itself is const and cannot be changed,which can be :
 * 1> build-in arithmetic types, i.e."const int v1 = 2 ";
 * 2> A class type;
 * 3> A pointer type, i.e. " int *const p = v1";
 *
 The low_level const means "the defined object can point or refer to a const object",so that we can change the object to which the defined object points, which can be :
 * 1> A reference, i.e. "const int &r = v1", 'r' can be bound to other const objects; 
 * 2> A pointer type , a pointer definition can have "both top and low level const" independently.
 *
 * The top_level and low_level const theory needs us to take more practice in order to get familiar with it. 
 */

int main()
{
    
    const int i = 46; // After this definition ,' i ' cannot be changed ,so const is top_level.
    const int *p1 = &i; // We can change 'p1' to other const int variable ,so const is low_level. 
    /* 
    By these two examples ,we discovered that "the loaction of where const qualifiers sit" does not indicate the level of const,we need to focus on its underlying mechanism,but not the place. 
     */
    
    const int *const p2 = p1; 
    // The right const is top_level ,the left const is low_level. 
    
    
    /* The distinction between top_level and low_level :
     *
     * Top_level:when we copy/assign "a top_level const object" to other "low_level const or nonconst object ",we can do it freely,the top_level const is ignored,since the top_level const represents itself,and "the copied from top_level const object" won't be changed in assignment. 
     *
     * Low_level:when we dealing with low_level const in assignment,the low_level const is never ignored,when we copy an object,both object must have "the same low_level const qualification" or "there must be a conversion between the types of the two objects".In general,we can convert a nonconst to const(the copied from top_level const is ignored), but not the other way around. 
     */
     int v1 = 13, &r1 = v1;
     p1 = &r1;//OK,'r1' is nonconst(int&), it can be assgined into a low_const(const int*) ;
     
     int *p3;
     p3 = p1; 
     /* ERROR, 'p3' is plain int* ,'p1' is low_const pointer ,if this assignment succeeded, then we will be able to change the const object through the plain int*(*p3),so it's a invalid conversion from 'const int* ' to ' int* ' .
      */
    return 0;
}















