#include<stdio.h>

int main()
{
    char a[10];
    printf("Input the name:\n");
    fflush(stdout);
    scanf("%s",&a);
    printf("hello,%s",a);
    return 0;
}
