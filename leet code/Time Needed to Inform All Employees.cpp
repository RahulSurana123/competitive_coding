

/* 
    Solution by Rahul Surana
    
    ***********************************************************


A company has n employees with a unique ID for each employee from 0 to n - 1. 
The head of the company is the one with headID.

Each employee has one direct manager given in the manager array where manager[i] is the direct manager of the i-th employee, manager[headID] = -1. 
Also, it is guaranteed that the subordination relationships have a tree structure.

The head of the company wants to inform all the company employees of an urgent piece of news. 
He will inform his direct subordinates, and they will inform their subordinates, 
and so on until all employees know about the urgent news.

The i-th employee needs informTime[i] minutes to inform all of his direct subordinates 
(i.e., After informTime[i] minutes, all his direct subordinates can start spreading the news).

Return the number of minutes needed to inform all the employees about the urgent news.


    ***********************************************************
*/



#include <bits/stdc++.h>

class Solution {
public:
    vector<int> dp;
    
    int df(int i, vector<int>& m, vector<int>& it){
        if(m[i] == -1) return it[i];
        if(dp[i] != -1) return dp[i];
        return dp[i] = df(m[i],m,it) + it[i];
    }
    
    int numOfMinutes(int n, int headID, vector<int>& manager, vector<int>& informTime) {
        dp.resize(n,-1);
        int ans = 0;
        for(int i = 0; i < n; i++){
            ans = max(ans,df(i,manager, informTime));
        }
        return ans;
    }
};