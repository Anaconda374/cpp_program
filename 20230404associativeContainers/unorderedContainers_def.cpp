#include<iostream>
#include<unordered_set>


/*
  The standard C++ 11 defines 4 unordered associative containers('unordered_map', 'unordered_set', 'unordered_multimap', 'unordered_multiset').
* 
  Unlike ordered containers, the unordered containers are organized as a collection of buckets, each of which holds zero or more elements. 
  Rather than using a comparison operation to organize their elements in order, these containers use "a hash function" to map elements to buckets, and use "the key type's equality operator== " to find the target element stored in a bucket.
*
  It is usually easier(and often yields better performance) to use an ordered container, but we can use an unordered container if the key type is inherently unordered(like pointers) or if performance testing reveals problems that hashing might solve.
*
  NOTE: Elements with the same key are stored adjcent to one another in both the ordered and unordered containers(since hashing the same key always produces the same hash_code).
*/

class Professor{
public:
    int idNum;
    std::string name;
    Professor(int id, std::string n){
        idNum = id;
        name = n;
    }
};

/*
Self_defined 'hashing_function' and 'key_equality_operator':
    we can directly define unordered containers whose key is one of the built-in types(including pointer type) or a string, or a smart pointer. 
    But we cannot directly define an unordered container that uses a our own class type for its key type because we cannot use the hash template directly(since 'hash<key_type>' in STL only supports for built-in types). Instead, we must supply our own version "hash template" and "equality operator" when we define an unordered container with keys of self_defined class type.
*/

//define an own version hash template for self_defined class 'Professor':
size_t hasher(const Professor& pro){
    std::hash<int> hashObj;
    return hashObj(pro.idNum);//use the class's int member 'idNum' as the hashing argument.
}

//define an own version equality operator for self_defined class 'Professor':
bool equalOptr(const Professor& lhs, const Professor& rhs){
    return lhs.idNum == rhs.idNum;
}



int main(){

//define  own multiset type 'Professor_multiset' that has elements of Type'Professor' and a "hashing function type" and "equality function type". 
    using Professor_multiset = std::unordered_multiset<Professor, decltype(hasher)*, decltype(equalOptr)*>;
    
    //create a 'Professor_multiset' object with given arguments(the size of each bucket, Pointer to the hash function, Pointer to the equality operator)  
    Professor_multiset pros(8, hasher, equalOptr);

    Professor a(111, "Ramirez");
    Professor b(202, "Anna");
    Professor c(330, "Manuno");
    Professor d(44, "Carmen");
    
    pros.insert(a);
    pros.insert(c);
    pros.insert(d);
    pros.insert(b);
    
    //print all elements in 'pros'.
    for(auto &elem : pros){
        std::cout <<"Id: "<<elem.idNum<< "\n" << "Name: "<<elem.name<<std::endl;
    }//from the output, we can see the elements are not stored in order.

/*
Other member functions exclusively for unordered containers(see detail on P445 c++_primer):
    Since unordered containers store elements in buckets using hashing function, they provide some functions to deal with its 'buckets' and 'hashing function'. 
*/
    std::cout<<"Number of buckets in use: "<<pros.bucket_count()<<std::endl;
    std::cout<<"Largest number of buckets the container can hold: "<<pros.max_bucket_count()<<std::endl;


    return 0;
}