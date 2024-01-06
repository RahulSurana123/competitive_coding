

/* 
    Solution by Rahul Surana
    
    ***********************************************************


You are the manager of a basketball team. For the upcoming tournament, 
you want to choose the team with the highest overall score. 
The score of the team is the sum of scores of all the players in the team.

However, the basketball team is not allowed to have conflicts. 
A conflict exists if a younger player has a strictly higher score than an older player. 
A conflict does not occur between players of the same age.

Given two lists, scores and ages, where each scores[i] and ages[i] represents the score and age of the ith player, 
respectively, return the highest overall score of all possible basketball teams.



    ***********************************************************
*/


#include <bits/stdc++.h>

class Solution {
public:

    vector<vector<int>> dp;

    int df(int i, int ma, vector<vector<int>>& t){
        if(i == t.size()){
            return 0;
        }
        if(dp[i][ma] != -1) return dp[i][ma];
        // cout << i <<" "<<ma <<"\n";
        if(t[i][1]>=ma){
            dp[i][ma] = max(dp[i][ma] ,t[i][0]+ df(i+1,t[i][1],t));
            return dp[i][ma] = max(dp[i][ma] ,df(i+1,ma,t));
        }
        return dp[i][ma] = max(dp[i][ma],df(i+1,ma,t));
    }

    int bestTeamScore(vector<int>& scores, vector<int>& ages) {
        vector<vector<int>> ind;
        int m= 0;
        for(int i = 0; i < ages.size(); i++) {
            ind.push_back({scores[i],ages[i]});
            m = max(m,ages[i]);
        }
        dp.resize(ages.size(),vector<int>(m+1,-1));
        sort(ind.begin(),ind.end());
        return df(0,0,ind);
    }
};