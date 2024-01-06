

/* 
    Solution by Rahul Surana
    
    ***********************************************************


Given n points on a 2D plane where points[i] = [xi, yi], Return the widest vertical area between two points 
such that no points are inside the area.

A vertical area is an area of fixed-width extending infinitely along the y-axis (i.e., infinite height). 
The widest vertical area is the one with the maximum width.

Note that points on the edge of a vertical area are not considered included in the area.


    ***********************************************************
*/

class Solution {
public:
    int maxWidthOfVerticalArea(vector<vector<int>>& points) {
        sort(points.begin(),points.end(),[](auto &a,auto &b){return a[0]<b[0];});
        int n = points.size(), ans = 0; 
        for(int i = 1; i < n; i++){
            ans = max(ans, points[i][0] - points[i-1][0]);
        }
        return ans;
    }
};