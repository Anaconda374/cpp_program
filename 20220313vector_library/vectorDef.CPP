#include<iostream>
#include<string>
/* Remark: "Standard template library" is a library filled with container types, the word "template" means that "the underlying data type that the container contains" is actually up to you to decide.
 */
 
#include<vector>
/* 
  A vector is "a class template", except 'references'(since it is not a object), we can have vectors of most other(noreference) built-in types and most class types.In particular,we can even have vectors whose elements are themselves vectors.
 * 
  Like "a strings" ,a vector is also the same as "a dynamic array" with ability to resize itself automatically, when an element is inserted or deleted,the storage being handled(extend or shrink) automatically by function 'realloc(... , ...)'.
 *
 * 
   Thanks to this allocating mechanism, vector elements are placed in contiguous storage so that they can be accessed and trversed using iterators.
 */

int main()
{
    std::vector<int> ivec;
// "vector library" is in 'std' namespace, defining form is " std::vector<typeName> vectorName ".

    std::vector<std::vector<std::string>> file;//'file' is a vector whose elements are vectors.
    

    return 0;
}