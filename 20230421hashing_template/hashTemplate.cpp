#include<iostream>
#include<functional>//Class(or Type) 'hash' is defined in Header<functional> under Namespace 'std'.

int main() {
/*
  'hash<key_type>' is an "unary function object class" that defines the default hash function used by the standard library.
  The standard library supplies version of 'hash' only for the built-in types, including pointers. 
*
  This Hash class only has one member function: 
  '()': It returns hashed value for given argument.
* 
  A hash value is a integral of Type'size_t' that depends solely on its argument, returning always the same value for the same argument (for a given execution of a program). 
*/
    std::string keyStr = "anacs";
    //The hash class is default constructible, which means that one can construct this object without any arguments or initialization values.
    std::hash<std::string> hashObj;
    std::cout<< "Hash value for \"anacs\" is " <<hashObj(keyStr)<< std::endl;
    return 0;
}