

/* 
    Solution by Rahul Surana
    
    ***********************************************************

You are given an integer array nums. You need to create a 2D array from nums satisfying the following conditions:

The 2D array should contain only the elements of the array nums.
Each row in the 2D array contains distinct integers.
The number of rows in the 2D array should be minimal.
Return the resulting array. If there are multiple answers, return any of them.

Note that the 2D array can have a different number of elements on each row.


    ***********************************************************
*/

class Solution {
public:
    vector<vector<int>> findMatrix(vector<int>& nums) {
        int n = nums.size(), len = 0;
        vector<int> a(n+1,0);
        for(auto x: nums){
            a[x]++;
            len = max(len,a[x]);
        }
        vector<vector<int>> ans(len);
        for(int i = 1; i < n+1; i++){
            int x = 0;
            while(a[i]>0) {ans[x++].push_back(i); a[i]--;}
        }
        return ans;
    }
};