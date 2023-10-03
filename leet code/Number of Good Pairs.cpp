

/* 
    Solution by Rahul Surana
    
    ***********************************************************


Given an array of integers nums, return the number of good pairs.

A pair (i, j) is called good if nums[i] == nums[j] and i < j.
 


    ***********************************************************
*/


class Solution {
public:
    int numIdenticalPairs(vector<int>& nums) {
        unordered_map<int,int> f;
        for(auto &x: nums) f[x]++;
        int ans = 0;
        for(auto &z: f){
            if(z.second == 0) continue;
            ans += (z.second*(z.second-1))/2;
        }
        return ans;
    }
};