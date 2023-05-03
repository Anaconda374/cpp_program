#include<iostream>
#include<memory>

int main(){
    std::shared_ptr<int> sp( new int(2023));
    
    //Initialize with a 'shared_ptr'
    std::weak_ptr<int> wp1(sp);
    
    //assign using a 'shared_ptr' or 'weak_ptr',
    std::weak_ptr<int> wp2 = wp1;

    //'w.use_count()' returns the number of 'shared_ptr(s)' that share ownership with 'w'.
    std::cout<<"The number of shared_ptr(s) is: "<< wp2.use_count()<<std::endl;

    //'w.expired' checks whether 'w.use_count()' is 0, returns a boolean value.
    std::cout<<"wp2 has no shared_ptr companion："<< wp2.expired()<<std::endl;

    //'w.lock()', if 'w.expried' is 'TRUE', returns a null 'shared_ptr'; otherwise, returns a 'shared_ptr' to the object to which 'w' points. It is often used to assgin a 'shared_ptr' or access the obejct.
    std::cout<< "The value stored in wp2 is: "<<*(wp2.lock())<<std::endl;

    //'w.reset()' makes 'w' null:
    wp2.reset();

    return 0;
}