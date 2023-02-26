#include<iostream>
#include<string>

/* 
Nonmember_functions(also called 'Auxiliary_functions') define operations that are conceptually part of the interface of a Class, but they are not part of the class. Auxiliary_functions are typically declared(may not defined) in the same header as the class itself. That way users only need to include one file to use any part of the 'interface' of the class.  
 */

istream& read(istream& is, Sales_data& item){
    /* By defining a istram_withassign type reference 'is' to read datas from input_steam, and interpret datas into the members of the given object'item'.
     */
    double price = 0;
    is >> item.bookNO >> item.units_sold >> price;
    item.revenue = price * item.units_sold;
    return is;
}

ostream& print(ostream& os, const Sales_data& item){
    eam& read(istream& is, Sales_data& item)
{   /* By defining a ostram_withassign type reference 'os' to get the datas of members,
     * and interpret datas into the output_stream.
     */
    os << item.isbn() << " " << item.units_sold << " "
       << item.revenue << " " << item.avg_price();
    return os;
}
/* Since The IO classes are types that cannot be copied, so we may only pass and return them by reference. Moreover, reading or writing to a stream may changes that stream (to which 'is' or 'os' refers), so both functions take ordinary references,not references to 'const'.
 */

Sales_data add(const Sales_data& lhs, const Sales_data& rhs){
    //NOTE: define 'const' parameters if do not need to change the arguments.
    Sales_data sum = lhs;
    sum.combine(rhs);
    return sum;
    
}


int main()
{
    
    return 0;
}