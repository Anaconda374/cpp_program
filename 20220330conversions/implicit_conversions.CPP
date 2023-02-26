#include<iostream>
#include<string>
#include<vector>

/* In addition to the arithmetic conversions, there are several kinds of implicit conversions: 
 */
 
int main()
{
//Array -> Pointer:
    int ia[10]{1, 3, 5, 7};
    int* ip = ia;
    /* 
       Excepts as the operand of "address_of&", "sizeof", "typeid" operators, or initialize a  reference to an array.  In most expressions, when we use an array, the array is automatically converted to a pointer to the first element in that array.  
     */     


//Integral/Literal -> pointer:
    char *cp = 0;
    int  *ip2 = nullptr; 
    //We can convert integral value of '0' and the literal 'nullptr' to any pointer type.
  


/* pointer -> voidpointer: 
 * A pointer to any nonconst type can be converted to 'void*', a pointer to any type(includeing 'const') can be converted to a 'const void*'. 
 */ 
    void* vp = ip;
    // std::cout<< (*vp)[2] << std::endl;//ERROR, void pointer'vp' has no associated data type.
    
    int (*ip3)[] = static_cast<int(*)[]>(vp);//OK,type 'void*' can be typecasted to any type.
    std::cout<< (*ip3)[2] << std::endl;


// " Reference or Pointer to Nonconst" -> "Reference or Pointer to Const": 
    int i1 = 17;
    const int &ri = i1; 
    const int *pi = &i1; 
    /* the address of a nonconst'int*' is converted to 'const int*' (only) in statement, but the type of 'i1' would not be changed.  
     */
     
    i1 = 18; //OK, we can still change 'i1' by assigning itself.
    // ri = 47;//ERROR,we can not change 'i1' by a "const reference"
    // *pi = 47;//ERROR,we can not change 'i1' by dereference a "pointer to const"
    std::cout<< *pi << std::endl;
    
    
// Conversions defined by Class types(in library):

//"C_style character string" -> "Library string"
    char carr[] = {'Z','e','n','\0'};
    std::string s1 = carr;
    //Class type 'string' defines this conversion that the compiler will apply automatically.
    std::cout << s1 << std::endl;
    
//"istream" -> "bool"
    std::vector<std::string> sv;
    std::string word;
    while(std::cin >> word){
    /* 'IO_library' defines a conversion from 'istream' to 'bool', the resulting bool value  depends on the state of the stream, so in a "condition", 'cin' is automatically be converted to a bool type. If the last read succeeded, then the conversion yields 'true', if the last attempt failed(meet 'end_file'), then the conversion to bool yields 'false'.
     */
        sv.push_back(word);
    }
    for(auto w : sv){
        std::cout<< w <<std::endl;
    }
  
    return 0;
}











