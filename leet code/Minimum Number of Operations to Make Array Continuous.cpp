

/* 
    Solution by Rahul Surana
    
    ***********************************************************

You are given an integer array nums. In one operation, you can replace any element in nums with any integer.

nums is considered continuous if both of the following conditions are fulfilled:

All elements in nums are unique.
The difference between the maximum element and the minimum element in nums equals nums.length - 1.
For example, nums = [4, 2, 5, 3] is continuous, but nums = [1, 2, 3, 5, 6] is not continuous.

Return the minimum number of operations to make nums continuous.


    ***********************************************************
*/


class Solution {
public:
    int minOperations(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(),nums.end());
        int i = 0, j = 0, ans = 1e9;
        int d = 0;
        while(i < n && j < n){
            int le = nums[j];
            while(j+1 < n && nums[j+1] < nums[i] + n) { if(nums[j+1] == le) d++; le = nums[j+1]; j++;  }
            ans = min(ans, n - j + i - 1 + d);
            // cout << ans << " " << i << " " << j << "\n";
            i++;
            while( i < n && nums[i] == nums[i-1]) { i++; d--; }
        }
        return ans;
    }
};