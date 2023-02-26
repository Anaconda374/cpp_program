#ifndef SALESDATA_H

#define SALESDATA_H


#include<iostream>
#include<string>
using namespace std;

class Sales_data {

public:

    Sales_data() = default;
    Sales_data(const std::string& s): bookNO(s){}
    Sales_data(const std::string& s, unsigned n, double p):
                bookNO(s), units_sold(n), revenue(p*n) {}
    Sales_data(std::istream& is);
    std::string isbn() const {return bookNO;}
    Sales_data& combine(const Sales_data&);
     
private:

    double avg_price() const;
    std::string bookNO;
    unsigned units_sold = 0;
    double revenue = 0.0;
 


friend Sales_data add(const Sales_data& lhs, const Sales_data& rhs);
friend istream& read(istream& is, Sales_data& item);
friend ostream& print(ostream& os, const Sales_data& item);

};


istream& read(istream& is, Sales_data& item);
ostream& print(ostream& os, const Sales_data& item);
Sales_data add(const Sales_data& lhs, const Sales_data& rhs);

Sales_data::Sales_data(std::istream& is){
    read(is, *this);
}


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
#endif