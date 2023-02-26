#include<iostream>
#include<string>
#include<list>
/*
 
 */

void print(std::list<std::string> lst)
{
   std::list <std::string>::iterator iter;
   for (iter = lst.begin(); iter != lst.end(); ++iter){
        std::cout<<*iter<<' '<<std::endl;
   }
}

int main()
{
    std::list<std::string> lst1;
    lst1.assign({"te ", "amo ", "juanjuan "});
    
    std::cout<< *(lst1.begin() ) <<"\n"
         <<  *(lst1.rbegin()) <<"\n"
         //'.rbegin()' is the reverse interator, which is opposite to '.begin'.
         <<std::endl;
    
    auto iter = lst1.begin();//'iter' is a nonconst_iterator.
    *iter = "cambiado ";//OK
    print(lst1);
   
//Define const iterator:
//1.deduced by using 'auto':    
    auto cIter = lst1.cbegin();
/*
   'cIter' is a const_iterator. Equivalent to "list<string>::const_iterator 1st1 = a.begin();"
*/
    // *cIter = "cambiado segundo";
    //Error, cannot change a element through a const_iterator.
    print(lst1);

//2.an iterator of const object is a const_iterator:
    const std::list<std::string> lst2 = {"buenos ", "dias."};
    auto Iter2 = lst2.begin();//Iter2 is a const_iterator.
    // Iter2 = "cambiado ";//Error.
    print(lst2);
    
    return 0;
}