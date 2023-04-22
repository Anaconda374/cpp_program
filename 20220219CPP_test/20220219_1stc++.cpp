#include<stdio.h>
#include<iostream>
#include<cmath>

int main()
{
    int temp = 100;
    int sum = 0;
    while(temp){
        sum = sum + pow(temp%10, 2);
            temp = temp / 10;
    }
    std::cout<< sum <<std::endl;
    
    printf("hello,world!, test2!");
    return 0 ;
}
