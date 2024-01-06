

/* 
    Solution by Rahul Surana
    
    ***********************************************************


You are given an integer array nums and an integer x. 
In one operation, you can either remove the leftmost or the rightmost element from the array nums and subtract its value from x. 
Note that this modifies the array for future operations.

Return the minimum number of operations to reduce x to exactly 0 if it is possible, otherwise, return -1.

 


    ***********************************************************
*/


class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        int n = nums.size(), t = accumulate(nums.begin(),nums.end(),0),ml = 0, cs = 0, l = 0;
        t-=x;
        // cout << t <<"\n";
        if(t < 0) return -1;
        if(t == 0) return n;
        for(int r = 0;r < n; r++){
            cs += nums[r];
            while(l < r && cs > t){
                cs -= nums[l];
                l++;
            }
            if(cs == t) ml = max(ml, r-l+1);
        }
        return ml? (n-ml):-1;
    }
};