

/* 
    Solution by Rahul Surana
    
    ***********************************************************


Given an integer array nums, return true if there exists a triple of indices (i, j, k) such that i < j < k and nums[i] < nums[j] < nums[k]. 
If no such indices exists, return false.



    ***********************************************************
*/

#pragma GCC optimize("Ofast")
class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        int a = INT_MAX, b= INT_MAX;
        
        for(int &i : nums){
            if(a >= i) a = i;
            else if(b >= i) b = i;
            else return true;
        }
        return false;
    }
};