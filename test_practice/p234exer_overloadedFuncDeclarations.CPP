#include<iostream>
#include<string>

int get(){
    int a;
    std::cin >> a;
    return a;
}
// double get(){
    // double d;
    // std::cin >> d;
    // return d;
// }
/* ERROR,ambiguating new declaration of 'double get()', since 'double' and 'int' can convert
 * to another implicitly.
 */
 
int *reset(int *){
    static int ival = 2;
    int* ip = &ival;
    return ip;
}

double *reset(double *){
    //OK, valid overloaded function, since 'double*' and 'int*' cannot convert into each other.
    static double dval = 2;
    double* dp = &dval;
    return dp;
}  
 
int main()
{
    int i = 8;
    double* dp = &i;
    
    std::cout <<  0 <<"\n"
         <<  0 <<"\n"
         <<std::endl;
    return 0;
}