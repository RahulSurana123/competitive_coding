

/* 
    Solution by Rahul Surana
    
    ***********************************************************


There are some spherical balloons taped onto a flat wall that represents the XY-plane. The balloons are represented as a 2D integer array points where points[i] = [xstart, xend] denotes a balloon whose horizontal diameter stretches between xstart and xend. You do not know the exact y-coordinates of the balloons.

Arrows can be shot up directly vertically (in the positive y-direction) from different points along the x-axis. A balloon with xstart and xend is burst by an arrow shot at x if xstart <= x <= xend. There is no limit to the number of arrows that can be shot. A shot arrow keeps traveling up infinitely, bursting any balloons in its path.

Given the array points, return the minimum number of arrows that must be shot to burst all balloons.



    ***********************************************************
*/


#include <bits/stdc++.h>


class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& p) {
        vector<pair<int,int>> x;
        sort(p.begin(),p.end());
        x.push_back({p[0][0],p[0][1]});
        for(int i = 1; i< p.size(); i++){
            if(x[x.size()-1].second >= p[i][0]){
                x[x.size()-1].first = max(x[x.size()-1].first,p[i][0]);
                x[x.size()-1].second = min(x[x.size()-1].second,p[i][1]);
            }
            else {
                x.push_back({p[i][0],p[i][1]});
            }
        }
        return x.size();
    }
};