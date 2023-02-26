#include<iostream>
#include<string>
/* 
   Revise the 'Sales_data' class to make it an abstract data type(have its own operation set and the implementation is inaccessable to users of the class.).
 */
 
 /* 
   'Member_fucntions' that be called with memeber operator'.' (such as .isbn(), .combine(const Sales_data&)) must be "declared" inside the class(may be defined inside or outside the class body). 
 * 
   'Nonmember_functions' that are part of the interface, such as 'add', 'read', and 'print', are declared and defined outside the class.
 */
 struct Sales_data{
    std::string bookNO;
    unsigned units_sold = 0;
    double revenue = 0 ;
    
    //new members declarations: operations on 'Sales_data' objects.
    std::string isbn();
    
    Sales_data& combine(const Sales_data&);
    
    double avg_price() const;
};



//nonmember 'Sales_data' interface function declarations:
Sales_data add(const Sales_data& , const Sales_data&);

std::ostream &print(std::ostream&, const Sales_data&);

std::istream& read(std::istream&, Sales_data &);


int main()
{
    return 0;
}