

/* 
    Solution by Rahul Surana
    
    ***********************************************************

You are given a 0-indexed integer array nums of size n.

Define two arrays leftSum and rightSum where:

leftSum[i] is the sum of elements to the left of the index i in the array nums. If there is no such element, leftSum[i] = 0.
rightSum[i] is the sum of elements to the right of the index i in the array nums. If there is no such element, rightSum[i] = 0.
Return an integer array answer of size n where answer[i] = |leftSum[i] - rightSum[i]|.


    ***********************************************************
*/

class Solution {
public:
    vector<int> leftRightDifference(vector<int>& nums) {
        int sum = 0;
        for(auto x : nums){
            sum += x;
        } 
        vector<int> ans;
        int c = 0;
        for(auto x : nums){
            sum -= x;
            ans.push_back(abs(c-sum));
            c += x;
        }
        return ans;
    }
};
