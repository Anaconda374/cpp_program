#include<iostream>
#include<string>
#include<vector>

/* Practice: count the number of input grades by clusters of 10 in the score range0~100.
 * The first cluster will count grades of 0~9, the second count of 10~19,and so on. The final 
 * cluster counts how many scores of 100 were achieved.
 * we can make this task by using "vector" and "bucket_sort" 
 */
int main()
{
    std::vector<unsigned> gradeCounts(11, 0);//use vector for 11 clusters/buckets,all initially 0.
    unsigned score;
    while(std::cin >> score){
        if(score<=100)
            gradeCounts[score/10]++;
    }
/* NOTE:the subscript operator'[]' on vector(and string) only fetches an existing element;
 * it doesnot add an element.
 */
    decltype(gradeCounts.size()) i = 0;
    while(i < gradeCounts.size()){
        std::cout << gradeCounts[i]
         <<std::endl;
         i++;
    }
    return 0;
}