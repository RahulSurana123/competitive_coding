

/* 

    Solution by Rahul Surana
    
    ***********************************************************

Given a collection of candidate numbers (candidates) and a target number (target), 
find all unique combinations in candidates where the candidate numbers sum to target.

Each number in candidates may only be used once in the combination.

Note: The solution set must not contain duplicate combinations.


    ***********************************************************
*/


#include <bits/stdc++.h>

class Solution {
public:
    set<vector<int>> ans;

    void df(int i, int target,vector<int>& candidates, vector<int> a){
        if(target < 0) return;
        if(target == 0) {
            ans.insert(a);
            return;
        }
        for(int j = i; j < candidates.size(); j++){
            if(j > i && candidates[j] == candidates[j-1]) continue;
            if(target - candidates[j] >= 0){
                a.push_back(candidates[j]);
                df(j+1,target-candidates[j], candidates,a);
                a.pop_back();
            }
            else break;
        }
    }

    vector<vector<int>> combinationSum2(vector<int>& c, int target) {
        sort(c.begin(),c.end());
        vector<int> a;
        df(0,target, c, a);
        return vector<vector<int>>(ans.begin(), ans.end());
    }
};