

/* 

    Solution by Rahul Surana
    

    ***********************************************************


Given a set of distinct positive integers nums, return the largest subset answer such that every pair 
(answer[i], answer[j]) of elements in this subset satisfies:

answer[i] % answer[j] == 0, or
answer[j] % answer[i] == 0
If there are multiple solutions, return any of them.



    ***********************************************************
*/



#include <bits/stdc++.h>
class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<int> par(nums.size(),-1),lis(nums.size(),0);
        int ind,max;
        for(int i = 0; i < nums.size();i++){
            for(int j = i-1; j >=0;j--){
                if(lis[j]+1>lis[i] && nums[i]%nums[j]==0){
                    lis[i] = lis[j]+1;
                    par[i] = j;
                }
                if(lis[i]>max){
                    ind = i;
                    max = lis[i];
                }
            }
        }
        vector<int> ans;
        while(ind !=-1){
            ans.push_back(nums[ind]);
            ind = par[ind];
        }
        return ans;
    }
};