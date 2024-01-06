

/* 
    Solution by Rahul Surana
    
    ***********************************************************


You are given an array nums that consists of non-negative integers. 
Let us define rev(x) as the reverse of the non-negative integer x. 
For example, rev(123) = 321, and rev(120) = 21. 
A pair of indices (i, j) is nice if it satisfies all of the following conditions:

0 <= i < j < nums.length
nums[i] + rev(nums[j]) == nums[j] + rev(nums[i])

Return the number of nice pairs of indices. Since that number can be too large, return it modulo 109 + 7.


    ***********************************************************
*/

class Solution {
public:

    int rev(int a){
        int n = a, ans= 0;
        while(n > 0){
            ans *= 10;
            ans += n%10;
            n/=10;
        }
        return ans;
    }

    int countNicePairs(vector<int>& nums) {
        for(int i = 0; i < nums.size(); i++){
            nums[i] -= rev(nums[i]);
        }
        int ans = 0;
        unordered_map<int,int> f;
        for(auto x: nums){
            ans = (ans + f[x])%1000000007;
            f[x]++;
        }
        return ans%(1000000007);
    }
};