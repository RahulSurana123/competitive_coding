

/* 
    Solution by Rahul Surana
    
    ***********************************************************


You are given an array coordinates, coordinates[i] = [x, y], where [x, y] represents the coordinate of a point. 
Check if these points make a straight line in the XY plane.


    ***********************************************************
*/



#include <bits/stdc++.h>

class Solution {
public:

double slope(int &x1, int &y1, int &x2, int &y2)
{
    if (x2 - x1 != 0)
        return ((double)y2 - y1) / (x2 - x1);
    return 1e9;
}

    bool checkStraightLine(vector<vector<int>>& coo) {
        if(coo.size()<=2) return true;
        double sl = slope(coo[0][0],coo[0][1],coo[1][0],coo[1][1]);
        for(int i = 1; i < coo.size(); i++){
            double s=slope(coo[0][0],coo[0][1],coo[i][0],coo[i][1]);
            // cout << s <<" "<<sl<<" "<< coo[i][0] <<" "<< coo[i][1] <<"\n";
            if(s != sl) return false; 
        }
        return true;
    }
};