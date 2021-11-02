

/* 
    Solution by Rahul Surana
    
    ***********************************************************


Given an integer array nums, return all the triplets [nums[i], nums[j], nums[k]] 
such that i != j, i != k, and j != k, and nums[i] + nums[j] + nums[k] == 0.

Notice that the solution set must not contain duplicate triplets.


    ***********************************************************
*/


#include <bits/stdc++.h>

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        set<vector<int>> ans;
        map<int,int> m;
        int n = nums.size();
        sort(nums.begin(),nums.end());
        if(nums.size() <=2 || nums[0] > 0 || nums[n-1] < 0) return vector<vector<int>>();
        for(int i = 0; i < n; i++){
            m[nums[i]] = i;
        }
        
        for(int i = 0; i < n-2; i++){
            while(i!=0 && i < n-1 && nums[i] == nums[i-1]) i++;
            for(int j = i+1; j < n-1; j++){
                while(j != i+1 && j < n-1 && nums[j-1] == nums[j] ) j++;
                // cout<<nums[i]<<" "<<nums[j]<<" "<<-nums[i]-nums[j]<<"\n";
                if(i < n-2 && j < n-1 && m[-nums[i]-nums[j]] > j) { 
                    ans.insert({nums[i], nums[j], -nums[i]-nums[j]}); 
                }
            }
        }
        // cout <<"\n";
        return vector<vector<int>>(ans.begin(),ans.end());
    }
};