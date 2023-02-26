#include<iostream>
#include<string>
//'const_cast' are most useful in the context of overloaded functions.

const std::string& shorterString(const std::string& s1, const std::string& s2){
    return s1.size() < s2.size()? s1 : s2;
}
/* Since 'low_level const' parameters(such as a reference to const) can also be assigned with 'non_const' objects.  In order for the function dealing with 'low_level const' and 'non_const' differently,
 * we can use 'const_cast' to cast(or cast away) the 'low_level const' in overloaded functions and return a different type. 
 */
 
 std::string& shorterString(std::string& s1, std::string& s2){
     auto &r = shorterString(const_cast<const std::string&>(s1),
                                                const_cast<const std::string&>(s2));
     return const_cast<std::string&>(r);
    /* In this function, we first call the "1st shorterString function" by casting the parameters as 'low_level const', and then cast away the returned 'low_level const' as 'non_const'.
     */
 }
 
// NOTE: The above demo_function is kind of tedious, we can simply write it as below.
// std::string& shorterString(std::string& s1, std::string& s2){
    // return s1.size() < s2.size()? s1 : s2;
// }
 
 

int main()
{
    const std::string cs1 = "zhou" , cs2 = "lijuan";
    std::string s1 = "AAA" , s2 = "Anacs";
    //shorterString(cs1, cs2) = "changed_const";
    //ERROR, cannot change the returned 'low_level const'.

    shorterString(s1 ,s2) = "changed_shorter";
    
    std::cout <<  s1 <<"\n"
         <<  cs1 <<"\n"
         <<std::endl;
    return 0;
}