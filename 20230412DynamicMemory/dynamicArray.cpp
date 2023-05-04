#include<iostream>
#include<new>

/*
Some applications, need the ability to allocate storage for many objects at once(such as 'vector'). To support such usage, the language and library provide 2 ways to allocate an array of objects at once:
    1. C++ defines a second kind of 'new' expression that allocates and initializes an array of objects, which is called -- Dynamic Arrays.
    2. The standard library includes a template class named 'allocator' that let us seperate allocation from initialization.
*
NOTE: Most applications should use a library container rather than dynamically allocated arrays. Using a container is easier, less likely to contain memory_management bugs, and is likely to give better performance.
*/


int main(){
//Allocate a dynamic array:
    int* ip = new int[10];
/*
NOTE: 'ip' has Type'int*' and it points to the first element, When we use 'new' to allocate an array we do not get an object with an array type. Instead, we get a pointer to the element type of the array.
*/
    
//Default initialization of a dynamic array with "a empty parentheses()":
    std::string* sp1 = new std::string[10]();
    //allocate a block of memory for 10 strings which are default initialized as empty strings "".

    auto p1 = new auto(sp1); // Caution! this 'new' does not allocate a dynamic array.
/*
NOTE: Although we can use empty parentheses to value_initialize the elements of an array, we cannot supply an element initializer inside the parentheses. And by this fact, we also cannot use 'auto' to deduce from another array to allocate an array.
*/

//Initialize a dynamic array with "a braced list{...}": 
    std::string* sp2 = new std::string[5]{"botella", "mochila",};
    //allocate a block of memory for 5 strings, the first two are initialized from the given initializers, remaining elements are value initialized.


//Allocate an array by using a "type alias":
    typedef int arrT[42]; //'allT' names the type array of 42 integers.
    int* ip2 = new arrT; // Allocate an array of 42 ints; 'ip2' points to the first one element.


//Treverse the dynamic array using arithmetic operations of pointers:
    std::size_t sz = 3; //pre_record the size of the dynamic array.
    std::string* sp3 = new std::string[sz]{"botella", "mochila", "mesa",};
    for(std::string* q = sp3; q != sp3 + sz; ++q ){
        std::cout<<*q<<std::endl; //print all strings in the dynamic array.
    }


//Free dynamic array using 'delete' and 'square brackets[]':
    delete [] ip; 
    /* Destroys the elements in the array to which 'ip' points and frees the corrsponding memory. 
    since 'ip' only points to the first element in the array, if we want to free the whole array, the empty bracket pair is essential.
    Caution: if "we forget the brackets when we 'delete' a pointer to an array" or if "we use brackets[] when we 'delete' a pointer to an object." The compiler is unlikely to warn us and apt to misbehave.
    */
    return 0;
}



