#include<iostream>
#include<string>
using namespace std;

/* In c++ we use "access specifiers" to enforce encapsulation:
   'public:' Members defined after a 'public' specifier are accessible to all parts of the class users' program. The "public members" define the interface to the class.
   
   'private:' Member defined after a 'private' specifier are accessible to the member functions of the class but are not accessible to the class user's code that uses the class. The "private member sections" encapsulate(i.e., hide) the implementation. 
  
 */
class Sales_data {
/* Difference between Keywords 'class' and 'struct' for the class definition:
   If we use 'class', the members defined before the first access specifier are 'private', if we use 'struct', then those members are 'public'.
 */
public:
//The 'constructors' and 'member_functions(interface part)' follow the 'public' specifier.
    Sales_data() = default;
    Sales_data(const std::string& s): bookNO(s){}
    Sales_data(const std::string& s, unsigned n, double p):
                bookNO(s), units_sold(n), revenue(p*n) {}
    Sales_data(std::istream& is);
    std::string isbn() const {return bookNO;}
    Sales_data& combine(const Sales_data&);
     
private:
//The 'data_member' and 'member_functions(implementation part)' follow the 'private'.
    double avg_price() const;
    std::string bookNO;
    unsigned units_sold = 0;
    double revenue = 0.0;
 


friend Sales_data add(const Sales_data& lhs, const Sales_data& rhs);
friend istream& read(istream& is, Sales_data& item);
friend ostream& print(ostream& os, const Sales_data& item);
/* 
   A class can allow another class or funtion to access its 'nonpublic' members by making  that class of function a 'friend' by including a declaration for that function preceded by the Keyword 'friend'.
   
   Friend declarations may appear only inside a class definition(normal at the beginning or end). 
   NOTE: A friend declaration only specifies "the access to 'nonpublic' members", It is not a general declaration of the function. If we want users of the class to be able to call a friend function, we must declare it outside the class(general declaration) as well as in the same header as the class itself.
 */
};

//Declarations of friend(nonmember) functions: 
istream& read(istream& is, Sales_data& item);
ostream& print(ostream& os, const Sales_data& item);
Sales_data add(const Sales_data& lhs, const Sales_data& rhs);

Sales_data::Sales_data(std::istream& is){
    read(is, *this);
}


int main()
{
    Sales_data item1;
    print(cout, item1);
    std::cout<<std::endl;
    // std::cout << item1.bookNO <<std::endl;
    // ERROR, objects cannot access its private members.

    return 0;
}

//member functions defined outside the class(explained in another file):
double Sales_data::avg_price() const {
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