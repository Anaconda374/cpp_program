#include<iostream>
#include<memory>
#include<new>

/*
When we allocate and free a dynamic memory using 'new' and 'delete' inside a function'f'(or a local block), if an exception happens between the 'new' and 'delete', and is not caught inside, then 'f' will be terminated at that exception, and the following code including 'delete' won't be excuted, so that the dynamic memory allocated by 'new' can never be freed. Since there is no pointer to this memory outside the function 'f'. Thus, there is no way to free this memory.
*/

int divide(int num1, int num2) {
    int* res = new int(0);
    if (num2 == 0) {
        throw std::runtime_error("Cannot divide by zero!");
        //If this exception occurs, it won't be caught inside 'divide', and 'res' won't be freed before the whole program ends.
    }
    *res = num1 / num2;
    std::cout << "Result: " << *res << std::endl;
    delete res;
}

int main() {
    int a, b;
    std::cin>>a>>b;
    try {
        divide(a, b);
    }
    catch (std::exception& e) {
        std::cout << "Exception caught: " << e.what() << std::endl;
    }
    return 0;
}