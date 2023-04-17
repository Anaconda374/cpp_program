#include<iostream>
#include<set>
#include<vector>

class MES{
public:
    int num;
    MES(int x){num = x;}
};

bool compareMeses(const MES &lhs, const MES &rhs){
    return lhs.num < rhs.num;
}

//define a print_function of a multiset with struct 'MES' elements and a comparison predicate.
void printStrSet(std::multiset<MES, decltype(compareMeses)* > s){
    for(auto i : s){
        std::cout<< i.num <<" ";
    }
}


int main(){
    MES ereno(1);
    MES febreno(2);
    MES marzo(3);
    MES abril(4);
    /*define a multiset with self-defined comparison function:
  1st parameter indicates that this multiset has elements of the type 'MES'.
  2nd parameter 'decltype(compareMeses)' yields a function type, which indicates the comparison function takes 2 MES structures and return a bool value.  
*/
    std::multiset<MES, decltype(compareMeses)* > mesesMultiset(compareMeses);
    //we initialize multiset object 'meses' with comparison function 'compareMeses'(which is automatically converted into a pointer) means we are going to order the keys following function 'compareMeses'.

//after the definition of multiset, we need to use member function '.insert(...)' to assgin it.
    mesesMultiset.insert(ereno);
    mesesMultiset.insert(febreno);
    mesesMultiset.insert(marzo);
    mesesMultiset.insert(abril);

//all keys in mesesMultiset is ordered following the comparison funtion 'compareMeses'.
    printStrSet(mesesMultiset);

    
    return 0;
}