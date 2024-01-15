

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
    vector<vector<int>> findWinners(vector<vector<int>>& matches) {
        map<int,int> l;
        for(auto &x : matches){ if(!l.count(x[0])) l[x[0]] = 0; l[x[1]]++;  }
        vector<vector<int>> ans(2);
        for(auto &x: l){
            // cout << x.first <<" "<<x.second<<"\n";
            if(x.second < 2) ans[x.second].push_back(x.first);
        }
        return ans;
    }
};