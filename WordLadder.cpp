//used reference http://www.cplusplus.com/reference/list/list/
//used reference http://www.cplusplus.com/reference/stack/stack/
//used reference http://www.cplusplus.com/reference/queue/queue/
//main.cpp provided by Prof Miller/Prof La Pendu
#include "WordLadder.h"
#include <iostream>
#include <fstream>
#include <list>
#include <stack>
#include <queue>

using namespace std;

WordLadder::WordLadder(const string &fileName){ //constructor with file name
    ifstream inputs;
    inputs.open(fileName);
    if (!inputs.is_open()){
        cout << "The file failed to open." << endl;
        return;
    }
    string word;
    while (inputs>>word){
         if (word.size()!=5){
            cout << "Not all words in file are 5 characters long." << endl;
        }
        dict.push_back(word);
    }
    inputs.close(); //close the file
}

bool WordLadder::ladderWord(const string word, const string inDict){
    int offCount = 0;
    for (unsigned i = 0; i<5; i++){
        if (word.at(i) != inDict.at(i)){
            offCount++;
        }
    }
    if (offCount != 1){
    }
    return (offCount==1);
}

void WordLadder::toFile(stack<string> stack1, ofstream &output){
    vector <string> wordLad;
    int counter = 0;
    while (!stack1.empty()){
      wordLad.push_back(stack1.top());
      stack1.pop();
        counter++;
    }
    if (output.is_open()){
    while(counter!=0){
        counter--;
        output << wordLad.at(counter) << " ";
     }
    }
}

bool WordLadder::StartEndInDict(const string& start, const string& end){ //just to check if the inputted start/end words are in the dictionary
    bool startInLadder=false;
    bool endInLadder=false;
    for (list<string>::iterator print = dict.begin(); print!=dict.end(); ++print){
        if (start==*print){
            startInLadder = true;
        }
        if (*print==end){
            endInLadder = true;
        }
    }
    if (!startInLadder || !endInLadder){
        cout << "the 2 words are not in the dictionary" << endl;
        return false;
    }
    else{
        return true;
    }
}

void WordLadder::outputLadder(const string &start, const string &end, const string &outputFile){
    ofstream output;
    output.open(outputFile);
    if (!output.is_open()){
        cout << "failed to open output file." << endl;
        return;
    }
    string curr;
    stack<string>stack1;
    queue<stack<string>> que;
    list<string>::iterator print;
    stack1.push(start);
    que.push(stack1);
    if (!StartEndInDict(start,end)){ //if the two user inputted words are not in the dicitonary return.
        return;
    }
    //need to do same start/end:
    if (start==end){
        output << start;
        return;
    }
    dict.remove(start); //remove the user inputted 'start' word from the dictionary
        while (!que.empty()){
            curr = que.front().top(); //curr is word from the top of the queue of stacks.
            for (print = dict.begin(); print!=dict.end(); ++print){ //iterator through the whole dicitonary list.
                if (ladderWord(curr,*print)){ //if the current word is a word in the ladder
                    if (*print==end){ //is &end word
                        que.front().push(end); //to the first stack end
                        toFile(que.front(), output);
                        return; //finsihed when this word is the end owrd.
                    }
                    //if the current word is not the 'end' word
                    stack1 = que.front();
                    stack1.push(*print);
                    que.push(stack1);
                    dict.erase(print); //takes out the word from ladder
                    print--;
                    }
                            
                }    
            que.pop();
        }
        //should return before this, otherwise there is nothing in the ladder.   
            output << "No Word Ladder Found." ;
            output.close(); //close file

}
