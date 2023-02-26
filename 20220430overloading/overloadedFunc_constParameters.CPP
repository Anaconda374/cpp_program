#include<iostream>
#include<string>
/* 
   In overloaded functions, a parameter that has a 'top_level const' is indistinguishable from the 'non_const' parameter, since for both 'top_level const' and 'non_const' parameters, they are all "copy_initialized". 
 */
void printDouble(int* const cpi){
    std::cout << (*cpi) *2 << std::endl;
}
// void printDouble(int* i){ //ERROR, redeclares 'void printDouble(int*)'.
  // ;
// }


/* But we can overload based on the parameter is a 'low_level const'(a pointer or reference to a const object), which is distinguishable from the 'non_const' or 'top_level const'.
 */
 
void printDouble(const int * pci){//OK, parameter is a 'low_level const'.
    std::cout << (*pci)*2 << std::endl;
 }

int main()
{
    int v1 = 8;
    int* const pi = &v1;
    printDouble(pi);
    
    const int cv2 = 6;
    const int * pc = &cv2;
    printDouble(pc);
    
    
    std::cout <<  0 <<"\n"
         <<  0 <<"\n"
         <<std::endl;
    return 0;
}