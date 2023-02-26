#include<iostream>
#include<string>
#include<vector>
/*
    A class can declare "other classes" or "member functions of other classes" as its 'friend's. A 'friend' declaration just specifies the access to the class, it is not a real declaration for that friend.
 */
 
 
//Class 'Screen' definition:
class Screen{
friend class Window_mgr;
/* 
   Making "a member function"(for example'Window_mgr::clear') as a friend requires careful(Tedious, not suggested!:o) structuring of the program, to do so we must order our program as follows:
   1.First, define the Class'Window_mgr', and declare(but not define) the member funtion'clear' in it. Since Class'Screen' must be declared before 'clear', so that 'clear' can use the members of 'Screen'. 
   
   2.Second, define Class'Screen', including a friend declaration for 'clear'.
   
   3.Finally,define member function 'Window_mgr::clear' outside, which now can refer to the members in 'Screen'.  
   
   NOTE:Friendship is "not transitive", each class controls which classes or funtions are its friends.
 */
// friend void Window_mgr::clear(screenIndex);
// friend void window_mgr::newScreen(screenIndex, screenIndex, char);

    
public:
    typedef std::string::size_type pos;
    Screen() = default;
    Screen(pos ht, pos wd):height(ht), width(wd){}
    Screen(pos ht, pos wd, char c):height(ht), width(wd), contents(ht*wd, c){}
    char get() const { return contents[cursor];}
    inline char get(pos row, pos column) const; 
    Screen& move(pos row, pos column);
    Screen& set(char c){
        contents[cursor] = c;
        return *this;
    }
    Screen& display(std::ostream& os){
        do_display(os); 
        return *this;
    }
    
   
private:
    pos cursor = 0;
    pos height = 0, width = 0;
    std::string contents;  
    void do_display(std::ostream &os) const {
        for(pos i = 0; i <= contents.size(); i++){
            if( (i>0)&&((i%width) == 0)){
                os<<"\n";
            }
            os<< contents[i];
        }
        os<< "\r";
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



//Class 'Window_mgr' definition:
class Window_mgr{
    
public:
    using screenIndex = std::string::size_type;
    void clear(screenIndex index){
        Screen& s = (*this).screens[index];
        /* 
           Since Class'Window_mgr' is defined as a 'friend' in Class'Screen', so all the members of 'Screen' (such as 'height','width','contents') are accessible to the functions in 'Window_mgr'. 
         */
        s.contents = std::string(s.height * s.width, ' ');
    }
    void newScreen(screenIndex ht, screenIndex wd, char c){
        Screen temp(ht, wd, c);
        (*this).screens.push_back(temp);
        
    }
    void print(){
        for(auto& a : screens)
            a.display(std::cout);
    }
private:
    std::vector<Screen> screens {Screen(15, 25, 'c')};
  
};

int main()
{   
    Window_mgr testWin;
    testWin.newScreen(10,10,'a');
    testWin.print();
    testWin.clear(0);
    testWin.print();
    

    return 0;
}