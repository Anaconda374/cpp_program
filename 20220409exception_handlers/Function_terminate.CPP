#include<iostream>
#include<string>
#include<stdexcept>

void printSum(int v1, int v2){
    try {
         if (v1 > 1000){
            throw '9';
        }
        std::cout << "max + min = " << v1 + v2 << std::endl;
    }catch(char x){ 
    /* NOTE: 
        if change the parameter into other type(such as 'char') in 'catch parentheses', then no match 'catch' is found to this thrown exception, this function will terminate.
        After that, that 'thrown exception' continues to search the handler in the outter  functions, if no appropriate 'catch' is found in the entire program, then the program will exit.
     */
                    std::cout << "max cannot greater than 1000, ErrorCode"<< x << std::endl;
                }
            }
             
    



int main()
{
    int max , min;
    while(std::cin >> max >> min){
        try {
            if(max < min){
                throw std::runtime_error("max must greater than min!");
            }
            printSum(max, min);
        }catch(std::runtime_error errMes){
              std::cout << errMes.what()
                      << "\nTry again? Enter y/n" <<std::endl;
            char c;
            std::cin >> c;
            if (!std::cin || c == 'n'){
                break;
            }
        }catch(int x){
            ;
        }
        
    }
    

    return 0;
}