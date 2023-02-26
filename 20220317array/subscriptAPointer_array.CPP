#include<iostream>
#include<string>
/* 
   When we subscript an array such as ' arrName[0] ', we are really treating 'arrName' as a  pointer(to an address), and subscripting this pointer to an element in that array by an index.
 *
   Such that, we can use the subcript operator'[n]' on any pointer,as long as that pointer points to an element(or one past the last element) in an array. 
 */

int main()
{
    int ia[] = {1, 2, 3, 4};
    int* p = &ia[2];//Pointer 'p' points to the element indexed by [2] in Array 'ia'.
    int i = p[1];//to subscript Pointer'p' by index'1' is equal to " * (p +1) ".
    int j = p[-1];
    /* subscript operator can be a negative value, this feature works for 'vector', 'string', 'array' objects.   
     */
    std::cout <<  i <<"\n"
         <<  j <<"\n"
         <<std::endl;
    return 0;
}