

/* 
    Solution by Rahul Surana
    
    ***********************************************************


Given an array nums of distinct integers, return all the possible permutations. You can return the answer in any order.



    ***********************************************************
*/

class Solution {
public:

    vector<vector<int>> ans;
    void df(int k, vector<int>& nums){
        if(k == nums.size()){
            ans.push_back(nums);
        }
        for(int i = k; i < nums.size(); i++){
            swap(nums[i],nums[k]);
            df(k+1,nums);
            swap(nums[i],nums[k]);
        }
    }

    vector<vector<int>> permute(vector<int>& nums) {
        // vector<int> p;
        df(0,nums);
        return ans;
    }
};