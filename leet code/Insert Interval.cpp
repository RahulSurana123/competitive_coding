



/* 
    Solution by Rahul Surana
    
    ***********************************************************


You are given an array of non-overlapping intervals intervals where intervals[i] = [starti, endi] represent 
the start and the end of the ith interval and intervals is sorted in ascending order by starti. 
You are also given an interval newInterval = [start, end] that represents the start and end of another interval.

Insert newInterval into intervals such that intervals is still sorted in ascending order by starti and intervals 
still does not have any overlapping intervals (merge overlapping intervals if necessary).

Return intervals after the insertion.
 

    ***********************************************************
*/



#include <bits/stdc++.h>

class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        int i = 0,j;
        if(intervals.size() == 0){
            return {newInterval};
        }
        while( i < intervals.size() && intervals[i][0] <= newInterval[0]) i++;
        if(i == intervals.size()) {
            if(newInterval[0] > intervals[i-1][1])
            intervals.push_back(newInterval);
            else{
                intervals[i-1][1] = max(intervals[i-1][1], newInterval[1]);
            }
            return intervals;
        }
        else if(i == 0) {
            if(newInterval[1] < intervals[i][0]) intervals.insert(intervals.begin(),newInterval);
            else if(newInterval[1] <= intervals[i][1]){
                intervals[i][0] = min(intervals[i][0], newInterval[0]);
            }
            else{
                j=0;
                 while(j < intervals.size() && intervals[j][0] <= newInterval[1]) j++;
                 intervals[i][0] = min(intervals[i][0], newInterval[0]);
                    intervals[i][1] = max(intervals[j-1][1], newInterval[1]);
                    intervals.erase(intervals.begin()+i+1,intervals.begin()+j);
                    return intervals;
            }

            return intervals;
        }
        else{
            if(newInterval[0] <= intervals[i-1][1]){
                j = i-1;
                while(j < intervals.size() && intervals[j][0] <= newInterval[1]) j++;
                    if(j == i-1){
                        intervals[i-1][1] = max(intervals[j][1], newInterval[1]);
                        return intervals;
                    }
                    else if(j == intervals.size()){
                        intervals[i-1][1] = max(intervals[j-1][1], newInterval[1]);
                        return vector<vector<int>>(intervals.begin(),intervals.begin()+i);
                    }
                    intervals[i-1][1] = max(intervals[j-1][1], newInterval[1]);
                    if(i != j-1)
                    intervals.erase(intervals.begin()+i,intervals.begin()+j);
                    else{
                        intervals.erase(intervals.begin()+i);
                    }
                    return intervals;
            }
            else{
                j = i;
                while(j < intervals.size() && intervals[j][0] <= newInterval[1]) j++;
                cout << i <<" " << j<<"\n";
                {
                    if(j == i){
                        intervals.insert(intervals.begin()+i,newInterval);
                        return intervals;
                    }
                    else if(j == intervals.size()){
                        intervals.insert(intervals.begin()+i,newInterval);
                        intervals[i][1] = max(intervals[j][1], newInterval[1]);
                        return vector<vector<int>>(intervals.begin(),intervals.begin()+i+1);
                    }
                     cout << i <<" " << j<<"\n";
                    intervals.insert(intervals.begin()+i,newInterval);
                    intervals[i][1] = max(intervals[j][1], newInterval[1]);
                    intervals.erase(intervals.begin()+i+1,intervals.begin()+j+1);
                    return intervals;
                }
            }

        }
    }
};