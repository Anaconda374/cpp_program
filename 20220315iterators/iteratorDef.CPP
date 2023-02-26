#include<iostream>
#include<string>
/* 
   "iterators": can be virsualized as something similar to a pointer; an iterator is an object that enables a programmer to traverse a collection of values in a container.
 *
   Since all of the library containers have iterators, so "iterators" are more general than "subscripts/indice".
 *
   Unlike pointers, "types that have iterators" have members that return iterators: 
   ' .begin 'returns a iterator that denotes the first element;
   ' .end ' returns the "position" of "one past the end",this iterator denotes "a nonexistent element off the end" of the container,it is used as a marker indicating when we have processed all the elements.
 * 
   If the container is empty, '.begin' returns the same iterator as the one returned by '.end'.
*   
NOTE:
    When we use iterators in a loop, avoid storing the operator returned from '.end()', since after insert or erase the elements in a container, the orignially stored iterator is invalidated. the good idea is to call '.end()' to get the refreshed valide iterator in each trip of the loop.   
    
 */

int main()
{
    std::string s("i love you");
    if (s.begin() != s.end()) {//check if 's' is empty.
        auto it = s.begin(); 
/* 
    In general, we do not know(or care about) the precise type that an iterator has, so we use 'auto' to define the variables which have whatever type is returned by the '.begin' or '.end' member respectively.
 */     
        *it = toupper(*it);
/* 
    As with pointers, we can dereference an iterator to obtain the element denoted by ' *itVar '.
 * NOTE: 
        We may dereference only a valid iterator that denotes an element,dereference an invalid iterator or an off_the_end iterator has undefined behavior.
 */ 
    }
    std::cout <<  s <<"\n"
         <<  *(s.end()-1) <<"\n"//OK, return the last character of string 'u'.
         <<std::endl;
    if((s.begin()+3) == (s.end()-7))
/* if two iterators are denote exactly the same element(not to compare the characters), then they are equal. 
 */
        std::cout<< "these two characters are equal."<<std::endl;
    else 
        std::cout<< "these two characters are unequal."<<std::endl;
    return 0;
}