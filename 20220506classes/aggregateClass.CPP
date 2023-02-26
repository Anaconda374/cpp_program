#include<iostream>
#include<string>

/*
 "Aggregate classes" are classes with only public data members that has no in-class initializers or constructors. Members of objects of an aggregate class can be initialized by a brace_enclosed{...} list of initializers.
 */
class test_aggregate{
public:
    int i; 
    std::string s;
};
int main()
{
    test_aggregate obj1 = {2,"kuan"};
// OK, we cannot do this if the class members have in-class initializers. 
    std::cout<< obj1.i << "\n" <<obj1.s<<std::endl;
    
    return 0;
}