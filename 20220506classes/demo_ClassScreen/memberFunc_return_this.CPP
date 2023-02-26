#include<iostream>
#include<string>
#include<vector>

//Class 'Screen' definition:
class Screen{
public:

    typedef std::string::size_type pos;
    Screen() = default;
    Screen(pos ht, pos wd):height(ht), width(wd){}
    Screen(pos ht, pos wd, char c):height(ht), width(wd), contents(ht*wd, c){}
    char get() const { return contents[cursor];}
    inline char get(pos row, pos column) const; 
    Screen& move(pos row, pos column);
    void counterFunc() const;
    
//member-function 'set(char)' returns a reference to nonconst 'Screen'
    Screen& set(char c){
        contents[cursor] = c;//set the new character at the current cursor location.
        return *this;//returns "this modified object" as an lvalue. 
    }
//member-function 'display(std::ostream)' returns a reference to nonconst 'Screen'.
    Screen& display(std::ostream& os){
        do_display(os); 
        return *this;
    }
    /*
       As in any other context, when one member function calls another, the Pointer'this' is passed implicitly to "the called function". Thus, when nonconst function'display' calls const function'do_display', its own Pointer'this' is passed and converted from a 'pointer to nonconst' to a 'pointer to const' implicitly.
     */
    
   
private:
    pos cursor = 0;
    pos height = 0, width = 0;
    std::string contents;
    mutable size_t access_counter;
    
/* 
   In practice, well_designed C++ programs tend to have lots of small functions such as 'do_display' that are called to do the 'real' work of some other set of functions.
 */
    void do_display(std::ostream &os) const {
        os << contents;
    }
};

inline Screen& Screen::move(pos row, pos column){
    pos rowNum = row * width;
    cursor = rowNum + column;
    return *this;
}

char Screen::get(pos row, pos column) const {
    return contents[(row* width) + column];
}

void Screen::counterFunc() const {++access_counter;}



//Class 'window_mgr' definition:
class window_mgr{
    
private:
    std::vector<Screen> screens {Screen(24, 80, ' ')};
  
};


int main()
{
    Screen sc1(20,10,'c');
    sc1.move(3,4).set('y').set('x');
    sc1.display(std::cout);
    /* 
       Since member functions 'move(pos,pos)' and 'set(char)' return a lvalue(*this) ,so we can use their return values to call another member(function).
        
       NOTE: A const member function that return '*this' as a reference should have a return type that is a 'reference to const', and such that we won't be able to embed this kind of const member functions into a series of actions.
     */
    
    return 0;
}