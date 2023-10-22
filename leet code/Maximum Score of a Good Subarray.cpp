

/* 

    Solution by Rahul Surana
    
    ***********************************************************


You are given an array of integers nums (0-indexed) and an integer k.

The score of a subarray (i, j) is defined as min(nums[i], nums[i+1], ..., nums[j]) * (j - i + 1). 
A good subarray is a subarray where i <= k <= j.

Return the maximum possible score of a good subarray.


    ***********************************************************
    
*/

class Solution {
public:
    int maximumScore(vector<int>& nums, int k) {
        int ans = nums[k], mv = nums[k];
        int l = k, r = k, n = nums.size();
        while(l > 0 || r < n-1){
            if(l == 0 || nums[r+1] > nums[l-1]){
                r++;
            }  
            else l--;
            mv = min(mv,min(nums[l],nums[r]));
            ans = max(ans, mv *(r-l+1)); 
        }
        return ans;
    }
};