#include<iostream>
#include<fstream>
#include<sstream>
#include<new>
#include<vector>
#include<memory>
#include<map>
#include<set>

/*
The TextQuery Program will let a user search a given file for "a word" that might occur in it. And the result of a query should contains:
        1. The number of time the target word occurs;
        2. A list of lines(marked by its line number) on which that word appears. If a word occurs more than once on the same line.  
*
Data structures involved in this program:
    1. vector<string>: store a copy of the entire input file
    2. istringstream: break each line into words.
    3. set<int>: "each set" to hold the line numbers on which "each word" in the input appears?
    4. map<string, set<int>>: associate "each word" with "the set" of line numbers on which the word appears.
*/

using line_Num = std::vector<std::string>::size_type;

/*
Define class'QueryResult' which is a member of 'TextQuery':
    'QueryResult' is used to represent the result of a query. The result data which are stored in objects of type 'TextQuery'. We could avoid making copies(which may be costy) by returning iterators or pointers to the 'TextQuery' object. 
*
    But what happens if the 'TextQuery' object is destroyed before a corresponding 'QueryResult'? In that case, the 'QueryResult' would refer to data in an object that no longer exists. Such that we need to use 'shared_ptr'.
*/
class QueryResult{
//A friend function used to print the query result.
friend std::ostream& print(std::ostream& os, const QueryResult& qr);

public:
//Define the constructor:
    QueryResult(std::string wd, 
                std::shared_ptr<std::set<line_Num>> setPtr, 
                std::shared_ptr<std::vector<std::string>> file):
                word(wd), linesSet(setPtr), fileVec(file){}
private:
    std::string word;
    std::shared_ptr<std::set<line_Num>> linesSet;
    std::shared_ptr<std::vector<std::string>> fileVec;
};


/*
Define Class'TextQuery':
    The user will create objects by supplying an 'ifstream' from which to read the input file. 
    This class also provides the query operation that will take a string and return a 'QueryResult' representing the lines on which that string appears.
    Class'QueryResult' will share the vector representing the input file and the sets that hold the line numbers associated with each word in the input.
    Hence, our class has 2 date members: a "shared_ptr to a string vector holds all lines in the input file",  and a "map from string to shared_ptr<set>".
*/
class TextQuery{
public:
    
    //Define constructor:
    TextQuery(std::ifstream&);
    
    //Define Function'query' takes a 'string', and returns a 'QueryResult':
    QueryResult query(const std::string& word) const;

private:
    //The input file is load into a vector, each line for each element.
    std::shared_ptr<std::vector<std::string>> file;
    
    //Each word in the input file is associated with a 'shared_ptr' which points to a ;'set'
    std::map<std::string, std::shared_ptr<std::set<line_Num>>> wordMap;
};

//Definition of the constructor of 'TextQuery':
TextQuery::TextQuery(std::ifstream& ifs){
    file = std::make_shared<std::vector<std::string>>();
    std::string text;
    while(getline(ifs, text)){//seperate 'ifs' into lines.
        file->push_back(text); //push_back each line into the vector.
        int lineNum = file->size(); //the current line number (start from 1).
        
        //seperate the current line into words;
        std::istringstream line(text);
        std::string word;
        while(line>>word){
            //fetch the 'shared_ptr<set>' associated with 'word'.
            std::shared_ptr<std::set<line_Num>> lines = wordMap[word];
            // if 'word' is not already in 'wordMap', subscripting adds a new entry, and we allocate a set for it.
            if(!lines){lines.reset(new std::set<line_Num>);}
        
            //lastly, remember to insert this line number into the corresponding set which only stores unique numbers.
            lines->insert(lineNum); 
        }
    }
}

//Definition of Member Function 'query':
QueryResult TextQuery::query(const std::string &word) const{
    //if not find 'word', return a pointer bound to a empty set.
    static std::shared_ptr<std::set<line_Num>> nodata(new std::set<line_Num>);
    auto iter = wordMap.find(word);
    if(iter == wordMap.end()){
        return QueryResult(word, nodata, file); //not found.
    }
    else{
        return QueryResult(word, iter->second, file);
    }
}

//Define a print funtion to print the query result through a 'QueryResult' object:
std::ostream& print(std::ostream& os, const QueryResult& qr){
    //if the word was found, print the count and all occurrences:
    os<< qr.word<< " occurs " << qr.linesSet->size() << " time(s)." <<std::endl;

    //print each line in which the word appreared, if 'word' is not found, the set '*qr.linesSet' is empty, then this 'for' loop won't be executed.
    for(auto num : *(qr.linesSet)){
        //use 'num-1' as the index to retrieve the lines.
        os << "\t(line " << num << ")" <<(*qr.fileVec)[num-1] <<std::endl;
    }
    return os;
}


/*
Define a function that uses Class'TextQuery':
    when we design a class, it can be helpful to write programs using the class before actually implementing the members. That way, we can see whether the class has the operations we need.
*/
void runQueriesAndPrint(std::ifstream& infile){
    //construct 'TextQuery' object with an 'ifstream', 'tq' read the file into its 'vector' and build the query map. 
    TextQuery tq(infile);

    //iterate with the user: prompt for a word to find and print results:
    while(true){
        std::cout<< "enter word to look for, or \"q\" to quit: ";
        std::string s;

        //Stop if hit 'end_of_file' on the input, or if a 'q' is entered:
        if(!(std::cin>>s) || s == "q") break;

        //Run the query and print the results:
        print(std::cout, tq.query(s))<<std::endl;
    }
}

int main(){
    std::ifstream file("D:\\cpp_program\\20230505TextQueryProgram_C++PrimerP484\\test.txt");

    runQueriesAndPrint(file);

    return 0;
}

