#include<iostream>
#include<string>
#include<cstddef>
#include<iterator>

struct Accounts {
    std::string name;
    std::string id;
    std::string password;
};

void printAccount(std::string accName, struct Accounts acc[], int num);

int main(){
    
//Accounts lists(3):
    unsigned int size = 10;
    struct Accounts acc[size] , *p = acc;
    
    
// Apple account:
    acc[0].name = "apple";
    acc[0].id = "anacs_c@163.com";
    acc[0].password = "!Mcline1995";
    //Recovery Key: 9RBL-BYNG-Q524-AGKS-36EG-QGQM-4RLB
    
// Google account
    acc[1].name = "google";
    acc[1].id = "cj.anacs@gmail.com";
    acc[1].password = "!mcline1994";
    
// Hutao account:
    acc[2].name = "hutao";
    acc[2].id = "cj.anacs@gmail.com";
    acc[2].password = "mcline1995";
    
// 计算机等级考试：
    acc[3].name = "ncre";
    acc[3].id = "964951816@qq.com";
    acc[3].password = "!Caojieyong1995";
 
// bilibili account:
    acc[4].name = "bilibili";
    acc[4].id = "18975383769";
    acc[4].password = "mcline1995";

//软考报名：
    acc[5].name = "ruankao";
    acc[5].id = "18975383769";
    acc[5].password = "Mcline1994";
    
//pets-5    
    acc[6].name = "WSK";
    acc[6].id = "430902199512094518";
    acc[6].password = "!Caojieyong1995";    
    
//github   
    acc[7].name = "github";
    acc[7].id = "Anaconda374/anacs_c@163.com";
    acc[7].password = "Mcline1994";

//JD shopping   
    acc[7].name = "jingdong";
    acc[7].id = "18975383769";
    acc[7].password = "mcline1995";

//裁判文书
    acc[8].name = "caipanwenshu";
    acc[8].id = "18975383769";
    acc[8].password = "Mcline1994";
    
//ZTE router manager
    acc[9].name = "ZTE";
    acc[9].id = "admin";
    acc[9].password = "Mcline1994";
 

 
    std::string accName;
    std::cin >> accName;
    printAccount(accName, p, size);
    

    return 0;
}



void printAccount(std::string accName, struct Accounts acc[], int num){
    for (struct Accounts *pa = acc; pa != &acc[num]; ++pa){
        if (accName == (*pa).name){
            
            std::cout<<"\n" <<"id: "<< (*pa).id <<"\n"
              <<"pw: "<<(*pa).password<<"\n"
              <<std::endl;
            return;
        }
        
    }    
    std::cout<< "404" <<std::endl;
   
}