
/*


Solution By Rahul Surana


***********************************


There is a group of n members, and a list of various crimes they could commit. 
The ith crime generates a profit[i] and requires group[i] members to participate in it. 
If a member participates in one crime, that member can't participate in another crime.

Let's call a profitable scheme any subset of these crimes that generates at least minProfit profit, 
and the total number of members participating in that subset of crimes is at most n.

Return the number of schemes that can be chosen. Since the answer may be very large, return it modulo 109 + 7.


*************************************/



#include<bits/stdc++.h>
class Solution {
public:
    
    int mod = 1e9+7;
    
    vector<vector<vector<int>>> dp; 
    
    int df(int i,int c, int cp, int &n, int &mp, vector<int>& group, vector<int>& profit){
        if(i >= group.size()) return cp>= mp;
        if(dp[i][c][cp] != -1) return dp[i][c][cp];
        int ans = df(i+1,c,cp,n,mp,group,profit);
        if(c+group[i] <= n) ans+= df(i+1,c+group[i],min(mp,cp+profit[i]),n,mp, group,profit);
        return dp[i][c][cp] = ans%(mod);
    }
    
    int profitableSchemes(int n, int minProfit, vector<int>& group, vector<int>& profit) {
        dp.resize(group.size(),vector<vector<int>>(n+1, vector<int>(minProfit+1,-1)));
        return df(0,0,0,n,minProfit,group,profit);
    }
};