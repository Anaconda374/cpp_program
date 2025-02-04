#include<iostream>

/*
Keyword 'virtual':
    if we create a function in a base class and mark it as 'virtual', then we have the option of "overriding that function" in the derived class. And it's a best practice to add Keyword'override' after the overriding definition of the virtual function in the derived class.
*/
/*
Interfaces in Qt:
    Qt does not support multi_inheritance. Instead, the derived class using interface to link with multiple base classes, And "interface" is just fancier way of doing multiple inheritance. The only real difference with an interface is that you should have everything of the base classes as 'virtual'.
*/

//define a bass class:
class Entidad{
public:
    virtual void getName(){
        std::cout<< "El Nombre es Kuan." <<std::endl; 
    }
};

//define a derived class
class Jugador : public Entidad{
public:
    std::string nombre;

    //override the virtual function:
    void getName() override {
        std::cout<< "El Nombre es: "<< nombre <<std::endl; 
        //we can still force the program to call the function define in base class by using scope operator'::'
        Entidad::getName(); //For demonstration.
    }

};

void printName(Entidad* e){
    e->getName();
}



int main(){
    Entidad* e1 = new Entidad();

    Jugador* j1 = new Jugador();
    j1->nombre = "Anacs";
    printName(e1);

    //Although function 'printName' takes an argument of a Entity pointer, when we pass a pointer to Class'Jugador', the Function'getName()' in the definition of 'Entity' will be overrided.
    printName(j1); //Jugador* object 'j1' is implicitly converted into a 'Entidad*' object by C++ compiler.
    
    


}
