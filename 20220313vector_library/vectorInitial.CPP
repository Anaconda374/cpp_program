#include<iostream>
#include<string>
#include<vector>
using namespace std; // just use this statement for cleaner illustration. 

int main()
{
// List_Initialization:
    vector<int> ivec1;
    ivec1 = {10, 9};
    ivec1 = {1, 2, 4, 5};
/* 
   since a vector is a dynamic array, we need to assign or initialize the vector object with "values" in "list initialization" way.
 */
    vector<string> v1 {10,"b"} ;
 /* 
   In some particular cases, "list initialization" can be converted into "constructing_initialization",when the first value doesnot match the type of elements,the compiler looks for other ways to  initialize the object from the given values.
  */
    cout << ivec1[1] <<"\n"
         <<  ivec1[1] <<"\n"
         <<  v1[9] <<"\n"
         <<endl;
    

// Copy_form:
/* 
   we can assign the individual element in a vector ,or copy a vector object into another  by using copy_form assignment ' = '.
 */    
    ivec1[0] = 9;
    vector<int> ivec2 = ivec1;//equal to " vector<int> ivec2 (ivec1)"
       cout << ivec2[0] <<"\n"
         <<endl;
        
//constructing_initialization/Element_count initialization:
    vector<int> ivec3(10,6);//construct 'vector_ivec3' by 10 elements with value 6.
    vector<int> ivec4(5); //construct 'vector_ivec4' by 5 elements with default_value(0).
    cout << ivec3[0] <<"\n"
         <<  ivec4[3] <<"\n"
         <<endl;
    return 0;
}