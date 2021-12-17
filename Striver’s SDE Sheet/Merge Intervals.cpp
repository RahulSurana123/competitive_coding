

/* 

    Solution by Rahul Surana
    

    ***********************************************************


Given an array of intervals where intervals[i] = [starti, endi], merge all overlapping intervals, 
and return an array of the non-overlapping intervals that cover all the intervals in the input.

        

    ***********************************************************
*/



#include <bits/stdc++.h>
class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end());
        //    This was custom sorting logic which is not needed
        //     
        //     [=](auto a, auto b){
        //     if(a[0]==b[0]) 
        //         return a[1]<b[1]; 
        //     return a[0]<b[0]; });
        vector<vector<int>> ans;
        ans.push_back(intervals[0]);
        for(int i = 1; i < intervals.size();i++){
            if(ans[ans.size()-1][1] >= intervals[i][0]) 
                ans[ans.size()-1][1] = max(intervals[i][1],ans[ans.size()-1][1]) ;
            else 
                ans.push_back(intervals[i]);
        }
        return ans;
    }
};