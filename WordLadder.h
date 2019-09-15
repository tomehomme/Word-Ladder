//used reference http://www.cplusplus.com/reference/list/list/
//used reference http://www.cplusplus.com/reference/stack/stack/
//used reference http://www.cplusplus.com/reference/queue/queue/
//main.cpp provided by Prof Miller/Prof La Pendu
#ifndef PROGRAM1_WORDLADDER_H
#define PROGRAM1_WORDLADDER_H
#include <iostream>
#include <fstream>
#include <list>
#include <stack>
#include <queue>
using namespace std;

class WordLadder {

private:
    list<string> dict;        //list of possible words in ladder
    bool ladderWord (const string, const string);
    void toFile(stack<string> stack1, ofstream &output);
    bool StartEndInDict(const string& start, const string& end);
public:
    WordLadder(const string &);
    void outputLadder(const string &start, const string &end, const string &outputFile);
};



#endif
