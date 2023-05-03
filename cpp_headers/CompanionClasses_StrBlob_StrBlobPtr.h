#ifndef STRBLOB_H

#define STRBLOB_H

#include<iostream>
#include<memory>
#include<vector>

//declaration of 'StrBlobPtr':
class StrBlobPtr;

//define a class 'StrBlob' which has "a shared_ptr member" which used to access a vector<string> stored in dynamic memory:  
class StrBlob{
//declare 'StrBlobPtr' as a 'friend', so it can access the private member 'data'.
friend class StrBlobPtr;

public:
    typedef std::vector<std::string>::size_type size_type;
    //define 2 constructors:
    StrBlob() : //default_initialized.
        data(std::make_shared<std::vector<std::string>>()) {};

    StrBlob(std::initializer_list<std::string> il)://list_initialized.
        data(std::make_shared<std::vector<std::string>>(il)){};

    //define member functions like class 'vector<std::string>':
    size_type size() const {return data->size();} 
    //'size()' is a const_member_function that cannot change the member. 
    void push_back(const std::string &t) {data->push_back(t);}

    //Declarations of member functions defined outside:
    void pop_back();
    std::string& front() const;
    std::string& back() const;

    //Since the member functions '.begin()' and '.end()' will return a 'StrBlobPtr' object, but class 'StrBlobPtr' is not defined yet at this position, so we have to define these 2 member functions after the definitions of 'StrBlobPtr'.
    StrBlobPtr begin();
    StrBlobPtr end();
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


/*
Define a companion pointer class'StrBlobPtr' for Class'StrBlob'to illustrate the use of 'weak_ptr':
    we will create a 'weak_ptr' to the data member of the 'StrBlob' from which it was initialized. Using a 'weak_ptr' does not affect the lifetime of the vector to which a given 'StrBlob'(using a shared_ptr) points. However, we can prevent the user from attempting to access a vector that no longer exists.
*
    Now we can define Member Functions'.begin()' and '.end()' to Class'StrBlob',each returns a 'StrBlobStr' as an iterator which can be used to access the elements in 'vector<string>'.
*/
class StrBlobPtr{
private:
    std::weak_ptr<std::vector<std::string>> wPtr;
    std::size_t currPos;// Current position in the vector, used to access the string elements in the vector.
    //declaration of Function 'posCheck':
    std::shared_ptr<std::vector<std::string>> //The return type.
        posCheck(std::size_t pos, const std::string& msg) const;
    
public:
    //Define constructors:
    StrBlobPtr(): currPos(0) {};
    StrBlobPtr(StrBlob& StrBlobObj, std::size_t sz = 0):
         wPtr(StrBlobObj.data), currPos(sz) {} 
         //'StrBlobPtr' is a friend of 'StrBlob', so private member 'data' is accessible now.
    
    //Define a function to dereference the string at 'currPos' in the vector:
    std::string& deref() const{
        std::string errMsg = "Dereference past end!";
        auto p = posCheck(currPos, "errMsg");
        return (*p)[currPos];
    }
    //Define a function to increment the 'currPos', and return the modified 'StrBlobPtr&'
    StrBlobPtr& incr(){
        std::string errMsg = "Increment past end!";
        //check if 'currPos' already past the end of the container, cannot increment it
        posCheck(currPos, errMsg);
        ++currPos;//if no exception thrown, increment 'currPos'.
        return *this;
    }

    //Define equal relational operator '==' for 'StrBlobPtr' objects:
    bool operator==(const StrBlobPtr& other) const{
        auto lhs = this->wPtr.lock();
        auto rhs = other.wPtr.lock();
        return (lhs == rhs) && this->currPos == other.currPos;
    }

};

//define a const member function'posCheck' to check whether the object to which 'this->wPtr' points is still existed and input argument'pos' is valid. If so, return a 'shared_ptr'. Otherwise, throw an exception and output the corresponding error message:
std::shared_ptr<std::vector<std::string>> //The return type.
StrBlobPtr::posCheck(std::size_t pos, const std::string& msg) const{
        auto ret = wPtr.lock();
        //If the 'weak_ptr' or Argument'pos' is invalid, throw an exception:
        if(!ret){ 
            throw std::runtime_error("This StrBlobPtr is unbound to any object now!");
        }
        if(pos >= ret->size()){ throw std::out_of_range(msg);}
        //Otherwise, return a 'shared_ptr' which used to access the vector:
        return ret;
    }

//Define member functions 'begin' and 'end' after the definition of 'StrBlobPtr':
StrBlobPtr StrBlob::begin() {
        return StrBlobPtr(*this);
    }
StrBlobPtr StrBlob::end() {
        auto ret = StrBlobPtr(*this, data->size());
        return ret;
    }

#endif