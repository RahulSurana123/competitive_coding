

/* 

    Solution by Rahul Surana
    
    ***********************************************************


You are keeping score for a baseball game with strange rules. The game consists of several rounds, where the scores of past rounds may affect future rounds' scores.

At the beginning of the game, you start with an empty record. You are given a list of strings ops, where ops[i] is the ith operation you must apply to the record and is one of the following:

An integer x - Record a new score of x.
"+" - Record a new score that is the sum of the previous two scores. It is guaranteed there will always be two previous scores.
"D" - Record a new score that is double the previous score. It is guaranteed there will always be a previous score.
"C" - Invalidate the previous score, removing it from the record. It is guaranteed there will always be a previous score.
Return the sum of all the scores on the record.



    ***********************************************************
*/


#include <bits/stdc++.h>

class Solution {
public:
    int calPoints(vector<string>& ops) {
        stack<int> prev;
        int score = 0;
        for(int i = 0; i < ops.size(); i++){
            if(ops[i] == "+"){
                int temp = prev.top();
                prev.pop();
                int x = temp + prev.top();
                prev.push(temp);
                prev.push(x);
            }
            else if(ops[i] == "D"){
                prev.push(2*prev.top());
            }
            else if(ops[i] == "C"){
                prev.pop();
            }
            else{
                prev.push(stoi(ops[i]));
            }
        }
        while(!prev.empty()) { score+= prev.top(); prev.pop(); }
        return score;
        
    }
};