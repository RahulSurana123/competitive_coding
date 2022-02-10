

/* 
    Solution by Rahul Surana
    
    ***********************************************************


Given an array of integers nums and an integer k, return the total number of continuous subarrays whose sum equals to k.

 


    ***********************************************************
*/


class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int,int> m;
        vector<int> pre(nums.size()+1,0);
        pre[1] = nums[0];
        for(int i = 1; i < nums.size(); i++){
            pre[i+1] = nums[i] + pre[i];
        }
        int ans = 0;
        for(int i = 1; i <= nums.size(); i++){
            if(pre[i] == k) ans++;
            if(m.find(pre[i]-k) != m.end()){
                ans+= m[pre[i]-k];
            }
            m[pre[i]] += 1;
        }
        return ans;
    }
};