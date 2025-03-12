
/* 
    Solution by Rahul Surana
    
    ***********************************************************


Given an array nums sorted in non-decreasing order, return the maximum between the number of positive integers and the number of negative integers.

In other words, if the number of positive integers in nums is pos and the number of negative integers is neg, then return the maximum of pos and neg.
Note that 0 is neither positive nor negative.





    ***********************************************************
*/

class Solution {
public:
    int maximumCount(vector<int>& nums) {
        int n = nums.size();
        int n_c = -1, p_c = -1, i = 0, j = n-1;
        
        while(i<=j){
            int m = (j+i)/2;
            if(nums[m] >= 0) j = m-1;
            else { n_c = m; i = m+1; }
        }
        
        i = 0, j = n-1;
        while(i<=j){
            int m = (j+i)/2;
            if(nums[m] > 0) { p_c = m; j = m-1;}
            else { i = m+1; }
        }
        
        if(n_c == -1 && p_c == -1) return 0;
        else if(n_c == -1) return n-p_c;
        else if(p_c == -1) return n_c+1;
        return max(n_c+1,n-p_c);
    }
};
