

/* 
    Solution by Rahul Surana
    
    ***********************************************************


Given an integer array of size n, find all elements that appear more than ⌊ n/3 ⌋ times.
 


    ***********************************************************
*/


class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<int> ans;
        int n = nums.size();
        int t = n/3;
        for(int i = 0; i < n-t; i++){
            if(i+t < n && nums[i] == nums[i+t]) {
                if(ans.size() == 0 || ans.back() != nums[i]) 
                ans.push_back(nums[i]);
                i+=t;
            }
        }
        return ans;
    }
};