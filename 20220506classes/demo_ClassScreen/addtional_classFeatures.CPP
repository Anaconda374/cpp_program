#include<iostream>
#include<string>
#include<vector>
/* 
    using a pair of cooperating classes 'Screen' and 'window_mgr' to demonstrate the addtional features include :
    'Type-member', 'Mutable data-member', 'In-class Initializer', 'member of Class-Type', 'Inline member-function','Returning *this'. 
 */

class Screen{
public:
/* 
Type-member: 
    a class can define its own local names for types, type-members defined by a class are subject(adj.) to the same access controls as any other member and may be either 'public' or 'private'.   
    If we do not want the users of class to know that the 'Screen' objects use a string to hold data, we can define 'pos' as a public member, so the users can only see(or use) 'pos' as the type of data members of 'Screen'.
    NOTE: a Type-member must defined before it is used, so that it usually appear at the beginning of the class. As a result, defining the 'public' section at the beginning of a class is a good practice.
 */
    typedef std::string::size_type pos;//also can be defined by Keyword 'using'.
   
    Screen() = default;
    Screen(pos ht, pos wd):height(ht), width(wd){}
    Screen(pos ht, pos wd, char c):height(ht), width(wd), contents(ht*wd, c){}
   //since 'constents' has Type'string', it can be initialized by constructing-form.
   
/*
In-line member funtions:
    1. Implicitly 'inline' :The member functions defined inside the class are automatically 'inline' by default.
    
    2. Explicitly 'inline': we can also explicitly declare a member function(which is defined outside) as 'inline' as part of its declaration inside the class body or on its definition that appears outside the class body, as long as this member function defined in the same header as the corresponding class definition.
 */
 
   char get() const { return contents[cursor];}//defined in class, implicit 'inline'.
   inline char get(pos row, pos column) const; //explicitly declare as 'inline' in the class.
   Screen& move(pos row, pos column);//explicitly 'inline' on its outside definition.
   
   void counterFunc() const;
   
   void print(){
       std::cout << this->contents <<std::endl;
   }
   
private:
    pos cursor = 0;
    pos height = 0, width = 0;
    std::string contents;
/*
Mutable data member:
    A 'mutable' data member is never 'const', it can be changed even it is a member of a "const object". Accordingly, a "const member function" may change a 'mutable' member.
 */
    mutable size_t access_counter;
    
};

inline Screen& Screen::move(pos row, pos column){//specifies 'inline'.
    pos rowNum = row * width;
    cursor = rowNum + column;
    return *this;
}

char Screen::get(pos row, pos column) const {
    return contents[(row* width) + column];
}

//A const member-function modifies the mutable data member'access_counter'. 
void Screen::counterFunc() const {++access_counter;}


/* 
Member of Class-Type:
    Define a window manager class that used to represent a collection of 'Screen' objects on a given display.
 */
class window_mgr{
    //Class'window_mgr' has a data member that is a vector with 'Screen' element.
private:
    std::vector<Screen> screens {Screen(24, 80, ' ')};
    /*
      In C++ ,it is recommended to use 'in-class' initializer("following an =" or "inside curly braces") to specify the default value of data member.
      When we initialize a data member of class type, we are supplying arguments to a constructor of that member's type. In this case, we list initialize the vector data member'Screens' with a single sized_specified blank 'Screen' element.  
     */
};

int main()
{
    Screen sc1(20,10);
    sc1.print();
   
    return 0;
}