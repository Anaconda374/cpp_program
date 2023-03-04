#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<functional>//'bind(...)' is defined in header 'functional' 


using namespace std;
using namespace std::placeholders;

//the '_n' names are defined in a namespace named 'placeholders' which is also defined inside the 'std' namespace.
using std::placeholders::_1;




/*
    It is not easy to write a function to replace a lambda that captures local variables.
    'bing(callable, argus)' function can be thought of as a general_purpose function adaptor. it takes a callable object(function or lambda...) and generates a new_callable that 'adapts' the parameter list of the original object.
 *
    
 
 */
//define a callable .
bool Check_size(const string& cstr, string::size_type sz){
        return cstr.size() >= sz;
    }
    
void addVector(int val, int& v){      
        v = v + val;
}

int main(){
    
//1. Use 'bind(...)' define a new callable that checks whether the string's size is longer than 6.
    auto check6 = bind(Check_size, _1, 6);//using placeholder'_1' stand for the first parameter of 'Check6' indicates we should input an argument which has the same type as the first parameter of 'Check_size' when we call the new callable 'check6'.
    
    cout<< check6("febrero")<< endl;
    
//2. Using 'bind', we can replace "the lambda_based call" with "Check_size(...)" to 'find_if(...)' .
    vector<string> strVec = {"ante", "postre", 
                                "supre", "inferior"};
    auto wc = find_if(strVec.begin(), strVec.end(), bind(Check_size, _1, 6));
    
    std::cout <<  *wc <<"\n"<<std::endl;
    
//3. binding reference parameters.
    vector<int> iVec = {20,23,02,27};
    
    int val = 5;
    //add a vector of values to 'val' by passing a reference to 'bind'.
    for_each(iVec.begin(), iVec.end(), bind(addVector, _1, ref(val)));

    cout<< val << endl;
    return 0;
}