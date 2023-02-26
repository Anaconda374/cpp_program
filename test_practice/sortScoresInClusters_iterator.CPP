#include<iostream>
#include<string>
#include<vector>

int main()
{
    std::vector<unsigned> grades(11,0) ;
    unsigned score; 
    while(std::cin  >> score){
        (*(grades.begin()+ (score/10)))++;
    }
    for(auto i = grades.begin(); i != grades.end(); i++)
        std::cout << *i <<" score(s) in the range of "<<(i-grades.begin())*10
    //use 'iterator - iterator' can result in a signed int. 
    <<"~"<<((i-grades.begin())*10)+9<<"\n"
         <<std::endl;
    return 0;
}