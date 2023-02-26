#include<iostream>
#include<istream>
#include<ostream>
#include<string>
using namespace std;

/*
A constructor that can be called with a single argument defines an implicit conversion from the constructor's parameter type to the class type.
 */

class Sales_data {
friend istream& read(istream& is, Sales_data& item);
friend ostream& print(ostream& os, const Sales_data& item);
friend Sales_data add(const Sales_data& lhs, const Sales_data& rhs);
public:
    std::string isbn() const {return bookNO;}
    Sales_data& combine(const Sales_data&);
    double avg_price() const;
    Sales_data() = default;
    Sales_data(const std::string& s): bookNO(s){}
    Sales_data(const std::string& s, unsigned n, double p):
                bookNO(s), units_sold(n), revenue(p*n) {}
/* 
'explicit' constructor:
    Using 'explicit' keyword on the constructor declaration inside the class(not repeated on the definition outside the class) can we prevent the use of a constructor in a context that requires an implicit. 
 */
    explicit Sales_data(std::istream& is);
    
private:
    std::string bookNO = "123-x";
    unsigned units_sold = 0;
    double revenue = 0.0;
};

istream& read(istream& is, Sales_data& item);
ostream& print(ostream& os, const Sales_data& item);
Sales_data add(const Sales_data& lhs, const Sales_data& rhs);

Sales_data::Sales_data(std::istream& is){
    read(is, *this);
}



int main()
{
    Sales_data item;
    print(cout,item);
    std::cout<< "\n";
    string null_book = "999-999" ;
    item.combine(null_book);
    /* 
     the member function 'combine' should take a Sales_data object. So in this case, the compiler automatically creates a Sales_data object from the given string'null_book' with members 'unit_sold' and 'revenue' equal to 0, like calling Constructor'Sales_data(const std::string& s): bookNO(s){}' implicitly. Then this newly generated(temporary) Sales_data object is passed to 'combine'. 
     */
    print(cout, item);

//Only One-step class-type Conversion is allowed:
    // item.combine("999-999");
    //ERROR, this statement takes two steps of conversions.1. convert literal"999-999" to a 'String'; 2. convert that 'string' to 'Sales_data'. 
    

    
/* 
    use 'static_cast' to force a conversion explicitly in order to use the 'explicit' constructor:
*/ 
    //item.combine(cin);
    //ERROR, the constructor'Sales_data(std::istream& is)' is declared explicit.
    item.combine(Sales_data(cin));
    item.combine(static_cast<Sales_data>(cin));
    print(cout, item);
    
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
    bookNO = rhs.bookNO;
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