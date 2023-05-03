#include<iostream>
#include<memory>
#include<vector>

/*
The 'shared_ptr' class automatically destroys the object to which that shared_ptr points, it does so through another special member function known as a 'destructor'.
    When a shared_ptr object goes out of scope or is explicitly reset(such as assigning it), the class 'shared_ptr' destructor first decrements the reference count and checks if it has reached zero. If it has, then the destructor calls "the destructor of the managed object", which frees any resources it was using. 
*
Classes with resourses that have "Dynamic Lifetime":
    Some classes allocate resources with a lifetime that is independent of the original object, which means different objects share the same elements stored in dynamic memory through 'shared_ptrs'. 
    And when two objects share the same underlying data, we cannot unilaterally destroy the data when one of the objects goes out of scope.
*/


//define a class 'StrBlob' which has "a shared_ptr member" which used to access a vector<string> stored in dynamic memory:  
class StrBlob{
public:
    typedef std::vector<std::string>::size_type size_type;
    //define 2 constructors:
    StrBlob() : //default_initialized.
        data(std::make_shared<std::vector<std::string>>()) {};

    StrBlob(std::initializer_list<std::string> il)://list_initialized.
        data(std::make_shared<std::vector<std::string>>(il)){};

    //define member functions like class 'vector<std::string>':
    size_type size() const {return data->empty();} 
    //'size()' is a const_member_function that cannot change the member. 
    void push_back(const std::string &t) {data->push_back(t);}

    //Declarations of member functions defined outside:
    void pop_back();
    std::string& front() const;
    std::string& back() const;

private:
    //define a share_ptr member 'data':
    std::shared_ptr<std::vector<std::string>> data;
    //define a function to throw an 'out_of_range' exception:     
    void check(size_type i, const std::string &msg) const{
        if(i >= data->size()){
            throw std::out_of_range(msg);
        }
    };
};

//define similar member function'front()' to return the reference to the first element: 
std::string& StrBlob::front() const {
    //if the vector is empty, 'check(...)' will throw.
    check(0, "ERROR, front() on empty StrBlob");
    return data->front();
}
//define the similar member function 'back()' to return the reference to the last element: 
std::string& StrBlob::back() const {
    check(0, "ERROR, back() on empty StrBlob");
    return data->back();
}
//define a member function to remove the last element:
void StrBlob::pop_back(){
    check(0, "ERROR, pop_back() on empty StrBlob");
    data->pop_back();
}

int main(){
/*
    Since our 'StrBlob' has an 'shared_ptr' member, therefore, it has all properties of 'shared_ptr' when we copy, assign, or destroy a 'StrBlob' object. 
    Thus, "the vector in dynamic memory allocated by the 'StrBlob' constructors" will be automatically destroyed when the last 'StrBlob' object pointing to that vector is destroyed.
*/   


    return 0;
}