#include<iostream>
#include<string>
#include<vector>
#include<iterator>
#include<array>
#include<list>
/*
 
 */

using namespace std;

void printVector(vector<int> vec){
    
    vector<int>::iterator iter;
    for(iter = vec.begin(); iter!= vec.end(); ++iter){
        std::cout<<*iter<<' '; 
    }
    cout<<endl;
}


int main()
{
//1.list initial
    vector<int> vec1 = {1, 2, 3, 4, 5};
    
//2.copy initial
    vector<int> vec2(vec1);

//3.iterator initial
    vector<int> vec3(vec1.begin(), vec1.begin()+2);
    
//4.size-related initial
    vector<int> vec4(6, 6);

//5.array initial
    int arr[] = {0, 3, 0, 5};
    //we should use built-in array here, the c++ type array does not work for initilization.
    int arrLength = sizeof(arr)/sizeof(arr[0]);
    vector<int> vec5(arr, arr+arrLength);

//6.sequential container(such as 'deque', 'list') initial
    list<int> lst = {2, 0, 2, 3};
    vector<int> vec6(lst.begin(), lst.end());
    
    
//print all vectors:
    printVector(vec1);
    printVector(vec2);
    printVector(vec3);
    printVector(vec4);
    printVector(vec5);
    printVector(vec6);
    
    std::cout << "\n"<<  0 <<std::endl;
    return 0;
}