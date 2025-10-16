


/* 

    Solution by Rahul Surana
    

    ***********************************************************


You are given a 0-indexed integer array nums and an integer value.

In one operation, you can add or subtract value from any element of nums.

For example, if nums = [1,2,3] and value = 2, you can choose to subtract value from nums[0] to make nums = [-1,2,3].
The MEX (minimum excluded) of an array is the smallest missing non-negative integer in it.

For example, the MEX of [-1,2,3] is 0 while the MEX of [1,0,3] is 2.
Return the maximum MEX of nums after applying the mentioned operation any number of times.

        

    ***********************************************************
*/



#include <bits/stdc++.h>

class Solution {
public:
    int findSmallestInteger(vector<int>& nums, int val) {
        map<int,int> mp;
        for(int i = 0; i < nums.size(); i++){
            mp[((nums[i] % val) + val) %val]++;
        }
        for(int i = 0; i < 1e5; i++){
            if(mp[(i%val)]){
                mp[i%val]--;
            }
            else return i;
        }
        return 1e5;
    }
};