

/* 
    Solution by Rahul Surana
    
    ***********************************************************


Given an integer array nums, move all the even integers at the beginning of the array 
followed by all the odd integers.

Return any array that satisfies this condition.



    ***********************************************************
*/



#include <bits/stdc++.h>

class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& nums) {
        // vector<int> ans;
        // for(auto x: nums) if(x%2==0) ans.push_back(x);
        // for(auto x: nums) if(x%2==1) ans.push_back(x);
        int i = 0,j = 0;
        while(i < nums.size() && j < nums.size()){
            if(nums[i] % 2 == 1){
                i++;
            }
            else{
                swap(nums[i],nums[j]);
                j++;
                if(nums[i]%2 == 0) i++;
            }
        }
        return nums;
    }
};