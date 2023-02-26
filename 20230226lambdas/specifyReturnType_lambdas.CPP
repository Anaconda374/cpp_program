#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include "d:\cpp_program\cpp_headers\ContainerPrinter.h"


using namespace std;

/*
By default, if a lambda body contains any statements other than "a return statement", then that lambda is assumed to return 'void'. like other functions that return 'void', lambdas inferred to return 'void' may not return a value.
 */

int main()
{
    vector<string> strVec = {"anterior", "posterior", 
                                "superior", "inferior"};
    
// 'transform(1stIter1, 1stIter2, destIter1, transFunction)' algorithm take a sequence of elements and transform each element according to 'transFunction' into the destination container. If the third iterator is also of the input container means to replace the element in that input container.
    transform(strVec.begin(), strVec.end(), strVec.begin(), 
        [](string str){return "cambiada";} );
        //OK, return type of lambda is deduce as 'string' type.
    printVector(strVec);
    
    
    vector<int> iVec = {-1, 3, -4, -6, 8, -9};
    //transform each negative value into its absolute value. 
    transform(iVec.begin(), iVec.end(), iVec.begin(),
        [](int i){if(i<0) return -i; else return i;});
        //a statement'if(...)' other than 'return ...' is used, compiler cannot deduce the return type. 
        //But right now it can deduce the return type without specification.
    printVector(iVec);
        
//specify the return type of lambda by using a "trailing return type".
    //transform each positive value into negative. 
    transform(iVec.begin(), iVec.end(), iVec.begin(),
        [](int i) ->int {if(i>0) return -i; else return i;});
    printVector(iVec);
    
    
    return 0;
}