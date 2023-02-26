#include<iostream>
#include<string>
/* 
   The primary purpose of namespaces is to avoid "naming conflicts" of functions in different headers or files.Using namespace operator ' :: ',we can actually dive into a certain area and use the functions or methods specifically inside it.
 */
 
using namespace std;
/* Stop " using namespace std; ", what the "using namespace ..." directive actually do is to import everything from that namespace, and doing so is kind of giving away the functionality of "defining namespace". when we use "std::functionName" to write our code,
 * Firstly it's good for readers, they can know what funtion(from which namespace) is actually using; 
 * Secondly we can avoid possible errors such as "naming conflicts"; 
 * Thirdly ,everything in c++ standard library is behind "std namespace", so we are not going to get naming conflicts in it.
 *
 * Tips: A good way to "using namespace ..." directive is declare it in a smaller scope, 
 * do not declare it in global scope, and "never" declare "using namespace ..." directives in header files.
 */
namespace apple{
    void print(){
     std::cout<<"apple namespace." <<std::endl;   
    }
}

namespace orange{
     void print(){
     std::cout<<"orange namespace." <<std::endl;   
    }
}
int main()
{
    apple::print();
    namespace o = orange;//we can create an alias of the namespace.
    o::print();
    
    return 0;
}