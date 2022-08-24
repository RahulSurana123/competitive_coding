

/* 
    Solution by Rahul Surana
    
    ***********************************************************


On an infinite plane, a robot initially stands at (0, 0) and faces north. The robot can receive one of three instructions:

"G": go straight 1 unit;
"L": turn 90 degrees to the left;
"R": turn 90 degrees to the right.
The robot performs the instructions given in order, and repeats them forever.

Return true if and only if there exists a circle in the plane such that the robot never leaves the circle.



    ***********************************************************
*/


#include <bits/stdc++.h>


class Solution {
public:
    bool isRobotBounded(string in) {
        int x = 0,y = 0,c=0;
        vector<vector<int>>dir = {{0,1},{-1,0},{0,-1},{1,0}}; 
        for(int i = 0; i < in.length(); i++){
            if(in[i] == 'L') c++;
            else if(in[i] == 'R') c--;
            else { 
                x+= dir[c][0]; 
                y+=dir[c][1]; 
            }
            if(c > 3) c-=4;
            if(c<0) c+=4;
        }
        if((x==0 && y==0) || c) return true;
        return false;
    }
};