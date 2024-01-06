

/* 
    Solution by Rahul Surana
    
    ***********************************************************


You are given an integer array matches where matches[i] = [winneri, loseri] indicates 
that the player winneri defeated player loseri in a match.

Return a list answer of size 2 where:

answer[0] is a list of all players that have not lost any matches.
answer[1] is a list of all players that have lost exactly one match.
The values in the two lists should be returned in increasing order.

Note:

You should only consider the players that have played at least one match.
The testcases will be generated such that no two matches will have the same outcome.



    ***********************************************************
*/


#include <bits/stdc++.h>

class Solution {
public:
    
    map<int,int> p;
    map<int,int> l;
    
    vector<vector<int>> findWinners(vector<vector<int>>& matches) {
        for(auto x: matches){
            p[x[1]]++;
            p[x[0]]++;
            l[x[1]]++;
        }
        vector<vector<int>> ans(2,vector<int>());
        for(auto m:p){
            if(l[m.first]==1) ans[1].push_back(m.first);
            else if(l[m.first]==0) ans[0].push_back(m.first);
        }
        return ans;
    }
};