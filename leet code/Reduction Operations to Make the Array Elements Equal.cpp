

/* 
    Solution by Rahul Surana
    
    ***********************************************************


Given an integer array nums, your goal is to make all elements in nums equal. 
To complete one operation, follow these steps:

1. Find the largest value in nums. Let its index be i (0-indexed) and its value be largest. 
If there are multiple elements with the largest value, pick the smallest i.

2. Find the next largest value in nums strictly smaller than largest. Let its value be nextLargest.

3. Reduce nums[i] to nextLargest.

Return the number of operations to make all elements in nums equal.


    ***********************************************************
*/

class Solution {
public:
    int reductionOperations(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int u = 1, c = 1;
        int ans = 0;
        int i = 0;
        while(i+1 < nums.size() && nums[i]==nums[i+1]) i++;
        i++;
        for(;i+1 < nums.size();i++){
            while(i+1 < nums.size() &&  nums[i]==nums[i+1]) { c++; i++; }
            ans += (u*c);
            c = 1;
            u++;
        }
        if(i != nums.size())
        ans+= c*u;
        return ans;
    }
};