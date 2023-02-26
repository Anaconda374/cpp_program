#include<iostream>

int main()
{
    int i = 2, *p1 = &i, **p2 = &p1;
    std::cout << p1 <<"\n"
              << *p2 <<"\n" // *p2 == p1 == the address of i;
              << **p2 <<"\n"
              <<std::endl;
        


    return 0;
}