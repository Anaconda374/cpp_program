#include<iostream>
#include<istream>
#include<ostream>
#include<string>
using namespace std;

/* 
  A constructor is a special type of (overloaded)member function of a class which have the same name as the class used to initializes(or construct) objects of the class. In C++, Constructor is automatically called when object(instance of class) is created. 
  Each class defines how objects of its type can be initialized by defining one(or more) special member functions--Constructors. Constructors should not be declared as 'const', when we create a "const object" of a class type, the object does not assume its 'constness' until after the constructor completes the object's initialization.Thus, constructors can write values to "const  objects" during their construction.
 */
 
 
/*Synthesized Default Constructor: 

 The compiler-generated constructor is known as the "synthesized default constructor" which takes no arguments, and initializes each data member of the class as follows: 
    1.If there is an in-class initializer, use it to initialize the member.
    2.Otherwise ,default-initialize them member, the default value is undefined. 
*/


/*Defining constructors: 
 Some classes will have their own "class-defined constructor" since they cannot rely on the synthesized default constructor for some reasons:
 1.The compiler generates the synthesized default constructor only if we do not define any other constructors for the class. If the class defined a constructor for one member, then the rest members will also not have the default constructor. The basis for this rule is that if a class requires control to initialize one member, then the class is likely to initialize all its members.
 
 2.Like normal code blocks, the members of "built-in" or "compound type"(such as 'array' and 'pointer') that are defined inside a block have undefined value when they are default initialized.
 
 3.If a class has a member that has a class type, and that class does not have a default constructor, then the compiler cannot default initialize that member.
 
 Class-defined constructors have "the same name as the class". Unlike other functions, constructors have no return type. Like other functions, constructors have a (possibly empty) parameter list and a (possibly empty) function body. 
 A class can have multiple constructors, since they all have the same name, like any other overloaded function, the constructors must differ from each other in the number or types of their parameters.  
 */
struct Sales_data {
    //other members as before:
    std::string isbn() const {return bookNO;}
    Sales_data& combine(const Sales_data&);
    double avg_price() const;
    /*data member 'bookNO' has no in-class initializer, it's default-initialized to the "empty string".
     */
    std::string bookNO;
    
    //'units_sold
    ' and 'revenue' are initialized with '0'.
    unsigned units_sold = 0;
    double revenue = 0.0;
    
    //constructors added:
    /* 'Sales_data()= default' defines "a default constructor", a default constructor takes no parameters, using '=default' since we also want to provide "the object of this class" the synthesized default constructor except other class-defined constructors.
     */ 
    Sales_data() = default;
       
    /* "a parameterized constructor" defined with parameter list contains the different types of objects which are needed to initialize the data members, and the data members are initiazlied by a "constructor initializer list" preceded by colon-operator' : '.
     */
    Sales_data(const std::string& s): bookNO(s){}
    Sales_data(const std::string& s, unsigned n, double p):
                bookNO(s), units_sold(n), revenue(p*n) {}
    
    Sales_data(std::istream& is);//A declaration of constructor defined outside the class body.
    
};

//Declarations of nonmember functions: 
istream& read(istream& is, Sales_data& item);
ostream& print(ostream& os, const Sales_data& item);
Sales_data add(const Sales_data& lhs, const Sales_data& rhs);

Sales_data::Sales_data(std::istream& is){
    read(is, *this);
    /* This constructor has no constructor initializer list, it will take a input stream to initialize each data member of 'this' object by Function'read'. So after defining this constructor, every time we create a new Sales_data type object with a stream parameter, the program will automatically use that stream to initialize the object.    
     */
}



int main()
{
    Sales_data item1(std::cin);//using parameterized constructor to create and initilize a object.
    
    print(std::cout, item1); 

    
    
    return 0;
}


//member functions defined outside the class(explained in another file):
inline double Sales_data::avg_price() const {
    if (units_sold)
        return revenue/units_sold;
    else
        return 0;
}

 Sales_data& Sales_data::combine(const Sales_data& rhs){
    units_sold += rhs.units_sold;
    revenue += rhs.revenue;
    return *this;
 }
 
 
//nonmember functions definitions(explained in another file):
istream& read(istream& is, Sales_data& item){
    double price = 0;
    is >> item.bookNO >> item.units_sold >> price;
    item.revenue = price * item.units_sold;
    return is;
}

ostream& print(ostream& os, const Sales_data& item){
  
    os << item.isbn() << " " << item.units_sold << " "
       << item.revenue << " " << item.avg_price();
    return os;
}

Sales_data add(const Sales_data& lhs, const Sales_data& rhs){
    Sales_data sum = lhs;
    sum.combine(rhs);
    return sum;
    
}
