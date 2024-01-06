

/* 

    Solution by Rahul Surana
    
    ***********************************************************

Given an array of intervals intervals where intervals[i] = [starti, endi], 
return the minimum number of intervals you need to remove to make the rest of the intervals non-overlapping.


    ***********************************************************
*/


class Solution {
public:
    
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        
        if(intervals.size()==0) return 0;
        sort(intervals.begin(),intervals.end(),[&](auto &a, auto &b){ return a[1]<b[1]; });
        int k = -1e9, ans = 0;
        for(auto a: intervals){
            int x = a[0], y = a[1];
            if(x>=k){
                k = y;
            }
            else ans++;
        }
        return ans;
    }
};