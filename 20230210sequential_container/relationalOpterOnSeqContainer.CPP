#include<iostream>
#include<string>
#include<array>
#include<vector>
#include<list>

using namespace std;
/*
Relational operator returns a boolean value:
    Using relational operators can we compare whether 2 container objects have the same elements.
    Every container type supports the equality operators( == & != ).
    And all the containers(except the built-in 'array') also support the relational operators( > , >=, <, <= ), but the right- and left-hand operands must be the same kind of container and must hold elements of the same type.

NOTE:
    If the element type does not support the required operator, then we can not use the corrsponding operations on containers holding that type. For example, the element type is a self-defined class which not define relational operators on it.
 */


int main()
{
    vector<string> vec1 = {"kuan", "enero"};
    vector<string> vec2 = {"kuan", "febrero"};
    cout <<  (vec1 < vec2) <<endl;
    
    array<int, 3> arr1 = {3, 7, 4};
    array<int, 3> arr2 = {3, 7, 6};
    std::cout<< (arr1 <= arr2) <<endl;
    
    
    int arr3[] = {1, 2, 3};
    int arr4[] = {1, 2, 3};
    cout<<  (arr1 == arr2) << endl;//Caution! this statement actually compares the address of two containers, but not the elements inside.
    return 0;
}