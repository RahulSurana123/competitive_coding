



/* 
    Solution by Rahul Surana
    
    ***********************************************************


Given an integer array nums, return all the different possible non-decreasing subsequences 
of the given array with at least two elements. 

You may return the answer in any order.

    ***********************************************************
*/



#include <bits/stdc++.h>

class Solution {
public:
    vector<vector<int>> ans;

    void df(int x, vector<int> &nums, vector<int> &path){
        if(x >= nums.size()){ if(path.size()>1)
            ans.push_back(path);
            return; 
        }
        if(path.empty() || nums[x] >= path.back()){ 
            path.push_back(nums[x]); 
            df(x+1,nums,path); 
            path.pop_back();
        }
        if(path.empty() || path.back()!=nums[x]) df(x+1,nums,path);
    }

    vector<vector<int>> findSubsequences(vector<int>& nums) {
        vector<int> q;
        df(0,nums,q);
        return ans;
    }
};