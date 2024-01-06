

/* 
    Solution by Rahul Surana
    
    ***********************************************************


You are given a 0-indexed integer array tasks, where tasks[i] represents the difficulty level of a task. 
In each round, you can complete either 2 or 3 tasks of the same difficulty level.

Return the minimum rounds required to complete all the tasks, or -1 if it is not possible to complete all the tasks.



    ***********************************************************
*/


#include <bits/stdc++.h>


class Solution {
public:
    int minimumRounds(vector<int>& tasks) {
        int mr = 0;
        unordered_map<int,int> tc;
        for(auto x: tasks){
            tc[x]++;
        }
        for(auto x: tc){
            if(x.second == 1) return -1;
            mr += ceil((double)x.second/3);
        }
        return mr;
    }
};