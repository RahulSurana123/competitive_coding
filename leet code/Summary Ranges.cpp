

/* 
    Solution by Rahul Surana
    
    ***********************************************************


You are given a sorted unique integer array nums.

Return the smallest sorted list of ranges that cover all the numbers in the array exactly. 
That is, each element of nums is covered by exactly one of the ranges, 
and there is no integer x such that x is in one of the ranges but not in nums.

Each range [a,b] in the list should be output as:

"a->b" if a != b
"a" if a == b



    ***********************************************************
*/


#include <bits/stdc++.h>


class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        int i = 0;
        vector<string> ans;
        while(i<nums.size()){
            int start = nums[i];
            int end = 0;
            while(i+1<nums.size() && nums[i]+1 == nums[i+1]) i++;
            end = nums[i];
            i++;
            if(end == start) ans.push_back(to_string(start));
            else ans.push_back(to_string(start) + "->" + to_string(end));
        }
        return ans;
    }
};