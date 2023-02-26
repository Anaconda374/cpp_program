#include<iostream>
#include<string>
#include<vector>
/* When we using an increament or decrement operator in an expression,
    "Prefix operators": meaning the variable is "incremented or decremented" first and then  the expression is evaluated using the new value of the variable.
 *
    "Postfix operators": meaning the expression is evaluated first using the original value of the variable and then the variable is incremented or decremented.
    what the postfix increment operator actually do underlying is "returns a copy of its original unincremented operand, and then increments itself by 1. 
 */

int main()
{
    int a = 5;
    int b = a++; //'b' = 5 , 'a' will increment to 6  after the evaluation in this expression.
    
    int c = ++a; //'a' = 7
    std::cout << b <<"\n"
         <<  c <<"\n"
         <<std::endl;

//"postfix operator" in compound expressions:
    std::vector<int> vi = {3, 5, 7, 9, -1, -3};// a vector contains signed ints.
    
    auto pbeg = vi.begin();
    //printing the values of all elements in the Vector'vi' unless it is a negative value.
    while(pbeg != vi.end() && *pbeg >= 0){
        
        std::cout <<"the NO."<< pbeg - vi.begin() << " element is :"
        << *pbeg++ << std::endl;
    /* 
       The precedence of postfix incerement 'pbeg++' is higher than the dereference operator '*pbeg', s.t. *pbeg++ == (pbeg++). But due to the mechanism of postfix operators, the operand of dereference operator'*' is the unincremented value of ' *pbeg '.
    */
        
    }
    
/* NOTE: 'Operands' can be evaluated in any order, this lack of guaranteed order often doesnot matter, but it does matter when one suexpression changes the value of an operand that is used in another subexpression.
 */ 
 
    //*pbeg = topper(*pbeg++)
    
    /* Caution, this assignment is undefined ,since we do not know whether "left_hand side" or
     * "right_hand side" is evaluated first.
     * if left_hand evaluated first, then this statement equals to: *pbeg = topper(*pbeg) 
     * if right_hand evaluated first, then this statement equals to: *(pbeg+1) = topper(*pbeg) 
     */
    return 0;
}