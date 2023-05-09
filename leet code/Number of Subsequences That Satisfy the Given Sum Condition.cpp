

/* 

    Solution by Rahul Surana
    
    ***********************************************************

You are given an array of integers nums and an integer target.

Return the number of non-empty subsequences of nums such that the sum 
of the minimum and maximum element on it is less or equal to target. 
Since the answer may be too large, return it modulo 109 + 7.


    ***********************************************************
*/


#include <bits/stdc++.h>

#define MOD 1000000007

class Solution {
public:
   
    int numSubseq(vector<int>& nums, int target) {
        vector<int> p(nums.size(),1);
        for(int i = 1; i <nums.size(); i++){ 
            p[i] = (p[i-1]<<1);
            if(p[i]>MOD) p[i]-=MOD;
        }
        sort(nums.begin(),nums.end());
        
        int ans  = 0;
        int j = nums.size()-1, i = 0;
        while(i<=j){
            // int a = bs(target-nums[i]);
            if(nums[i]+nums[j]<=target){
            ans = (ans%MOD + (p[j-i])%MOD)%MOD;
            // cout << i <<" "<<ans <<" "<<a<<"\n";
            i++; }
            else j--;
        }
        return ans;

    }
};