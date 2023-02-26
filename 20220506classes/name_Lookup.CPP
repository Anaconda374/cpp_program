#include<iostream>
#include<string>

/*
Ordinary "Name Lookup"(the process of finding which declaration match the use of name):
    1.First, Look for a declaration of the name in the block in which the name was used. Only names declared before the use are considered.
    2.If the name isn't found, look in the enclosing scope(s).
    3.If no declaration is found, then the program is in error.
 */

/*
    Since the class' definition are processed in two phases: First, the member declaration are compiled(abide by the ordinary Name Lookup), Second, the member function bodies are processed only after the compiler processing all the of the declaration in the class, so the member function bodies can use any name defined inside the class.
"Name Lookup" inside Member definitions:
    1.First, look for a declaration of the name inside the member function which declared before the use of the name.
    2.Second, look for a declaration inside the class. All the members of the class are considered.
    3.Finally, look for in the enclosing scope of member function definition outside the class definition.
 */
int height = 2;
class Screen {
public:
    typedef std::string::size_type pos;
    /* 
        Type names cannot be redefined in a class after that type name is used, so the definition of type members should appear at the beginning of the class. 
     */
    
    
    void test_fcn1(pos height){
    //NOTE: It's a bad idea to use the same name for a parameter and a member.
        cursor = width * height; //the parameter 'height' matched.
    }
    void test_fcn2(){
        cursor = width* this->height; // the data member 'hegiht' matched.
    }
    void test_fcn3(){
        cursor = width* ::height;//the global 'height' matched
        /*
        If we want the name from the outer scope, we can ask for it explicitly using the scope operator'::'.
         */
    }
    
private:
    pos cursor = 0;
    pos height = 0;
    pos width = 0;
};


int main()
{
    
    
    
    std::cout <<  0 <<"\n"
         <<  0 <<"\n"
         <<std::endl;
    return 0;
}