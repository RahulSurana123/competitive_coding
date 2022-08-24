

/* 
    Solution by Rahul Surana
    
    ***********************************************************


Given a binary array nums, return the maximum length of a contiguous subarray with an equal number of 0 and 1.



    ***********************************************************
*/


#include <bits/stdc++.h>

class Solution {
public:
    
    int findMaxLength(vector<int>& nums) {
        int n = nums.size();
        vector<int> v((2*n)+1,-1);
        int s = 0,ans = 0;
        for(int i = 0; i < nums.size(); i++){
            s += (nums[i])?1:-1;
            if(s==0) ans = max(ans,i+1);
            if(v[s+n] != -1){
                // cout << i <<" "<<v[s+n]<<"\n";
                ans = max(ans,i-v[s+n]);
            }
            else{
                v[s+n] = i;
            }
        }
        return ans;
    }
};