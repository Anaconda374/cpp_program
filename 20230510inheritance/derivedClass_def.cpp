#include<iostream>

/*
Inheritance in C++ is mainly for helping class_authors avoid "code duplication", it gives us a way to put all that common code between a number of classes into a "base class"--Like a template.
8/

/*
Syntax: " class DerivedClass : access_specifier BaseClass "
In the derived class declaration, the colon (:) followed by the access specifier (public, protected, or private) is used to specify the type of inheritance. The access specifier determines the visibility of the base class members in the derived class.
There are 3 types of inheritance:

1.public Inheritance: 
    When the derived class inherits from the base class using the public keyword, all the public members of the base class become public members of the derived class, and all the protected members of the base class become protected members of the derived class. 

2.protected Inheritance: 
    When the derived class inherits from the base class using the protected keyword, all the public and protected members of the base class become protected members of the derived class. 

3.private Inheritance:
    When the derived class inherits from the base class using the private keyword, all the public and protected members of the base class become private members of the derived class. 

NOTE: 
Private members of the base class are always not accessible in the derived class.The access specifier in the derived class declaration only determines how the members of the base class are inherited and accessed in the derived class. 
Also, the derived class can add new members and override existing members of the base class, as long as the access level allows it.

*/

//define a base class:
class GeneralEntity{    
public:
    float x, y;
    void move(float dx, float dy){
        x += dx;
        y += dy;
    }
};


//Define a derived_class that inherited from the bass class:    
class Player : public GeneralEntity{
// Now Class'Player' has inherited(contains) all public members of class'generalEntity'.
public:
    char name;
    void printName(){
        std::cout<< name <<std::endl;
    }
};

int main(){
    std::cout<<"The size of 'float': "<<sizeof(float) <<std::endl;
    std::cout<<"The size of 'char': "<<sizeof(char) <<std::endl;
    std::cout<< "The size of base class is: "<< sizeof(GeneralEntity) <<std::endl;
    //'GeneralEntity' contains 2 'float' members, its size should be 8. 

    std::cout<< "The size of derived class is: "<< sizeof(Player) <<std::endl;
    //'Player' inherited from 'GeneralEntity' and defines 1 'char' member itself, so its size is '9'. But due to "Data Structure Alignment" in memory, the output of 'sizeof(Player)' will be '12'.

    Player kuan;
    kuan.x = 1.2;
    kuan.y = 2.3;
    kuan.move(3, 5);
    std::cout<<"the coordinates of Player kuan is moved to: "<<kuan.x<<" "
    <<kuan.y<<std::endl;
}