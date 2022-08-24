

/* 
    Solution by Rahul Surana
    
    ***********************************************************


You are given an integer array nums and an integer k.

In one operation, you can pick two numbers from the array whose sum equals k and remove them from the array.

Return the maximum number of operations you can perform on the array.



    ***********************************************************
*/



#include <bits/stdc++.h>

class Solution {
public:
    int maxOperations(vector<int>& nums, int k) {
        map<int,vector<int>> m;
        map<int,int> mi;
        for(int i = 0; i < nums.size(); i++){
            m[nums[i]].push_back(i);
            mi[nums[i]] = 0;
        }
        
        int c = 0;
        for(int i = 0; i < nums.size(); i++){
            if(mi[k-nums[i]] >= m[k-nums[i]].size() || mi[nums[i]] >= m[nums[i]].size()) continue;
            if(k-nums[i] == nums[i] && m[nums[i]].size() - mi[nums[i]] < 2) continue; 
            c++;
            mi[k-nums[i]]++;
            mi[nums[i]] ++;
        }
        return c;
    }
};