#include<iostream>
#include<algorithm>

using std::cout;
using std::cin;
using std::endl;
int main()
{
    int v1 = 0, v2 = 0;
    int a,b;
    cout << "Input two numbers: " << endl;
    cin >> v1 >> v2;
    a = std::max(v1,v2);
    b = std::min(v1,v2);
    cout << "the numbers in this range are :" << endl;
    for(b ;b <= a;b++)
        cout << b <<endl;
    return 0;
}