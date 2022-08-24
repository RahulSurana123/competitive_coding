/* 
    Solution by Rahul Surana
    
    ***********************************************************


You are given two lists of closed intervals, firstList and secondList, where firstList[i] = [starti, endi] and secondList[j] = [startj, endj]. 
Each list of intervals is pairwise disjoint and in sorted order.

Return the intersection of these two interval lists.

A closed interval [a, b] (with a <= b) denotes the set of real numbers x with a <= x <= b.

The intersection of two closed intervals is a set of real numbers that are either empty or represented as a closed interval. 
For example, the intersection of [1, 3] and [2, 4] is [2, 3].


    ***********************************************************
*/



#include <bits/stdc++.h>

class Solution {
public:
    vector<vector<int>> intervalIntersection(vector<vector<int>>& firstList, vector<vector<int>>& secondList) {
        int i = 0, j = 0, n = firstList.size(), m = secondList.size();
        vector<vector<int>> ans;
        while(i < n && j < m){
            // cout << firstList[i][0]<<" "<<firstList[i][1]<<" " << secondList[j][0]<<" "<<secondList[j][1]<<"\n";
            if((firstList[i][1] >= secondList[j][0] && firstList[i][0] <= secondList[j][0]) || 
               (firstList[i][1] >= secondList[j][1] && firstList[i][0] <= secondList[j][1]) || 
               (firstList[i][0] <= secondList[j][1] && firstList[i][0] >= secondList[j][0]) || 
               (firstList[i][1] <= secondList[j][1] && firstList[i][1] >= secondList[j][0])){
                int x = max(firstList[i][0] , secondList[j][0]);
                int y = min(firstList[i][1],secondList[j][1]);
                ans.push_back({x,y});
                if(secondList[j][1] == y) j++;
                if(firstList[i][1] == y) i++;
            }
            else{
                if(firstList[i][1] < secondList[j][0]) i++;
                if( i < n && firstList[i][0] > secondList[j][1]) j++;
            }
            
        }
        return ans;
    }
};