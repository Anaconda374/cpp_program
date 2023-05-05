#include<iostream>
#include<vector>
#include<map>
#include<set>

/*
The TextQuery Program will let a user search a given file for "a word" that might occur in it. And the result of a query should contains:
        1. The number of time the target word occurs;
        2. A list of lines(marked by its line number) on which that word appears. If a word occurs more than once on the same line.  
*/

/*
Data structures used in the Class 'TextQuery':
    1. vector<string>: store a copy of the entire input file, each line in the input file will be an element in this vector.
    2. istringstream: break each line into words.
    3. set<int>: "each set" to hold the line numbers on which "each word" in the input appears?

    4. map<string, set<int>>: associate "each word" with "the set" of line numbers on which the word appears.
*
    So the work of query operation is pretty simple: It will look inside its 'map' to see whether the give word is present.
*/


class TextQuery{



};