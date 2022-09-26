

/* 
    Solution by Rahul Surana
    
    ***********************************************************


You are given an integer array nums and an array queries where queries[i] = [vali, indexi].

For each query i, first, apply nums[indexi] = nums[indexi] + vali, then print the sum of the even values of nums.

Return an integer array answer where answer[i] is the answer to the ith query.



    ***********************************************************
*/


class Solution {
public:
    vector<int> sumEvenAfterQueries(vector<int>& nums, vector<vector<int>>& queries) {
        int s = 0;
        for(int i = 0; i < nums.size(); i++){
            s += (nums[i]&1) ? 0:nums[i];
        }
        vector<int> ans;
        for(int i = 0 ; i < queries.size(); i++){
            if(!((nums[queries[i][1]] + queries[i][0])&1)){
                s += (nums[queries[i][1]] &1)?  (nums[queries[i][1]] + queries[i][0]) : queries[i][0];
                nums[queries[i][1]] = (nums[queries[i][1]] + queries[i][0]);
            }
            else{
                s -= (nums[queries[i][1]] &1)?  0 : (nums[queries[i][1]]);
                 nums[queries[i][1]] = (nums[queries[i][1]] + queries[i][0]);
            }
            ans.push_back(s);
        }
        return ans;
    }
};