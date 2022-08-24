

/* 
    Solution by Rahul Surana
    
    ***********************************************************


You are given a 0-indexed integer array nums. Rearrange the values of nums according to the following rules:

Sort the values at odd indices of nums in non-increasing order.
For example, if nums = [4,1,2,3] before this step, it becomes [4,3,2,1] after. The values at odd indices 1 and 3 are sorted in non-increasing order.
Sort the values at even indices of nums in non-decreasing order.
For example, if nums = [4,1,2,3] before this step, it becomes [2,1,4,3] after. The values at even indices 0 and 2 are sorted in non-decreasing order.
Return the array formed after rearranging the values of nums.



    ***********************************************************
*/


#include <bits/stdc++.h>

class Solution {
public:
    vector<int> sortEvenOdd(vector<int>& nums) {
        vector<int> even,odd;
        for(int i = 0 ; i < nums.size(); i++){
            if(i%2){
                odd.push_back(nums[i]);
            }
            else even.push_back(nums[i]);
        }
        sort(odd.begin(),odd.end(),greater<int>());
        sort(even.begin(),even.end());
        vector<int> ans;
        int i = 0,j=0,k=0;
        while(ans.size()<nums.size()){
            ans.push_back(even[j++]);
            if(ans.size()==nums.size()) break;
            ans.push_back(odd[k++]);
        }
        return ans;
    }
};