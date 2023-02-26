#include<iostream>
#include<string>

/* 
    We cannot define parameters of function type, but can have a parameter that is a 'pointer_to_function'.
 */
 
 
int sum(int v1, int v2){
    return v1 + v2;
}
int dif(int v1, int v2){
    return v1 - v2;
}

//Defining a function with 'function' as the parameter:
int test_sum(int v1, int v2, int sum(int v1, int v2)){
    return sum(v1, v2);
    /* 
      when we define a function as a parameter, we cannot really use it(passing arguments to it), it's just a kind of declaration(or specification) of a function type which takes 2 'int' objects and return a 'int' object.
      when we use 'function_pointer' as the parameter, this will make more sence. 
     */
}

//Defining a function with 'function_pointer' as the parameter:
int (*pf)(int v1, int v2);
int select_func(int v1, int v2, int pf(int , int) ){
    return pf(v1 , v2);
    //In this definition way, the program is more readable.
}
//we can also define the pointer to function in the parameter list.
int select_func2(int v1, int v2, int (*pf)(int, int)){
    return pf(v1, v2);//functions the same as the function above.
}

int main()
{
    std::cout<< test_sum(1, 2, dif) <<std::endl;
    //We can even pass the function 'dif' as argument here. 
    
    
    int a, b, res;
    char o;
    std::cout << "please input 2 numbers: ";
    std::cin >> a >> b;
    std::cin.clear();
    std::cout << "please select a operation: sum(S)/ dif(D)";
    std::cin >> o;
    /* when we pass the function as an argument, we can do so directly, since itself cannot take arguments, and its function type is already defined in the parameter list.
     */
    if((o == 'S')|| (o=='s')){
        res = select_func(a,b,sum);
    }
    else if((o == 'D')|| (o=='d')){
        res = select_func(a,b,dif);
    }
    else{
          std::cout << "Invalid Input!" << std::endl;
          return 1;
    }

    std::cout << res << std::endl;
    
    return 0;
}