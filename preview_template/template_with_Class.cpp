#include <iostream>

template<class T> //"template<class T>" y "template<typename T>" se pueden usar indistintamente en C++, 

//definir una plantilla clase (que usa un tipo difinido en plantilla):
class OptrTest{
public:
    T add(T value1, T value2){
        return value1 + value2;
    }
};

int main(){
    /*
    Si usa un tipo de 'plantilla' en una clase, necesita pasa una tipo cuando definir un objeto de la clase:
        La expresión "OptrTest<int> t" se refiere a la creación de una instancia de la clase "OptrTest" parametrizada con el tipo de dato "int". En otras palabras, se está creando un objeto de la clase "OptrTest" cuyos métodos y miembros utilizan el tipo "int".
    */
    OptrTest<int> i;//el miembro 'i.add' sumará 2 'int'
    std::cout<< i.add(3, 5) <<std::endl;


    OptrTest<std::string> s; //el miembro 's.add' agregara 2 'string'
    std::cout<< s.add("kuan ", "Anacs") <<std::endl;


    return 0;
}