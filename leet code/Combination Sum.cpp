

/* 

    Solution by Rahul Surana
    
    ***********************************************************


Given an array of distinct integers candidates and a target integer target, return a list of all unique combinations of candidates where the chosen numbers sum to target. You may return the combinations in any order.

The same number may be chosen from candidates an unlimited number of times. Two combinations are unique if the frequency of at least one of the chosen numbers is different.

It is guaranteed that the number of unique combinations that sum up to target is less than 150 combinations for the given input.



    ***********************************************************
*/


#include <bits/stdc++.h>

class Solution {
public:
    
    vector<vector<int>> ans;
    
    void df(int i, vector<int> &c,int target,vector<int> &a){
        cout << c[i] <<" ";
        if(target == 0) { ans.push_back(a); return; }
        while(i < c.size() && target >= c[i]) {
            a.push_back(c[i]);
            df(i,c,target-c[i],a);
            ++i;
            a.pop_back();
        }
    }
    
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        sort(candidates.begin(),candidates.end());
        candidates.erase(unique(candidates.begin(),candidates.end()),candidates.end());
        vector<int> a;
        df(0,candidates,target,a);
        return ans;
    }
};