

/* 

    Solution by Rahul Surana
    
    ***********************************************************


You are given an array nums of n positive integers.

You can perform two types of operations on any element of the array any number of times:

If the element is even, divide it by 2.
For example, if the array is [1,2,3,4], then you can do this operation on the last element, and the array will be [1,2,3,2].
If the element is odd, multiply it by 2.
For example, if the array is [1,2,3,4], then you can do this operation on the first element, and the array will be [2,2,3,4].
The deviation of the array is the maximum difference between any two elements in the array.

Return the minimum deviation the array can have after performing some number of operations.



    ***********************************************************
*/


#include <bits/stdc++.h>

class Solution {
public:
    int minimumDeviation(vector<int>& nums) {
        set<int> s;
        for(int i = 0 ; i < nums.size(); i++){
            
            if(nums[i] % 2 == 1){ nums[i]*=2; }
            s.insert(nums[i]);
        }
        int ans = *s.rbegin() - *s.begin();
        while(*s.rbegin()%2 == 0){
            s.insert(*s.rbegin()/2);
            s.erase(*s.rbegin());
            ans = min(ans,*s.rbegin() - *s.begin());
        }
        return ans;
    }
};